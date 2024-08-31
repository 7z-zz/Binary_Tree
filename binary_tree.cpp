#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//�������Ķ���
//�� �ýڵ㱻��Ϊ�������ӽڵ�ĸ��ڵ�
typedef struct binary_tree_node
{
	long long val;					//�ڵ�ֵ
	binary_tree_node* LeftNode;		//���ӽڵ�
	binary_tree_node* RightNode;	//���ӽڵ�
	//���캯����ʼ��������
	binary_tree_node(int x) :val(x), LeftNode(nullptr), RightNode(nullptr) {};
}tree_node;

//������ʼ��
void delete_node();
vector<int> traversal_tree(tree_node* root);

//��ʼ��������
//��ʼ�����
void func()
{
	tree_node* n1 = new tree_node(1);
	tree_node* n2 = new tree_node(2);
	tree_node* n3 = new tree_node(3);
	tree_node* n4 = new tree_node(4);
	tree_node* n5 = new tree_node(5);
	//�����ڵ�ֱ�ӵ���ϵ��ʹ��ָ��
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
�������Ĳ������
����һ��ʹ��queue�����У������ж������Ĳ������
������ѭ�Ƚ��ȳ����������������ѭ����Ƽ��������ߵ�˼�뱾����һ����
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