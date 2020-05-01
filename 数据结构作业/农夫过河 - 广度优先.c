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
}Status;	//状态为 1 表示已经过河，状态为 0 表示未过河

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
	//人不能从 A 岸到 A 岸，也不能从 B 岸到 B 岸
	if (currentStatus->farmer == nextStatus->farmer) {
		return false;
	}

	//排除已经有过的状态
	for (Status* tempStatus = currentStatus; tempStatus; tempStatus = tempStatus->lastStatus) {
		if (tempStatus->cabbage == nextStatus->cabbage && tempStatus->farmer == nextStatus->farmer &&
			tempStatus->sheep == nextStatus->sheep && tempStatus->wolf == nextStatus->wolf) {
			return false;
		}
	}

	//排除菜或羊被吃的状态
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

		printf("%s\t", tempStatus->farmer ? "左" : "右");
		printf("%s\t", tempStatus->wolf ? "左" : "右");
		printf("%s\t", tempStatus->sheep ? "左" : "右");
		printf("%s\t", tempStatus->cabbage ? "左" : "右");
		printf("\n");
	}
	printf("\n");
}

int main()
{
	//int e, n, m;
	//queue<int> q;
	//if (q.empty()) cout << "队列为空" << endl;
	//for (int i = 1; i <= 10; i++)
	//	q.push(i);
	//if (!q.empty()) cout << "队列不为空" << endl;

	queue<Status*> q;
	queue<Status*> q2;
	Status* originalState = Init();
	q.push(originalState);
	int count = 0;
	while (!q.empty()) {
		Status* head = q.front();
		q.pop();

		/** 农夫移动的八种可能 */
		Status* nextStatus[8];
		for (int i = 0; i < 8; i++) {
			nextStatus[i] = CopyStatus(head);
		}
		/** 设 A 为原岸， B 为对岸 */
		//农 A->B
		nextStatus[0]->farmer = 1;
		//狼 A->B
		nextStatus[1]->wolf = 1;
		nextStatus[1]->farmer = 1;
		//羊 A->B
		nextStatus[2]->sheep = 1;
		nextStatus[2]->farmer = 1;
		//菜 A->B
		nextStatus[3]->cabbage = 1;
		nextStatus[3]->farmer = 1;
		//农 A<-B
		nextStatus[4]->farmer = 0;
		//狼 A<-B
		nextStatus[5]->wolf = 0;
		nextStatus[5]->farmer = 0;
		//羊 A<-B
		nextStatus[6]->sheep = 0;
		nextStatus[6]->farmer = 0;
		//菜 A<-B
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