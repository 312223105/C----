#include <iostream>
using namespace std;

/*
#未完成


#与使用深度优先搜索实现，UnionFind不需要对图进行预处理，可以随时通过添加新边重新计算连通性。
#在完成只需要判断连通性或是需要完成有大量连通性查询和插入操作混合等类似的任务时，更倾向使用unionfind算法
*/
struct Node
{
	Node *left, right;

	int key;
	Node(int k){key = k;}
};

Node* put(Node *root, int key)
{
	if(root == NULL)	return new Node(key);

	if(root->key > key)	root->left = put(root->left, key);
	else if(root->key < key) root->right = put(root->right, key);
	else root->key = key;

	return root;
}

Node* get(Node* root, int key)
{
	if(root == NULL)	return NULL;
	if(root->key > key) return get(root->left, key);
	else if(root->key < key) return get(root->right, key);
	else return root;
}

int main()
{
	Node *root;

}
