/*
ID: 2
输入两个链表，输出两个链表相加的结果，如下：
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
特别注意当Input为(0) + (0)的时候
*/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a, b, c = 0;
		ListNode *p1 = l1, *p2 = l2;
		ListNode *head = NULL, *p = NULL;
		while (true) {
			if (p1) {
				a = p1->val;
				p1 = p1->next; 
			}
			else {
				a = 0;
			}
			if (p2) {
				b = p2->val;
				p2 = p2->next;
			}
			else {
				b = 0;
			}
			cout << "a: " << a << endl;
			cout << "b: " << b << endl;
			int sum = a + b + c;
			cout << "sum: " << sum << endl;
			if (!p1 && !p2 && sum == 0) {
				if (head == NULL) {
					ListNode *listNode = new ListNode(0);
					head = listNode;
				}
				break;
			}
			else {
				ListNode *listNode = new ListNode(sum % 10);
				c = sum / 10;

				if (head == NULL) {
					head = listNode;
					p = head;
				}
				else {
					p->next = listNode;
					p = p->next;
				}
			}
		}
		return head;
	}
};

