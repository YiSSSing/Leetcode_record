#pragma once
#include <cstddef>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* ptr1 = head, * ptr2 = head->next;
    //swap first two nodes
    ptr1->next = ptr2->next;
    ptr2->next = ptr1;
    head = ptr2;
    if (ptr1->next == NULL) return head;

    struct ListNode* ptr = ptr1;
    ptr1 = ptr1->next;
    ptr2 = ptr1->next;
    while (ptr2 != NULL)
    {
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        ptr->next = ptr2;
        ptr = ptr1;
        ptr1 = ptr->next;
        if (ptr1 == NULL) break;
        ptr2 = ptr1->next;
    }

    return head;
}