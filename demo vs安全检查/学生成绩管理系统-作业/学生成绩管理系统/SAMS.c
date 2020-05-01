#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "SAMS.h"

/** ��ʼ��ѧ������ */
void InitStudentList(StudentList* studentList)
{
	memset(studentList, 0, sizeof(StudentList));
}

/** ��ӡѡ����� */
void PrintSelectionInterface()
{
	printf("\nѧ���ɼ�����ϵͳ\n");
	printf(" 1������ѧ����Ϣ\n");
	printf(" 2���޸�ѧ����Ϣ\n");
	printf(" 3��ɾ��ѧ����Ϣ\n");
	printf(" 4����������ѯ\n");
	printf(" 5����ѧ�Ų�ѯ\n");
	printf(" 6�����ָܷߵͲ�ѯ\n");
	printf(" 7����ѯ�༶������\n");
	printf(" 8���鿴��ǰѧ��\n");
	printf(" 9���˳�ϵͳ\n");
}

/** ���ı��ж�ȡ���ݵ������� */
void ReadFromTxt(StudentList* studentList)
{
	ClearLinkedList(studentList);
	//printf("ReadFromTxt\n");
	FILE* read_file;
	int openSucceed = fopen_s(&read_file, "student.txt", "r");		//�򿪳ɹ����� 0 
	if (read_file != NULL && openSucceed == 0)
	{
		while (0 == feof(read_file))	//0���ļ�δ��ȡ����  1���ļ��Ѷ�ȡ����
		{
			Student* newStudent = (Student*)malloc(sizeof(Student));
			if (newStudent)
			{
				memset(newStudent, 0, sizeof(Student));
				fscanf_s(read_file, "%s", newStudent->studentNumber, sizeof(newStudent->studentNumber));
				fscanf_s(read_file, "%s", newStudent->name, sizeof(newStudent->name));
				fscanf_s(read_file, "%d", &newStudent->usualPerformance);
				fscanf_s(read_file, "%d", &newStudent->experimentalGrade);
				fscanf_s(read_file, "%d", &newStudent->examResult);
				fscanf_s(read_file, "%d", &newStudent->totalScore);
				newStudent->nextStudent = (Student*)studentList->firstStudent;
				studentList->firstStudent = newStudent;
				studentList->numberOfStudents++;
			}
			fgetc(read_file);
		}
		fclose(read_file);

	}
}

/** ������� */
void ClearLinkedList(StudentList* studentList)
{
	if(studentList->firstStudent)
	{
		Student* currentStudent = studentList->firstStudent;
		Student* nextStudent = NULL;
		while (currentStudent)
		{
			nextStudent = (Student*)(currentStudent->nextStudent);
			free(currentStudent);
			currentStudent = nextStudent;
		}
		studentList->firstStudent = NULL;
		studentList->numberOfStudents = 0;
	}
}

/** ���������뵽�ı��� */
void WriteToTxt(StudentList* studentList)
{
	FILE* write_file;
	int openSucceed = fopen_s(&write_file, "student.txt", "w");		//�򿪳ɹ����� 0 
	if (write_file != NULL && openSucceed == 0)
	{
		Student* currentStudent = studentList->firstStudent;
		while (currentStudent)
		{
			fprintf(write_file, "\n%s ", currentStudent->studentNumber);
			fprintf(write_file, "%s ", currentStudent->name);
			fprintf(write_file, "%d ", currentStudent->usualPerformance);
			fprintf(write_file, "%d ", currentStudent->experimentalGrade);
			fprintf(write_file, "%d ", currentStudent->examResult);
			fprintf(write_file, "%d", currentStudent->totalScore);
			currentStudent = (Student*)currentStudent->nextStudent;
		}
		fclose(write_file);
	}
}

/** ����ѧ����� */
void AddStudentToLinkedList(StudentList* studentList)
{
	Student* newStudent = (Student*)malloc(sizeof(Student));
	if (newStudent)
	{
		printf("ѧ��ѧ�ţ�");
		scanf_s("%s", newStudent->studentNumber, sizeof(newStudent->studentNumber));
		printf("ѧ��������");
		scanf_s("%s", newStudent->name,sizeof(newStudent->name));
		printf("ѧ��ƽʱ�ɼ���");
		scanf_s("%d", &(newStudent->usualPerformance));
		printf("ѧ��ʵ��ɼ���");
		scanf_s("%d", &(newStudent->experimentalGrade));
		printf("ѧ�����Գɼ���");
		scanf_s("%d", &(newStudent->examResult));
		printf("ѧ�������ɼ���");
		scanf_s("%d", &(newStudent->totalScore));

		newStudent->nextStudent = (Student*)studentList->firstStudent;
		studentList->firstStudent = newStudent;
		studentList->numberOfStudents++;
		WriteToTxt(studentList);
	}
}

/** ��ѧ�Ų��� */
Student* SearchByStudentNumber(StudentList* studentList)
{
	char studentNumber[30] = "" ;
	scanf_s("%s", studentNumber,sizeof(studentNumber));
	Student* currentStudent = studentList->firstStudent;
	while (currentStudent)
	{
		if (0 == strcmp(studentNumber, currentStudent->studentNumber))
		{
			break;
		}
		currentStudent = currentStudent->nextStudent;
	}
	return currentStudent;
}

/** ���������� */
Student* SearchByName(StudentList* studentList)
{
	char studentNumber[30] = "";
	scanf_s("%s", studentNumber, sizeof(studentNumber));
	Student* currentStudent = studentList->firstStudent;
	while (currentStudent)
	{
		if (0 == strcmp(studentNumber, currentStudent->name))
		{
			break;
		}
		currentStudent = currentStudent->nextStudent;
	}
	return currentStudent;
}

