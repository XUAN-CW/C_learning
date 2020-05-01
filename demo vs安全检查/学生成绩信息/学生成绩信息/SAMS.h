#pragma once
//SAMS：Student Achievement Management System — 学生成绩管理系统
typedef struct _course_
{
	char courseName[50];
	double usualPerformance;
	double experimentalGrade;
	double examResult;
	double totalScore;
}Course;

/** 定义链表结点 */
typedef struct
{
	char studentNumber[30];
	char name[30];
	char class[30];
	int numberOfCourse;
	Course course[30];
	struct Student* nextStudent;
}Student;

/** 定义头结点 */
typedef struct
{
	Student* firstStudent;
	int numberOfStudents;
}StudentList;

/*** 打印选择界面 **/
void PrintSelectionInterface();

/*** 初始化学生链表 **/
void InitStudentList(StudentList *studentList);

/*** 将学生信息插入到学生清单，学生信息直接插入到第一个结点 **/
void EnterStudentInformationToStudentList(StudentList *studentList);

void ModifyStudentInformation(StudentList* studentList);

void DeleteStudentInformation(StudentList* studentList);

void SearchByName(StudentList* studentList,char name[]);

void SearchByClass(StudentList* studentList, char class[]);

void SearchByStudentNumber(StudentList* studentList, char studentNumber[]);

void SearchByCourseName(StudentList* studentList, char studentNumber[]);

void SearchByTotalScoreFromHightToLow(StudentList* studentList);

void RankingInSingleSubject(StudentList* studentList);

void SearchClassExcellenceRateAndPassRate(StudentList* studentList);

void quit();


