#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct status {
	int farmer;
	int wolf;
	int cabbage;
	int sheep;
	struct status* lastStatus;
}Status;	//状态为 1 表示已经过河，状态为 0 表示未过河

Status *s[20];
int count = 0;

Status *Init() {
	Status* originalState = (Status*)malloc(sizeof(Status));
	if (originalState){
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
	for (Status* tempStatus = currentStatus; tempStatus; tempStatus=tempStatus->lastStatus){
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

int FindNextStatus(Status*currentStatus) {

	//找到路径，直接返回
	if (currentStatus->cabbage * 1 + currentStatus->wolf * 2 +
		currentStatus->farmer * 4 + currentStatus->sheep * 8 == 15) {
		s[count++] = currentStatus;
		return 1;
	}

	/** 农夫移动的八种可能 */
	Status *nextStatus[8];
	for (int i = 0; i < 8; i++) {
		nextStatus[i] = CopyStatus(currentStatus);
	}
	//Status* nextStatus = CopyStatus(currentStatus);
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
		if (Movable(currentStatus, nextStatus[i])) {
			nextStatus[i]->lastStatus = currentStatus;
			if (FindNextStatus(nextStatus[i]) == 1) {
				//continue;
				return 0;
			}
			//FindNextStatus(nextStatus[i]);
		}
	}


}

void Print(Status* outcome) {
	printf("%s\t%s\t%s\t%s\t\n", "farmer", "wolf", "sheep", "cabbage");
	for (Status* tempStatus = outcome; tempStatus; tempStatus = tempStatus->lastStatus) {
		//printf("%d\t%d\t%d\t%d\t\n",
		//	tempStatus->farmer, tempStatus->wolf, tempStatus->sheep, tempStatus->cabbage);

		printf("%s\t", tempStatus->farmer ? "L" : "R");
		printf("%s\t", tempStatus->wolf ? "L" : "R");
		printf("%s\t", tempStatus->sheep ? "L" : "R");
		printf("%s\t", tempStatus->cabbage ? "L" : "R");
		printf("\n");
	}
	printf("\n");
}

int main(){
	Status *originalState = Init();
	printf("1 - Is across the river        0 - Not cross the river  \n");
	FindNextStatus(originalState);
	Print(s[0]);
	Print(s[2]);

	return 0;
}