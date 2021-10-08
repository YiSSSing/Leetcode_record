#pragma once
#include <xhash>



struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    ListNode* ptr1 = l1, * ptr2 = l2;
    ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* tail = newHead;
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->val > ptr2->val)
        {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        }
        tail = tail->next;
    }

    if (ptr1 != nullptr) tail->next = ptr1;
    else tail->next = ptr2;

    tail = newHead->next;
    free(newHead);
    return tail;
}