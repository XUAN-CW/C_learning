#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct _account
{
	const char *bankName;
	const char *userName;
	double limit;       //�˻��Ķ��
	double billAmount;  //�����˵����
}Account;
//�õ�ĳ���˻�����Ӧ������
//���ݽṹ����ʱ���Ǹ��������ṹ������ֵ�������� - Ч�ʵ�
//double GetRepayment(Account account);

//�������ݵ��ǽṹָ�� - ����Ƭ
//����������const�󣬻���ָ����Ӱ�ȫ
double GetRepayment(const Account *account);


