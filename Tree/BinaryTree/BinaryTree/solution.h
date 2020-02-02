#pragma once
#include "BinaryNode.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

template <typename T>
void Visit(BinaryNode<T> * t)
{
	cout << t->element << "	";
}

template <typename T>
BinaryNode<T>* CreateTreeByPreAndInOrderHelp(const vector<T>& preOrder, const vector<T>& inOrder, int preStart, int inStart, int inEnd)
{
	if (inStart > inEnd)
	{
		return nullptr;
	}
	//根据先序遍历得到根节点
	BinaryNode<T>* current = new BinaryNode<T>(preOrder[preStart]);
	//该节点在中序遍历的序号
	int inIndex = 0;
	for (int i = inStart; i <= inEnd; i++)
	{
		if (inOrder[i] == preOrder[preStart])
		{
			inIndex = i;
			break;
		}
	}
	//左根节点:当前前序Index+1，左子树是:中序遍历[中序start,当前节点序号-1]，
	current->left = CreateTreeByPreAndInOrderHelp(preOrder, inOrder, preStart + 1, inStart, inIndex - 1);
	//右根节点:当前前序Index+左子树个数(当前节点在中序Index-中序start)+1左根节点:前序遍历+1右子树是:中序遍历[当前节点序号-1,中序end]
	current->right = CreateTreeByPreAndInOrderHelp(preOrder, inOrder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);
	return current;
}

// LeetCode 105:
// 根据前序遍历和中序遍历来创建树
// 解题思路:
// 递归根据先序遍历得到根节点，确定跟节点,然后根据中序遍历得到左右指数
template <typename T>
BinaryNode<T>* CreateTreeByPreAndInOrder(const vector<T>& preOrder, const vector<T>& inOrder)
{
	if (preOrder.empty() or inOrder.empty())
		return nullptr;
	return CreateTreeByPreAndInOrderHelp(preOrder, inOrder, 0, 0, inOrder.size() - 1);
}
// LeetCode 144: 前序遍历
//前序遍历(递归)
template <typename T>
void PreOrderRecursive(BinaryNode<T> * t, void(*func)(BinaryNode<T> *t))
{
	if (t)
	{
		func(t);
		PreOrderRecursive(t->left, func);
		PreOrderRecursive(t->right, func);
	}
}

template <typename T>
BinaryNode<T>* CreateAVLBSTByOrderArrayHelp(const vector<T>& order,int start, int end)
{
	if (start > end) 
		return nullptr;
	int mid = (end - start) / 2 + start;
	BinaryNode<T>* midNode = new BinaryNode<T>(order[mid]);
	midNode->left = CreateAVLBSTByOrderArrayHelp(order, start, mid - 1);
	midNode->right = CreateAVLBSTByOrderArrayHelp(order, mid + 1, end);
	return midNode;
}
//LeetCode 108
//将有序数组转换为二叉搜索平衡树
//思路:平衡树就要求从中间节点做为根节点,左区域为左子树,右区域为右子树
template <typename T>
BinaryNode<T>* CreateAVLBSTByOrderArray(const vector<T>& order)
{
	return CreateAVLBSTByOrderArrayHelp(order, 0, order.size() - 1);
}

// 前序遍历(非递归)
// 把左子树压入栈，直到null,出栈,遍历节点右子树
template <typename T>
void PreOrderTraversal(BinaryNode<T> * t, vector<T>& out)
{
	if (t == nullptr)
	{
		return;
	}
	stack<BinaryNode<T> *> st;
	st.push(t);//压入当前节点
	while (!st.empty())
	{
		t = st.top();
		st.pop();//当前节点出栈
		out.push_back(t->element);
		if (t->right != nullptr)//如果右子树不为空则入栈
		{
			st.push(t->right);
		}
		if (t->left != nullptr)//如果左子树不为空则入栈
		{
			st.push(t->left);
		}
	}
}

// LeetCode 94:
// 中序遍历
// 中序遍历(递归)
template <typename T>
void InOrderRecursive(BinaryNode<T> * t, void(*func)(BinaryNode<T> *t))
{
	if (t)
	{
		InOrderRecursive(t->left, func);
		func(t);
		InOrderRecursive(t->right, func);
	}
}

// 中序遍历(非递归)
// 把左子树压入栈，直到null,出栈,遍历节点右子树
template <typename T>
void InOrderTraversal(BinaryNode<T> * t, vector<T>& out)
{
	if (t == nullptr)
	{
		return;
	}
	stack<BinaryNode<T> *> st;

	while (!st.empty() || t != nullptr)
	{
		if (t != nullptr)//把左子树压进栈
		{
			st.push(t);
			t = t->left;
		}
		else// 左子树为空就出栈，遍历右子树
		{
			t = st.top();
			st.pop();
			out.push_back(t->element);
			t = t->right;
		}
	}
}
// LeetCode 145: 后序遍历
//后序遍历(后归)
template <typename T>
void PostOrderRecursive(BinaryNode<T> * t, void(*func)(BinaryNode<T> *t))
{
	if (t)
	{
		PostOrderRecursive(t->left, func);
		PostOrderRecursive(t->right, func);
		func(t);
	}
}

