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
	//������������õ����ڵ�
	BinaryNode<T>* current = new BinaryNode<T>(preOrder[preStart]);
	//�ýڵ���������������
	int inIndex = 0;
	for (int i = inStart; i <= inEnd; i++)
	{
		if (inOrder[i] == preOrder[preStart])
		{
			inIndex = i;
			break;
		}
	}
	//����ڵ�:��ǰǰ��Index+1����������:�������[����start,��ǰ�ڵ����-1]��
	current->left = CreateTreeByPreAndInOrderHelp(preOrder, inOrder, preStart + 1, inStart, inIndex - 1);
	//�Ҹ��ڵ�:��ǰǰ��Index+����������(��ǰ�ڵ�������Index-����start)+1����ڵ�:ǰ�����+1��������:�������[��ǰ�ڵ����-1,����end]
	current->right = CreateTreeByPreAndInOrderHelp(preOrder, inOrder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);
	return current;
}

// LeetCode 105:
// ����ǰ����������������������
// ����˼·:
// �ݹ������������õ����ڵ㣬ȷ�����ڵ�,Ȼ�������������õ�����ָ��
template <typename T>
BinaryNode<T>* CreateTreeByPreAndInOrder(const vector<T>& preOrder, const vector<T>& inOrder)
{
	if (preOrder.empty() or inOrder.empty())
		return nullptr;
	return CreateTreeByPreAndInOrderHelp(preOrder, inOrder, 0, 0, inOrder.size() - 1);
}
// LeetCode 144: ǰ�����
//ǰ�����(�ݹ�)
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
//����������ת��Ϊ��������ƽ����
//˼·:ƽ������Ҫ����м�ڵ���Ϊ���ڵ�,������Ϊ������,������Ϊ������
template <typename T>
BinaryNode<T>* CreateAVLBSTByOrderArray(const vector<T>& order)
{
	return CreateAVLBSTByOrderArrayHelp(order, 0, order.size() - 1);
}

// ǰ�����(�ǵݹ�)
// ��������ѹ��ջ��ֱ��null,��ջ,�����ڵ�������
template <typename T>
void PreOrderTraversal(BinaryNode<T> * t, vector<T>& out)
{
	if (t == nullptr)
	{
		return;
	}
	stack<BinaryNode<T> *> st;
	st.push(t);//ѹ�뵱ǰ�ڵ�
	while (!st.empty())
	{
		t = st.top();
		st.pop();//��ǰ�ڵ��ջ
		out.push_back(t->element);
		if (t->right != nullptr)//�����������Ϊ������ջ
		{
			st.push(t->right);
		}
		if (t->left != nullptr)//�����������Ϊ������ջ
		{
			st.push(t->left);
		}
	}
}

// LeetCode 94:
// �������
// �������(�ݹ�)
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

// �������(�ǵݹ�)
// ��������ѹ��ջ��ֱ��null,��ջ,�����ڵ�������
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
		if (t != nullptr)//��������ѹ��ջ
		{
			st.push(t);
			t = t->left;
		}
		else// ������Ϊ�վͳ�ջ������������
		{
			t = st.top();
			st.pop();
			out.push_back(t->element);
			t = t->right;
		}
	}
}
// LeetCode 145: �������
//�������(���)
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

// �������(�ǵݹ�)
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
//��α������Ұ�������
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
			BinaryNode<T>* current = queueNode.front(); // ���ض��ף�����ʱɾ��
			if (current == nullptr)
			{
				queueNode.pop();
				continue;
			}
			Visit(current);

			//�ѵ�ǰ�����������
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
//��֤�������Ƿ���������
//������������������<����
//����˼·��:��������������=��������
template <typename T>
bool isBST(BinaryNode<T> * t)
{
	/*
	//error C2440: ����ʼ����: �޷��ӡ�isBST::<lambda_21a1fa226ed1ac50bd3816eafa0d0ade>��ת��Ϊ��void (__cdecl *)(BinaryNode<int> *)��
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
//��������������(Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ���)
//�ݹ��
template <typename T>
int MaxDepthRecursive(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	return (max(MaxDepthRecursive(t->left), MaxDepthRecursive(t->right)) + 1);
}
//�ǵݹ飬��α�����˼�뵽���һ��
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
			//�ѵ�ǰ�����������
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
//����������С���(��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�����)
//�ݹ��
template <typename T>
int MinDepthRecursive(BinaryNode<T> *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	//ע��Ҷ�ڵ���û��������Ҳû���������Ľڵ�
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

//�ǵݹ飬��α�����˼�뵽��һ��Ҷ�ڵ�
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
			//�ҵ���һ��Ҷ�ڵ�
			if (current->left == nullptr && current->right == nullptr)
			{
				return depth + 1;
			}
			//�ѵ�ǰ�����������
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
//�Ƿ���ƽ����(һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1)
//�õ��������������߶Ƚ��бȽ�
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

