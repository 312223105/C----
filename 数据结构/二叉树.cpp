#include <iostream>
#include <vector>
#include <Queue>
using namespace std;

template <class type>
struct Node
{
	type data;
	Node<type> *lchild, *rchild;
};

Node<int> root;
//按前序创建  示例数据： 1 2 0 4 0 0 3 0 0
Node<int>* create_bt(Node<int> *bt)
{
	int data;
	cin>>data;
	if(data == 0)
		return NULL;
	else
	{
		bt = new Node<int>;
		bt->data = data;
		bt->lchild = create_bt(bt->lchild);
		bt->rchild = create_bt(bt->rchild);
		return bt;
	}
}

void preOrder(Node<int> *bt)
{
	if(bt == NULL)
	{
		cout<<"0 ";
		return;
	}
	
	cout<<bt->data<<" ";
	preOrder(bt->lchild);
	preOrder(bt->rchild);
}

void inOrder(Node<int> *bt)
{
	if(bt == NULL)
	{
		cout<<"0 ";
		return ;
	}

	inOrder(bt->lchild);
	cout<<bt->data<<" ";
	inOrder(bt->rchild);
}

void postOrder(Node<int> *bt)
{
	if(bt == NULL)
	{
		cout<<"0 ";
		return ;
	}

	postOrder(bt->lchild);
	postOrder(bt->rchild);
	cout<<bt->data<<" ";
}


void levelOrder(Node<int> *root)
{
	queue<Node<int> *> Q;

	Q.push(root);
	while(!Q.empty())
	{
		Node<int> *front = Q.front();
		Q.pop();
		cout<<front->data;

		if(front->lchild != NULL)
			Q.push(front->lchild);

		if(front->rchild != NULL)
			Q.push(front->rchild);	
	}
}

int main()
{
	cout<<"创建二叉树："<<endl;
	Node<int> *root = 0;
	root = create_bt(root);
	cout<<endl<<"前序遍历二叉树："<<endl;
	preOrder(root);

	cout<<endl<<"中序遍历二叉树："<<endl;
	inOrder(root);

	cout<<endl<<"后序遍历二叉树："<<endl;
	postOrder(root);

	cout<<endl<<"层序遍历二叉树："<<endl;
	levelOrder(root);

	cout<<endl;
	return 0;
}