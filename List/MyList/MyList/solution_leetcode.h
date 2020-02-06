#pragma once
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* createList(const vector<int>& l)
	{
		ListNode* head = nullptr;
		ListNode* p = head;
		for (auto val : l)
		{
			if (head == nullptr)
			{
				head = new ListNode(val);
				p = head;
			}
			else
			{
				p->next = new ListNode(val);
				p = p->next;
			}
		}
		return head;
	}
	//21. �ϲ�������������
	//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
	//ʾ����
	//	���룺1->2->4, 1->3->4
	//	�����1->1->2->3->4->4
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(-1);
		ListNode* p = &head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 == nullptr ? l2 : l1;
		return head.next;
	}
	//23. �ϲ�K����������
	//�ϲ� k �������������غϲ������������
	//ʾ��:
	//����:
	//[
	//	1->4->5,
	//	1->3->4,
	//	2->6
	//]
	//��� : 1->1->2->3->4->4->5->6
	//˼·��������һ��ĺϲ�2�����е�˼·���ٸ���List�Ķ��кϲ����һ������,ͷβ���
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0) {
			return nullptr;
		}
		int k = lists.size();
		while (k > 1) {
			for (int i = 0;i < k / 2;i++) {
				lists[i] = mergeTwoLists(lists[i], lists[i + (k + 1) / 2]);
			}
			k = (k + 1) / 2;
		}
		return lists[0];
	}
};