#pragma once
//SAMS��Student Achievement Management System �� ѧ���ɼ�����ϵͳ

/** ���������� */
typedef struct
{
	char studentNumber[30];
	char name[30];
	int usualPerformance;
	int experimentalGrade;
	int examResult;
	int totalScore;
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

/** ��ʼ��ѧ������ */
void InitStudentList(StudentList* studentList);

/** ���ı��ж�ȡ���ݵ������� */
void ReadFromTxt(StudentList *studentList);

/** ������� */
void ClearLinkedList(StudentList* studentList);

/** ���������뵽�ı��� */
void WriteToTxt(StudentList* studentList);

/** ����ѧ����� */
void AddStudentToLinkedList(StudentList* studentList);

/** ��ѧ�Ų��� */
Student* SearchByStudentNumber(StudentList* studentList);

/** ���������� */
Student* SearchByName(StudentList* studentList);

/** �޸�ѧ����Ϣ */
void ModifyStudentInformation(StudentList* studentList);

/** ɾ��ѧ����� */
void DeleteStudentInformation(StudentList* studentList);

/** ���ܷ����� */
void SearchByTotalScoreFromHightToLow(StudentList* studentList);

/** �鿴�༶������ */
double SearchClassPassRate(StudentList* studentList);

/** �˳����� */
void quit();

/** ��ӡѧ������ */
void PrintStudentList(StudentList* studentList);