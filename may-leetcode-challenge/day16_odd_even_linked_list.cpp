/** 
Title :  Odd Even Linked List
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/
Idea  :  Taking three pointers, one for odd list, one for even list and one to point event list head
Time Complexity : O(n) 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *oddList = head, *evenList = head->next, *evenHead = evenList;
        while (evenList != NULL && evenList->next != NULL)
        {
            oddList->next = evenList->next;
            oddList = oddList->next;
            evenList->next = oddList->next;
            evenList = evenList->next;
        }
        oddList->next = evenHead;
        return head;
    }
};