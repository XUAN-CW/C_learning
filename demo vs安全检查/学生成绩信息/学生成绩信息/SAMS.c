#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SAMS.h"

/** 打印选择界面 */
void PrintSelectionInterface()
{
	printf(" 学生成绩管理系统\n\n");
	printf(" 1、 输入学生信息\n");
	printf(" 2、 修改学生信息\n");
	printf(" 3、 删除学生信息\n");
	printf(" 4、 按姓名查询\n");
	printf(" 5、 按班级查询\n");
	printf(" 6、 按学号查询\n");
	printf(" 7、 按课程名查询\n");
	printf(" 8、 按总分高低查询\n");
	printf(" 9、 单科成绩排名\n");
	printf(" 10、查询班级优秀率\n");
	printf(" 11、退出系统\n");
}

void InitStudentList(StudentList *studentList)
{
	memset(studentList,0,sizeof(StudentList));
}

void EnterStudentInformationToStudentList(StudentList* studentList)
{
	while (1)
	{
		/** 创建新的学生结点 */
		Student* newStudent = (Student*)malloc(sizeof(Student));
		
		/** 将新结点插入到链表中，成为第一个结点 */
		if (newStudent)
		{
			//memset(newStudent, 0, sizeof(Student));

			printf("学生姓名：");
			scanf_s("%s", newStudent->name,sizeof(newStudent->name));
			printf("学号：");
			scanf_s("%s", newStudent->studentNumber, sizeof(newStudent->studentNumber));
			printf("班级：");
			scanf_s("%s", newStudent->class, sizeof(newStudent->class));
			for (int i = 0; i < sizeof(newStudent->course)/sizeof(Course); i++)
			{
				newStudent->numberOfCourse = 0;
				printf("课程名：");
				scanf_s("%s", newStudent->course[newStudent->numberOfCourse].courseName, sizeof(newStudent->course->courseName));
				printf("考试成绩：");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].examResult);
				printf("平时分");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].usualPerformance);
				printf("实验成绩：");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].experimentalGrade);
				printf("总分：");
				scanf_s("%lf", &newStudent->course[newStudent->numberOfCourse].totalScore);

				newStudent->nextStudent = studentList->firstStudent;
				studentList->firstStudent = newStudent;
			}
			
		}
		

		/** 询问是否继续创建新的结点 */
	}








}


void quit()
{
	exit(0);
}