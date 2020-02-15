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
	
	cout << "cpi的最大深度是:" << MaxDepthRecursive(cpi) << endl;
	cout << "cpi的最大深度是:" << MaxDepth(cpi) << endl;

	cout << "b的最大深度是:" << MaxDepthRecursive(b) << endl;
	cout << "b的最大深度是:" << MaxDepth(b) << endl;

	cout << "cpi的最小深度是:" << MinDepthRecursive(cpi) << endl;
	cout << "cpi的最小深度是:" << MinDepth(cpi) << endl;

	cout << "b的最小深度是:" << MinDepthRecursive(b) << endl;
	cout << "b的最小深度是:" << MinDepth(b) << endl;

	cout << "cpi是否搜索树:" << isBST(cpi)<< endl;
	cout << "b是否搜索树:" << isBST(b) << endl;

	cout << "cpi是否平衡树:" << IsAVL(cpi) << endl;
	cout << "b是否平衡树:" << IsAVL(b) << endl;

	cout << "cpi是否有路径=30:"<< hasPathSum(cpi,30) <<endl;
	cout << "cpi是否有路径=23:" << hasPathSum(cpi, 23) << endl;

	cout << "根据有序数组创建平衡搜索树" << endl;
	vector<int> orderArray{1,5,27,39,43,54,66,71,88,90,100,111,222};
	BinaryNode<int>* cbo = CreateAVLBSTByOrderArray(orderArray);
	cout << "cbo是否搜索树:" << isBST(cbo) << endl;
	cout << "cbo是否平衡树:" << IsAVL(cbo) << endl;
	cout << "cbo层次遍历:" << endl;
	levelOrder(cbo);
	cout << endl;


}
