#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//二叉树的定义
//↓ 该节点被称为这两个子节点的父节点
typedef struct binary_tree_node
{
	long long val;					//节点值
	binary_tree_node* LeftNode;		//左子节点
	binary_tree_node* RightNode;	//右子节点
	//构造函数初始化二叉树
	binary_tree_node(int x) :val(x), LeftNode(nullptr), RightNode(nullptr) {};
}tree_node;

//函数初始化
void delete_node();
vector<int> traversal_tree(tree_node* root);

//初始化二叉树
//初始化结点
void func()
{
	tree_node* n1 = new tree_node(1);
	tree_node* n2 = new tree_node(2);
	tree_node* n3 = new tree_node(3);
	tree_node* n4 = new tree_node(4);
	tree_node* n5 = new tree_node(5);
	//建立节点直接的联系，使用指针
	n1->LeftNode = n2;
	n1->RightNode = n3;
	n2->LeftNode = n4;
	n3->LeftNode = n5;
	vector<int>ans = traversal_tree(n1);
	for (auto i = ans.begin(); i != ans.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void delete_node()
{}

/*
二叉树的层序遍历
我们一般使用queue（队列）来进行二叉树的层序遍历
队列遵循先进先出，广度优先搜索遵循逐层推荐，这两者的思想本质是一样的
*/
vector<int> traversal_tree(tree_node* root)
{
	queue<tree_node*> q;
	q.push(root);
	vector<int>ans;
	while (!q.empty())
	{
		tree_node* node = q.front();
		q.pop();
		ans.push_back(node->val);
		if (node->LeftNode != nullptr)
		{
			q.push(node->LeftNode);
		}
		if (node->RightNode != nullptr)
		{
			q.push(node->RightNode);
		}
	}
	return ans;
}

int main()
{
	func();
	system("pause");
	return 0;
}