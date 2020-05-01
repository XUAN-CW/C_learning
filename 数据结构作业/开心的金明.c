#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include<iostream>
#include<algorithm>
using namespace std;
int w[6], v[6], f[11];//w数组为重要度，v数组为money，f是用来dp的数组
int n, m;//n是总物品个数，m是总钱数
int main()
{
	cin >> m >> n;//输入

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
		w[i] *= v[i];//w数组在这里意义变为总收获（重要度*money）
	}

	//01背包（参照第二类模板“一维数组优化”）
	int i, j, surplus;
	for (i = 1; i <= n; i++)
	{
		for (j = m; j >= v[i]; j--)//注意从m开始
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);//dp
		}
		surplus = m - j - 1;
	}
	//选了4、3、2 的
	cout << f[m] << endl;//背包大小为m时最大值
	return 0;
}