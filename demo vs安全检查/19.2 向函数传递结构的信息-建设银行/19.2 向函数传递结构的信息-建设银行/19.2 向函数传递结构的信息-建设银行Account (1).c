#include "Account.h"
/*
double GetRepayment(Account account)
{
	account.bankName = "��������";
	return account.limit - account.billAmount;
}
*/

double GetRepayment(const Account *account)
{
	//����ָ�룬�Ƚ�Σ��

	//account->bankName = "��������";
	return account->limit - account->billAmount;
}
