#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SAMS.h"

/** ��ӡѡ����� */
void PrintSelectionInterface()
{
	printf(" ѧ���ɼ�����ϵͳ\n\n");
	printf(" 1�� ����ѧ����Ϣ\n");
	printf(" 2�� �޸�ѧ����Ϣ\n");
	printf(" 3�� ɾ��ѧ����Ϣ\n");
	printf(" 4�� ��������ѯ\n");
	printf(" 5�� ���༶��ѯ\n");
	printf(" 6�� ��ѧ�Ų�ѯ\n");
	printf(" 7�� ���γ�����ѯ\n");
	printf(" 8�� ���ָܷߵͲ�ѯ\n");
	printf(" 9�� ���Ƴɼ�����\n");
	printf(" 10����ѯ�༶������\n");
	printf(" 11���˳�ϵͳ\n");
}

void InitStudentList(StudentList *studentList)
{
	memset(studentList,0,sizeof(StudentList));
}

void EnterStudentInformationToStudentList(StudentList* studentList)
{
	while (1)
	{
		/** �����µ�ѧ����� */
		Student* newStudent = (Student*)malloc(sizeof(Student));
		
		/** ���½����뵽�����У���Ϊ��һ����� */
		if (newStudent)
		{
			//memset(newStudent, 0, sizeof(Student));

			printf("ѧ��������");
			scanf_s("%s", newStudent->name,sizeof(newStudent->name));
			printf("ѧ�ţ�");
			scanf_s("%s", newStudent->studentNumber, sizeof(newStudent->studentNumber));
			printf("�༶��");
			scanf_s("%s", newStudent->class, sizeof(newStudent->class));
			for (int i = 0; i < sizeof(newStudent->course)/sizeof(Course); i++)
			{
				newStudent->numberOfCourse = 0;
				printf("�γ�����");
				scanf_s("%s", newStudent->course[newStudent->numberOfCourse].courseName, sizeof(newStudent->course->courseName));
				printf("���Գɼ���");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].examResult);
				printf("ƽʱ��");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].usualPerformance);
				printf("ʵ��ɼ���");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].experimentalGrade);
				printf("�ܷ֣�");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].totalScore);

				newStudent->nextStudent = studentList->firstStudent;
				studentList->firstStudent = newStudent;
			}
			
		}
		

		/** ѯ���Ƿ���������µĽ�� */
	}








}


void quit()
{
	exit(0);
}