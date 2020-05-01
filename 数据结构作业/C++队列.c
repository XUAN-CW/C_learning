#include <cstdlib>
#include <iostream>
#include <queue>
#define q1 q
using namespace std;

int main()
{
	int e, n, m;
	queue<int> q;
	if (q.empty()) cout << "1" << endl;
	for (int i = 1; i <= 10; i++)
		q.push(i);
	if (!q.empty()) cout << "1" << endl;

}