#pragma once
//SAMS��Student Achievement Management System �� ѧ���ɼ�����ϵͳ
typedef struct _course_
{
	char courseName[50];
	double usualPerformance;
	double experimentalGrade;
	double examResult;
	double totalScore;
}Course;

/** ���������� */
typedef struct
{
	char studentNumber[30];
	char name[30];
	char class[30];
	int numberOfCourse;
	Course course[30];
	struct Student* nextStudent;
}Student;

/** ����ͷ��� */
typedef struct
{
	Student* firstStudent;
	int numberOfStudents;
}StudentList;

/*** ��ӡѡ����� **/
void PrintSelectionInterface();

/*** ��ʼ��ѧ������ **/
void InitStudentList(StudentList *studentList);

/*** ��ѧ����Ϣ���뵽ѧ���嵥��ѧ����Ϣֱ�Ӳ��뵽��һ����� **/
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


