#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "SAMS.h"

/** 初始化学生链表 */
void InitStudentList(StudentList* studentList)
{
	memset(studentList, 0, sizeof(StudentList));
}

/** 打印选择界面 */
void PrintSelectionInterface()
{
	printf("\n学生成绩管理系统\n");
	printf(" 1、输入学生信息\n");
	printf(" 2、修改学生信息\n");
	printf(" 3、删除学生信息\n");
	printf(" 4、按姓名查询\n");
	printf(" 5、按学号查询\n");
	printf(" 6、按总分高低查询\n");
	printf(" 7、查询班级优秀率\n");
	printf(" 8、查看当前学生\n");
	printf(" 9、退出系统\n");
}

/** 从文本中读取数据到链表中 */
void ReadFromTxt(StudentList* studentList)
{
	ClearLinkedList(studentList);
	//printf("ReadFromTxt\n");
	FILE* read_file;
	int openSucceed = fopen_s(&read_file, "student.txt", "r");		//打开成功返回 0 
	if (read_file != NULL && openSucceed == 0)
	{
		while (0 == feof(read_file))	//0：文件未读取结束  1：文件已读取结束
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

/** 清空链表 */
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

/** 将数据输入到文本中 */
void WriteToTxt(StudentList* studentList)
{
	FILE* write_file;
	int openSucceed = fopen_s(&write_file, "student.txt", "w");		//打开成功返回 0 
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

/** 增加学生结点 */
void AddStudentToLinkedList(StudentList* studentList)
{
	Student* newStudent = (Student*)malloc(sizeof(Student));
	if (newStudent)
	{
		printf("学生学号：");
		scanf_s("%s", newStudent->studentNumber, sizeof(newStudent->studentNumber));
		printf("学生姓名：");
		scanf_s("%s", newStudent->name,sizeof(newStudent->name));
		printf("学生平时成绩：");
		scanf_s("%d", &(newStudent->usualPerformance));
		printf("学生实验成绩：");
		scanf_s("%d", &(newStudent->experimentalGrade));
		printf("学生考试成绩：");
		scanf_s("%d", &(newStudent->examResult));
		printf("学生总评成绩：");
		scanf_s("%d", &(newStudent->totalScore));

		newStudent->nextStudent = (Student*)studentList->firstStudent;
		studentList->firstStudent = newStudent;
		studentList->numberOfStudents++;
		WriteToTxt(studentList);
	}
}

/** 按学号查找 */
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

/** 按姓名查找 */
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

/** 修改学生信息 */
void ModifyStudentInformation(StudentList* studentList)
{
		printf("按学号查找请按1\n");
		printf("按姓名查找请按2\n");
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
			printf("输入该学生的新信息\n");
			printf("学生学号：");
			scanf_s("%s", currentStudent->studentNumber, sizeof(currentStudent->studentNumber));
			printf("学生姓名：");
			scanf_s("%s", currentStudent->name, sizeof(currentStudent->name));
			printf("学生平时成绩：");
			scanf_s("%d", &(currentStudent->usualPerformance));
			printf("学生实验成绩：");
			scanf_s("%d", &(currentStudent->experimentalGrade));
			printf("学生考试成绩：");
			scanf_s("%d", &(currentStudent->examResult));
			printf("学生总评成绩：");
			scanf_s("%d", &(currentStudent->totalScore));

			WriteToTxt(studentList);
		}
		else
		{
			printf("查无此人\n");
		}
		PrintStudentList(studentList);
}

/** 删除学生结点 */
void DeleteStudentInformation(StudentList* studentList)
{
		printf("按学号查找请按1\n");
		printf("按姓名查找请按2\n");
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
			printf("删除成功！\n");
			
		}
		else
		{
			printf("查无此人");
		}
		PrintStudentList(studentList);
	
}

/** 按总分排序 */
void SearchByTotalScoreFromHightToLow(StudentList* studentList)
{
	//指向学生链表的指针数组，一个指针指向一个结点
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

		/*** 输出 **/
		printf("\t学号\t姓名\t平时分\t实验分\t考试分\t总分\t\n");
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

/** 查看班级及格率 */
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
	printf("班级及格率为：%.2lf%%\n", pass / total * 100);
	return pass / total;
}

/** 退出程序 */
void quit()
{
	exit(0);
}

/** 打印学生链表 */
void PrintStudentList(StudentList* studentList)
{
	Student* currentStudent = studentList->firstStudent;
	printf("\t学号\t姓名\t平时分\t实验分\t考试分\t总分\t\n");
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