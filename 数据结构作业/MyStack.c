//#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
//
//template<typename  T> void swap(T* t1, T* t2) {
//	T tmpT;
//	tmpT = *t1;
//	*t1 = *t2;
//	*t2 = tmpT;
//}
//
//template<typename  stackNode>
//
//
//int main()
//{
//	//模板方法 
//	int num1 = 1, num2 = 2;
//	swap<int>(&num1, &num2);
//	printf("num1:%d, num2:%d\n", num1, num2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//public:
//	void setPoint(int x, int y) //实现setPoint函数
//	{
//		xPos = x;
//		yPos = y;
//	}
//	void printPoint() //实现printPoint函数
//	{
//		cout << "x = " << xPos << endl;
//		cout << "y = " << yPos << endl;
//	}
//private:
//	int xPos;
//	int yPos;
//};
//
////template<typename  stackNode>
//template<typename  T> void swap(T* t1, T* t2) {
//	T tmpT;
//	tmpT = *t1;
//	*t1 = *t2;
//	*t2 = tmpT;
//}
//
//class text
//{
//public:
//	int t() {
//		return 1;
//	}
//
//
//
//};
//
//int main()
//{
//	Point M; //用定义好的类创建一个对象 点M
//	M.setPoint(10, 20); //设置 M点 的x,y值
//	M.printPoint(); //输出 M点 的信息
//
//	text tttt;
//	printf("%d", tttt.t());
//
//
//	return 0;
//}

template <typename DataType>
class Link_Queue {
private:
	struct QueueNode {
		DataType data;
		QueueNode* next;
	};
protected:
	struct LinkQueue {
		QueueNode* front;
		QueueNode* rear;
	};

private:
	LinkQueue* Q=new LinkQueue;
public:
	Link_Queue() {
		Q->front = (QueueNode*)malloc(sizeof(QueueNode));
		Q->rear = Q->front;
		Q->rear->next = NULL;
	}

	bool QueueEmpty() {
		return Q->rear == Q->front;
	}

	void EnQueue(DataType x) {
		QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
		p->data = x;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
	}

	DataType GetFront() {
		if (QueueEmpty()) {
			cout << "the Queue is Empty!" << endl;
			exit(0);
		}
		else {
			return Q->front->next->data;
		}
	}

	DataType DeQueue() {
		QueueNode* p;
		if (QueueEmpty()) {
			cout << "the Queue is empty!" << endl;
			exit(0);
		}
		else {
			p = Q->front;
			Q->front = Q->front->next;
			free(p);
			return Q->front->data;
		}
	}
};

template <typename StackNode>
class Link_Stack {
private:
	typedef struct stacknode {
		StackNode data;
		stacknode* next;
	}StackNode;

protected:
	StackNode* top;

public:
	//StackNode() { top = NULL; }

	//判断栈是否为空
	bool StackEmpty() {
		return top == NULL;
	}

	StackNode* Push(StackNode data) {
		StackNode* p = (StackNode*)malloc(sizeof(StackNode));
		p->data = data;
		p->next = top;
		top = p;
		return top;
	}

	StackNode* Pop() {
		StackNode* p = top;
		if (StackEmpty()) { cout << "The stack is Empty!" << endl; exit(0); }
		else {
			top = p->next;
			free(p);
			return top;
		}
	}

	StackNode GetTop() {
		if (StackEmpty()) {
			cout << "The Stack is Empty!" << endl;
			//exiy(0);
		}
		else {
			return top->data;
		}
	}
};

int main()
{
	Link_Queue<int> q;
	//q.EnQueue(1);
	cout<<q.QueueEmpty();

	Link_Stack<double> s;
	cout <<s.StackEmpty() ;

	return 0;
}