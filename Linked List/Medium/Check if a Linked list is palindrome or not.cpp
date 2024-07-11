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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;

        //find the middle of the LL
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow -> next = Reverse(slow -> next);
        slow = slow -> next;
        fast = head;

        while(slow != NULL)
        {
            if(fast -> val != slow -> val)
                return false;
            
            slow = slow -> next;
            fast = fast -> next;
        }

        return true;
    }
};