/** �޸�ѧ����Ϣ */
void ModifyStudentInformation(StudentList* studentList)
{
		printf("��ѧ�Ų����밴1\n");
		printf("�����������밴2\n");
		int choice = 0;
		Student* currentStudent = NULL;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			currentStudent = SearchByStudentNumber(studentList);
			break;
		case 2:
			currentStudent = SearchByName(studentList);
			break;
		default:
			break;
		}
		if (currentStudent)
		{
			printf("�����ѧ��������Ϣ\n");
			printf("ѧ��ѧ�ţ�");
			scanf_s("%s", currentStudent->studentNumber, sizeof(currentStudent->studentNumber));
			printf("ѧ��������");
			scanf_s("%s", currentStudent->name, sizeof(currentStudent->name));
			printf("ѧ��ƽʱ�ɼ���");
			scanf_s("%d", &(currentStudent->usualPerformance));
			printf("ѧ��ʵ��ɼ���");
			scanf_s("%d", &(currentStudent->experimentalGrade));
			printf("ѧ�����Գɼ���");
			scanf_s("%d", &(currentStudent->examResult));
			printf("ѧ�������ɼ���");
			scanf_s("%d", &(currentStudent->totalScore));

			WriteToTxt(studentList);
		}
		else
		{
			printf("���޴���\n");
		}
		PrintStudentList(studentList);
}

/** ɾ��ѧ����� */
void DeleteStudentInformation(StudentList* studentList)
{
		printf("��ѧ�Ų����밴1\n");
		printf("�����������밴2\n");
		int choice = 0;
		Student* deletedStudent = NULL;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			deletedStudent = SearchByStudentNumber(studentList);
			break;
		case 2:
			deletedStudent = SearchByName(studentList);
			break;
		default:
			break;
		}
		if (deletedStudent)
		{
			Student* previousStudent = studentList->firstStudent;
			if (previousStudent == deletedStudent)
			{
				studentList->firstStudent = studentList->firstStudent->nextStudent;
				free(previousStudent);
			}
			else
			{
				for (;;)
				{
					if (previousStudent->nextStudent == deletedStudent)
					{
						break;
					}
					previousStudent = previousStudent->nextStudent;
				}
				previousStudent->nextStudent = deletedStudent->nextStudent;
				free(deletedStudent);
			}
			studentList->numberOfStudents--;
			WriteToTxt(studentList);
			printf("ɾ���ɹ���\n");
			
		}
		else
		{
			printf("���޴���");
		}
		PrintStudentList(studentList);
	
}

/** ���ܷ����� */
void SearchByTotalScoreFromHightToLow(StudentList* studentList)
{
	//ָ��ѧ�������ָ�����飬һ��ָ��ָ��һ�����
	Student** pArray = (Student * *)malloc(sizeof(Student*) * studentList->numberOfStudents);
	Student* currentStudent = studentList->firstStudent;
	if (pArray && currentStudent)
	{
		for (int i = 0; currentStudent;i++)
		{
			pArray[i] = currentStudent;
			currentStudent = currentStudent->nextStudent;
		}

		for (int i = 0; i < studentList->numberOfStudents - 1; i++)
		{
			for (int j = 0; j < studentList->numberOfStudents - 1 - i; j++)
			{
					Student* tempNode;
					if (pArray[j]->totalScore > pArray[j + 1]->totalScore)
					{
						tempNode = pArray[j];
						pArray[j] = pArray[j + 1];
						pArray[j + 1] = tempNode;
					}
			}
		}

		/*** ��� **/
		printf("\tѧ��\t����\tƽʱ��\tʵ���\t���Է�\t�ܷ�\t\n");
		for (int i = 0; i < studentList->numberOfStudents; i++)
		{
			printf("\t%s ", pArray[i]->studentNumber);
			printf("\t%s ", pArray[i]->name);
			printf("\t%d ", pArray[i]->usualPerformance);
			printf("\t%d ", pArray[i]->experimentalGrade);
			printf("\t%d ", pArray[i]->examResult);
			printf("\t%d \n", pArray[i]->totalScore);
		}
	}
	
}

/** �鿴�༶������ */
double SearchClassPassRate(StudentList* studentList)
{
	double pass = 0;
	double total = 0;
	Student* currentStudent = studentList->firstStudent;
	while (currentStudent)
	{
		total++;
		if (currentStudent->totalScore >= 60)
		{
			pass++;
		}
		currentStudent = currentStudent->nextStudent;
	}
	printf("�༶������Ϊ��%.2lf%%\n", pass / total * 100);
	return pass / total;
}

/** �˳����� */
void quit()
{
	exit(0);
}

/** ��ӡѧ������ */
void PrintStudentList(StudentList* studentList)
{
	Student* currentStudent = studentList->firstStudent;
	printf("\tѧ��\t����\tƽʱ��\tʵ���\t���Է�\t�ܷ�\t\n");
	while (currentStudent)
	{
		
		printf("\t%s ", currentStudent->studentNumber);
		printf("\t%s ", currentStudent->name);
		printf("\t%d ", currentStudent->usualPerformance);
		printf("\t%d ", currentStudent->experimentalGrade);
		printf("\t%d ", currentStudent->examResult);
		printf("\t%d \n", currentStudent->totalScore);
		currentStudent = currentStudent->nextStudent;
	}
}