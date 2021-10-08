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

 struct ListNode* mergeRecursive(struct ListNode** lists, int start, int end)
 {
     if (start > end) return NULL;
     else if (start == end) return lists[start];
     int mid = (start + end) >> 1;
     struct ListNode* left = mergeRecursive(lists, start, mid);
     struct ListNode* right = mergeRecursive(lists, mid + 1, end);
     return mergeTwoLists(left, right);
 }

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0) return NULL;
    return mergeRecursive(lists, 0, listsSize - 1);
}