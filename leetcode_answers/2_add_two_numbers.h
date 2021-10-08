#pragma once
#include <iostream>

// runtime: 16ms, faster than 98.19% submissions
// memory : 71.5MB, less than 9.44% submissions

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* ptr1 = l1, * ptr2 = l2;
		ListNode* ptr = new ListNode(0), *result = ptr;
		int carry = 0;
		// flag will set to 1 when list 1 is shorter than list 2
		// set to 2 when list 2 is shorter than list 1
		int flag = 0;

		int a, b;
		do {
			// Check it is null or not
			if (ptr1 == nullptr) a = 0;
			else a = ptr1->val;
			if (ptr2 == nullptr) b = 0;
			else b = ptr2->val;

			// if add up > 10, then set up a carry
			int sum = a + b + carry;
			if (sum > 9)
			{
				sum -= 10;
				carry = 1;
			}
			else carry = 0;
			// Insert new node into result list
			ptr->next = new ListNode(sum);
			ptr = ptr->next;

			if ( ptr1 != nullptr) ptr1 = ptr1->next;
			if ( ptr2 != nullptr) ptr2 = ptr2->next;
		} while (ptr1 != nullptr || ptr2 != nullptr);

		if (carry == 1) ptr->next = new ListNode(1);

		return result->next;
	}

	void CheckAnswer()
	{
		ListNode* list_head_1 = new ListNode(2);
		list_head_1->next = new ListNode(4);
		list_head_1->next->next = new ListNode(3);

		ListNode* list_head_2 = new ListNode(5);
		list_head_2->next = new ListNode(6);
		list_head_2->next->next = new ListNode(4);

		ListNode* result = addTwoNumbers(list_head_1, list_head_2);
		cout << "[";
		while (result != nullptr) {
			cout << result->val << ",";
			result = result->next;
		}
		cout << '\b' << "]";
	}
};