// 后序遍历(非递归)
template <typename T>
void PostOrderTraversal(BinaryNode<T> * t, vector<T>& out)
{
	if (t == nullptr)
	{
		return;
	}
	stack<BinaryNode<T> *> st;

	while (!st.empty() || t != nullptr)
	{
		if (t != nullptr)
		{
			st.push(t);
			out.insert(0, t->element);
			t = t->right;
		}
		else
		{
			t = st.top();
			st.pop();
			t = t->left;
		}
	}
}

//LeetCode 102:
//层次遍历按且按层次输出
template <typename T>
void levelOrder(BinaryNode<T> * t)
{
	if (t == nullptr)
	{
		return;
	}
	queue<BinaryNode<T>*> queueNode;
	queueNode.push(t);
	while (!queueNode.empty())
	{
		int size = queueNode.size();
		cout << "[";
		while (size > 0)
		{
			size--;
			BinaryNode<T>* current = queueNode.front(); // 返回队首，结束时删除
			if (current == nullptr)
			{
				queueNode.pop();
				continue;
			}
			Visit(current);

			//把当前左右子树入队
			if (current->left != nullptr)
			{
				queueNode.push(current->left);
			}
			if (current->right != nullptr)
			{
				queueNode.push(current->right);
			}
			queueNode.pop();
		}
		cout << "]" << endl;
	}
}


//LeetCode 98:
//验证二叉树是否是搜索树
//搜索树的特性是左树<右树
//所以思路是:中序遍历是升序的=是搜索树
template <typename T>
bool isBST(BinaryNode<T> * t)
{
	/*
	//error C2440: “初始化”: 无法从“isBST::<lambda_21a1fa226ed1ac50bd3816eafa0d0ade>”转换为“void (__cdecl *)(BinaryNode<int> *)”
	vector<T> nodeVector;
	auto a_lambda_func = [&nodeVector](BinaryNode<T> * t) {
		nodeVector.push_back(t->element);
	};
	void(*func)(BinaryNode<T> *t) = a_lambda_func;
	InOrderRecursive(t, func);
	*/
	vector<T> nodeVector;
	InOrderTraversal(t, nodeVector);
	int size = nodeVector.size();
	if (size <= 0)
	{
		return false;
	}
	else if (size == 1)
	{
		return true;
	}
	for (int i = 1; i < size;i++)
	{
		if (nodeVector[i] < nodeVector[i - 1])
		{
			return false;
		}
	}
	return true;
}

//LeetCode 104:
//二叉树的最大深度(为根节点到最远叶子节点的最长路径上的节点数)
//递归版
template <typename T>
int MaxDepthRecursive(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	return (max(MaxDepthRecursive(t->left), MaxDepthRecursive(t->right)) + 1);
}
//非递归，层次遍历的思想到最后一层
template <typename T>
int MaxDepth(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	queue<BinaryNode<T> *> queueNode;
	queueNode.push(t);
	int depth = 0;
	while (!queueNode.empty())
	{
		int size = queueNode.size();
		while (size)
		{
			size--;
			BinaryNode<T>* current = queueNode.front();
			if (current == nullptr)
			{
				queueNode.pop();
				continue;
			}
			//把当前左右子树入队
			if (current->left != nullptr)
			{
				queueNode.push(current->left);
			}
			if (current->right != nullptr)
			{
				queueNode.push(current->right);
			}
			queueNode.pop();
		}
		depth++;
	}
	return depth;
}

//LeetCode 111
//二叉树的最小深度(最小深度是从根节点到最近叶子节点的最短路径上的节点数量)
//递归版
template <typename T>
int MinDepthRecursive(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	//注意叶节点是没有左子树也没有右子树的节点
	if (t->left == nullptr)
	{
		return MinDepthRecursive(t->right) + 1;
	}
	if (t->right == nullptr)
	{
		return MinDepthRecursive(t->left) + 1;
	}
	return (min(MinDepthRecursive(t->left), MinDepthRecursive(t->right)) + 1);
}

//非递归，层次遍历的思想到第一个叶节点
template <typename T>
int MinDepth(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	queue<BinaryNode<T> *> queueNode;
	queueNode.push(t);
	int depth = 0;
	while (!queueNode.empty())
	{
		int size = queueNode.size();
		while (size)
		{
			size--;
			BinaryNode<T>* current = queueNode.front();
			if (current == nullptr)
			{
				queueNode.pop();
				continue;
			}
			//找到第一个叶节点
			if (current->left == nullptr && current->right == nullptr)
			{
				return depth + 1;
			}
			//把当前左右子树入队
			if (current->left != nullptr)
			{
				queueNode.push(current->left);
			}
			if (current->right != nullptr)
			{
				queueNode.push(current->right);
			}
			queueNode.pop();
		}
		depth++;
	}
	return depth;
}

//LeetCode 110
//是否是平衡树(一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1)
//得到左右子树的最大高度进行比较
template <typename T>
bool IsAVL(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return false;
	}
	int leftHeight = MaxDepth(t->left);
	int rightHeight = MaxDepth(t->right);
	if (abs(leftHeight - rightHeight) <= 1)
	{
		return true;
	}
	return false;
}

