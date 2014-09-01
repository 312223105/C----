#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 1000;

struct Node{
	int val;
	int key;
	Node *left, *right;
	int n;
	Node(int v, int k){val = v; key = k; n = 0;}
	Node(){val = 0, key = 1; n = 0;}
};
Node root;
int size(Node *root)
{
	if(root == 0) return 0;
	else return root->n;
}

Node* get(Node *root, int key);
Node* get(int key)
{
	return get(&root, key);
}

Node* get(Node *root, int key)
{
	//cout<<"*root = "<<root<<"\tkey = "<<key<<endl;
	if(root == 0)	return 0;
	if(root->key > key) return get(root->left, key);
	else if(root->key < key)	return get(root->right, key);
	else return root;
}

Node* put(Node *root, int key, int val);
Node* put(int key,int val)
{
	return put(&root, key, val);
}

Node* put(Node *root, int key, int val)
{
	if(root == 0)	return new Node(val,key);
	if(root->key > key) root->left = put(root->left, key, val);
	else if(root->key < key) root->right = put(root->right, key, val);
	else root->val = val;

	root->n = size(root->left) + size(root->right) + 1;
	return root;
}



int main()
{
	/*
	输入样例：
	4 5
	0 1 1 2 2 3 3 4 5 6
	*/

	int key, val;
	cin>>key>>val;
	root.key = key;	root.val = val;
	for(int i = 0; i < 5; i++)
	{
		cin>>key>>val;
		put(key,val);
	}

	for(int i = 0; i< 5; i++)
	{
		Node *node = get(i);

		cout<<i<<" ";
		if(node != 0)
			cout<<node->val<<endl;
		else
			cout<<"NAN"<<endl;
	}


}