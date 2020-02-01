// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main()
{
	BinaryNode<char>* a = new BinaryNode<char>('a');
	BinaryNode<char>* c = new BinaryNode<char>('c');
	BinaryNode<char>* b = new BinaryNode<char>('b', a, c);
	cout << "二叉树前序遍历:" << endl;
	PreOrderRecursive(b, Visit);
	cout << endl;
	cout << "二叉树中序遍历:" << endl;
	InOrderRecursive(b, Visit);
	cout << endl;
	//		3
	//	   / \
	//    9   20
	//       /  \
	//      15   7
	vector<int> preOrder{ 3,9,20,15,7 };
	vector<int> inOrder{ 9,3,15,20,7 };
	BinaryNode<int>* cpi = CreateTreeByPreAndInOrder(preOrder,inOrder);
	
	cout << "二叉树前序遍历:" << endl;
	PreOrderRecursive(cpi, Visit);
	cout << endl;
	cout << "二叉树后序遍历:" << endl;
	PostOrderRecursive(cpi, Visit);
	cout << endl;
	cout << "二叉树层次遍历:" << endl;
	levelOrder(cpi);
	cout << endl;
	
	cout << "cpi是否搜索树:" << isBST(cpi)<< endl;
	cout << "b是否搜索树:" << isBST(b) << endl;

}
