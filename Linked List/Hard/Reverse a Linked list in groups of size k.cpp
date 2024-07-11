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

    ListNode* Reverse(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        int count = 0;
        while(curr != NULL && count < k)
        {
            curr = curr -> next;
            count++;
        }
        
        if(count < k)
            return head;
        
        count = 0;
        curr = head;

        while(curr != NULL && count < k)
        {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;

            count++;
        }

        if(curr != NULL)
        {
            head -> next = Reverse(curr, k);
        }

        return prev;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;

        return Reverse(head, k);
    }
};