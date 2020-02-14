#include <cstdlib>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct status {
	int farmer;
	int wolf;
	int cabbage;
	int sheep;
	struct status* lastStatus;
}Status;	//״̬Ϊ 1 ��ʾ�Ѿ����ӣ�״̬Ϊ 0 ��ʾδ����

Status* s[20];
//int count = 0;

#define first 0
#define second 7

Status* Init() {
	Status* originalState = (Status*)malloc(sizeof(Status));
	if (originalState) {
		memset(originalState, 0, sizeof(Status));
	}
	return originalState;
}

bool Movable(Status* currentStatus, Status* nextStatus) {
	//�˲��ܴ� A ���� A ����Ҳ���ܴ� B ���� B ��
	if (currentStatus->farmer == nextStatus->farmer) {
		return false;
	}

	//�ų��Ѿ��й���״̬
	for (Status* tempStatus = currentStatus; tempStatus; tempStatus = tempStatus->lastStatus) {
		if (tempStatus->cabbage == nextStatus->cabbage && tempStatus->farmer == nextStatus->farmer &&
			tempStatus->sheep == nextStatus->sheep && tempStatus->wolf == nextStatus->wolf) {
			return false;
		}
	}

	//�ų��˻��򱻳Ե�״̬
	if ((nextStatus->cabbage == nextStatus->sheep && nextStatus->cabbage != nextStatus->farmer) ||
		(nextStatus->sheep == nextStatus->wolf && nextStatus->sheep != nextStatus->farmer)) {
		return false;
	}

	//if (nextStatus->farmer != nextStatus->sheep && (nextStatus->wolf == nextStatus->sheep || nextStatus->sheep == nextStatus->cabbage)) {
	//	return false;
	//}
	return true;
}

Status* CopyStatus(Status* originalStatus) {
	Status* copy = (Status*)malloc(sizeof(Status));
	if (copy) {
		copy->cabbage = originalStatus->cabbage;
		copy->farmer = originalStatus->farmer;
		copy->lastStatus = originalStatus->lastStatus;
		copy->sheep = originalStatus->sheep;
		copy->wolf = originalStatus->wolf;
	}
	return copy;
}

void Print(Status* outcome) {
	printf("%s\t%s\t%s\t%s\t\n", "farmer", "wolf", "sheep", "cabbage");
	for (Status* tempStatus = outcome; tempStatus; tempStatus = tempStatus->lastStatus) {
		//printf("%d\t%d\t%d\t%d\t\n",
		//	tempStatus->farmer, tempStatus->wolf, tempStatus->sheep, tempStatus->cabbage);

		printf("%s\t", tempStatus->farmer ? "��" : "��");
		printf("%s\t", tempStatus->wolf ? "��" : "��");
		printf("%s\t", tempStatus->sheep ? "��" : "��");
		printf("%s\t", tempStatus->cabbage ? "��" : "��");
		printf("\n");
	}
	printf("\n");
}

int main()
{
	//int e, n, m;
	//queue<int> q;
	//if (q.empty()) cout << "����Ϊ��" << endl;
	//for (int i = 1; i <= 10; i++)
	//	q.push(i);
	//if (!q.empty()) cout << "���в�Ϊ��" << endl;

	queue<Status*> q;
	queue<Status*> q2;
	Status* originalState = Init();
	q.push(originalState);
	int count = 0;
	while (!q.empty()) {
		Status* head = q.front();
		q.pop();

		/** ũ���ƶ��İ��ֿ��� */
		Status* nextStatus[8];
		for (int i = 0; i < 8; i++) {
			nextStatus[i] = CopyStatus(head);
		}
		/** �� A Ϊԭ���� B Ϊ�԰� */
		//ũ A->B
		nextStatus[0]->farmer = 1;
		//�� A->B
		nextStatus[1]->wolf = 1;
		nextStatus[1]->farmer = 1;
		//�� A->B
		nextStatus[2]->sheep = 1;
		nextStatus[2]->farmer = 1;
		//�� A->B
		nextStatus[3]->cabbage = 1;
		nextStatus[3]->farmer = 1;
		//ũ A<-B
		nextStatus[4]->farmer = 0;
		//�� A<-B
		nextStatus[5]->wolf = 0;
		nextStatus[5]->farmer = 0;
		//�� A<-B
		nextStatus[6]->sheep = 0;
		nextStatus[6]->farmer = 0;
		//�� A<-B
		nextStatus[7]->cabbage = 0;
		nextStatus[7]->farmer = 0;

		for (int i = 0; i < 8; i++) {
			if (Movable(head, nextStatus[i])) {
				nextStatus[i]->lastStatus = head;
				q.push(nextStatus[i]);
				if (q.back()->cabbage * 1 + q.back()->wolf * 2 +
					q.back()->farmer * 4 + q.back()->sheep * 8 == 15){
					s[count++] = nextStatus[i];
				}
			}
		}
	}

	Print(s[first]);
	Print(s[second]);

}