#pragma once
//SAMS：Student Achievement Management System — 学生成绩管理系统

/** 定义链表结点 */
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

/** 定义头结点 */
typedef struct
{
	Student* firstStudent;
	int numberOfStudents;
}StudentList;



/*** 打印选择界面 **/
void PrintSelectionInterface();

/** 初始化学生链表 */
void InitStudentList(StudentList* studentList);

/** 从文本中读取数据到链表中 */
void ReadFromTxt(StudentList *studentList);

/** 清空链表 */
void ClearLinkedList(StudentList* studentList);

/** 将数据输入到文本中 */
void WriteToTxt(StudentList* studentList);

/** 增加学生结点 */
void AddStudentToLinkedList(StudentList* studentList);

/** 按学号查找 */
Student* SearchByStudentNumber(StudentList* studentList);

/** 按姓名查找 */
Student* SearchByName(StudentList* studentList);

/** 修改学社信息 */
void ModifyStudentInformation(StudentList* studentList);

/** 删除学生结点 */
void DeleteStudentInformation(StudentList* studentList);

/** 按总分排序 */
void SearchByTotalScoreFromHightToLow(StudentList* studentList);

/** 查看班级及格率 */
double SearchClassPassRate(StudentList* studentList);

/** 退出程序 */
void quit();

/** 打印学生链表 */
void PrintStudentList(StudentList* studentList);