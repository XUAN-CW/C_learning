#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;

typedef struct node {
	char data;
	struct node* left;     //左子树
	struct node* right;    //右子树
}Node;

/** 创建一棵树并返回根节点 */
Node * CreateBinaryTree() {
	//输入 data 
	char data;
	cin>> data;
	//用户输入 '0' 表示结束当前子树的创建
	if ('0' == data) {
		return NULL;
	}
	else{
		//创建当前结点
		Node* root = new Node;
		memset(root, 0, sizeof(Node));
		root->data = data;
		//递归创建左子树
		cout << root->data << " left  node:" ;
		root->left = CreateBinaryTree();
		//递归创建右子树
		cout << root->data << " right node:" ;
		root->right = CreateBinaryTree();
		return root;
	}
	
}

/** 前序遍历 */
void  PreorderTraversal(Node* root) {
	//先访问根结点，然后遍历左子树，最后遍历右子树
	if (root){
		cout<<root->data;
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

/** 中序遍历 */
void InorderTraversal(Node* root) {
	if (root) {
		InorderTraversal(root->left);
		cout << root->data;
		InorderTraversal(root->right);
	}
}

/** 后序遍历 */
void PostorderTraversal(Node* root) {
	if (root) {
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		cout << root->data;
	}
}

/** 摧毁树 */
void DestroyTree(Node* root) {
	if (root) {
		DestroyTree(root->left);
		DestroyTree(root->right);
		free(root);
	}
}

void DestroyTree2(Node** root) {
	DestroyTree(*root);
	*root = NULL;
}

/** 前序遍历 - 非递归 */
void PreorderTraversal_NonRecursive(Node* root) {

	if (root) {
		Node* currentNode = root;
		stack<Node*> s;
		while (!s.empty() || currentNode) {
			//边遍历边打印，并存入栈中，以后需要借助这些根节点进入右子树
			while (currentNode){
				cout << setw(1) << currentNode->data;
				s.push(currentNode);
				currentNode = currentNode->left;
			}
			//当p为空时，说明根和左子树都遍历完了，该进入右子树了
			if (!s.empty()){
				currentNode = s.top();
				s.pop();
				currentNode = currentNode->right;
			}
		}
	}
}

/** 中序遍历 - 非递归 */
void InorderTraversal_NonRecursive(Node* root)
{
	if (root) //树非空
	{
		Node* currentNode = root;
		stack<Node*> s;
		while (!s.empty() || currentNode)
		{
			//一直遍历到左子树最下边，边遍历边保存根节点到栈中
			while (currentNode)
			{
				s.push(currentNode);
				currentNode = currentNode->left;
			}
			//当p为空时，说明已经到达左子树最下边，这时需要出栈了
			if (!s.empty())
			{
				currentNode = s.top();
				s.pop();
				cout << setw(1) << currentNode->data;
				//进入右子树，开始新的一轮左子树遍历
				currentNode = currentNode->right;
			}
		}
	}
}

/** 后序遍历 - 非递归 */
void PostorderTraversal_NonRecursive(Node* root)
{
	if (root == NULL)
		return;
	stack<Node*> s;
	//currentNode:当前访问节点，pLastVisit:上次访问节点
	Node* currentNode=root;
	Node* lastVisitNode = NULL;
	//先把currentNode移动到左子树最下边
	while (currentNode)
	{
		s.push(currentNode);
		currentNode = currentNode->left;
	}
	while (!s.empty())
	{
		//走到这里，currentNode都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
		currentNode = s.top();
		s.pop();
		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if (currentNode->right == NULL || currentNode->right == lastVisitNode)
		{
			cout << setw(1) << currentNode->data;
			//修改最近被访问的节点
			lastVisitNode = currentNode;
		}
		else
		{
			//根节点再次入栈
			s.push(currentNode);
			//进入右子树，且可肯定右子树一定不为空
			currentNode = currentNode->right;
			while (currentNode)
			{
				s.push(currentNode);
				currentNode = currentNode->left;
			}
		}
	}
}

/** 层序遍历 */
void LevelOrder(Node* root) {
	queue<Node*> queue1;
	queue<Node*> queue2;
	queue<Node*>* currentFloor = &queue1;
	queue<Node*>* nextFloor = &queue2;
	currentFloor->push(root);
	cout << endl;
	for (int i = 0; !currentFloor->empty(); i++) {
		cout << i + 1 << " floor:";
		while (!currentFloor->empty()) {
			//访问当前层
			cout << currentFloor->front()->data;
			//下一层入队
			if (currentFloor->front()->left) {
				nextFloor->push(currentFloor->front()->left);
			}
			if (currentFloor->front()->right) {
				nextFloor->push(currentFloor->front()->right);
			}
			currentFloor->pop();
		}
		queue<Node*>* temp;
		//移到下一层
		temp = currentFloor;
		currentFloor = nextFloor;
		nextFloor = temp;
		cout << endl;
	}

}

void statistics(Node* root,int *count,char ch)
{
	//先访问根结点，然后遍历左子树，最后遍历右子树
	if (root) {
		//cout << root->data;
		if (ch==root->data) {
			(*count)++;
		}
		int c;
		statistics(root->left, count,ch);
		statistics(root->right, count,ch);
	}
}

int main()
{
	Node* root = NULL;
	cout << "root:";
	root=CreateBinaryTree();

	cout <<"PreorderTraversal:";
	PreorderTraversal(root);
	cout << endl;

	cout << "InorderTraversal:";
	InorderTraversal(root);
	cout << endl;

	cout << "PostorderTraversal:";
	PostorderTraversal(root);
	cout << endl;

	cout << "PreorderTraversal_NonRecursive:";
	PreorderTraversal_NonRecursive(root);
	cout << endl;

	cout << "InorderTraversal_NonRecursive:";
	InorderTraversal_NonRecursive(root);
	cout << endl;

	cout << "PostorderTraversal_NonRecursive:";
	PostorderTraversal_NonRecursive(root);
	cout << endl;

	cout << "LevelOrder:";
	LevelOrder(root);
	cout << endl;

	cout << "statistics:";
	int count = 0;
	char ch;
	cin >> ch;
	statistics(root,  &count,ch);
	cout << count;
	cout << endl;

	cout << "DestroyTree:";
	DestroyTree2(&root);
	//DestroyTree(root);
	//root = NULL;
	PostorderTraversal(root);
	cout << endl;

	return 0;
}