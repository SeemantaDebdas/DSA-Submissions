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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* nPtr = head;
        ListNode* curr = head;

        for(int i = 1; i <= n; i++)
            nPtr = nPtr -> next;
        
        if(nPtr == NULL)
        {
            head = head -> next;
            return head;
        }

        while(nPtr -> next != NULL)
        {
            nPtr = nPtr -> next;
            curr = curr -> next;
        }

        curr -> next = curr -> next -> next;

        return head;
    }
};