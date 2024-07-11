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
    int GetCount(ListNode* head)
    {
        ListNode* curr = head;

        int count = 0;
        while(curr != NULL)
        {
            curr = curr -> next;
            count++;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;

        ListNode* curr = head;
        ListNode* tail = head;

        k = k % GetCount(head);
        if(k == 0)
            return head;

        int i = 0;
        while(curr -> next != NULL)
        {
            curr = curr -> next;
            if(i >= k)
                tail = tail -> next;
            
            i++;
        }

        curr -> next = head;
        head = tail -> next;
        tail -> next = NULL;

        return head;
    }
};