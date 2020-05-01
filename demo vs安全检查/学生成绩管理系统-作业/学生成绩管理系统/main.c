#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SAMS.h"
int main()
{
	

	StudentList studentList;
	InitStudentList(&studentList);
	ReadFromTxt(&studentList);
	Student* currentStudent = NULL;
	while (1)
	{
	PrintSelectionInterface();
		int choice;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			AddStudentToLinkedList(&studentList);
			break;
		case 2:
			ModifyStudentInformation(&studentList);
			break;
		case 3:
			DeleteStudentInformation(&studentList);
			break;
		case 4:
			currentStudent = SearchByName(&studentList);
			if (currentStudent)
			{
				printf("\t学号\t姓名\t平时分\t实验分\t考试分\t总分\t\n");
				printf("\t%s ", currentStudent->studentNumber);
				printf("\t%s ", currentStudent->name);
				printf("\t%d ", currentStudent->usualPerformance);
				printf("\t%d ", currentStudent->experimentalGrade);
				printf("\t%d ", currentStudent->examResult);
				printf("\t%d \n", currentStudent->totalScore);
			}
			
			break;
		case 5:
			currentStudent = SearchByStudentNumber(&studentList);
			if (currentStudent)
			{
				printf("\t学号\t姓名\t平时分\t实验分\t考试分\t总分\t\n");
				printf("\t%s ", currentStudent->studentNumber);
				printf("\t%s ", currentStudent->name);
				printf("\t%d ", currentStudent->usualPerformance);
				printf("\t%d ", currentStudent->experimentalGrade);
				printf("\t%d ", currentStudent->examResult);
				printf("\t%d \n", currentStudent->totalScore);
			}
			
			break;
		case 6:
			SearchByTotalScoreFromHightToLow(&studentList);
			break;
		case 7:
			SearchClassPassRate(&studentList);
			break;
		case 8:
			PrintStudentList(&studentList);
			break;
		case 9:
			quit();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}