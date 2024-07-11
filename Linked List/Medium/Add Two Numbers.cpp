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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* last = NULL;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;

        while(ptr1 != NULL || ptr2 != NULL || carry != 0)
        {
            int sum = 0, n1 = 0, n2 = 0;
            if(ptr1 != NULL)
            {
                n1 = ptr1 -> val;
                ptr1 = ptr1 -> next;
            }
            if(ptr2 != NULL)
            {
                n2 = ptr2 -> val;
                ptr2 = ptr2 -> next;
            }
            
            sum = n1 + n2 + carry;
            carry = sum / 10;
            
            ListNode* newNode = new ListNode(sum % 10);
            if(res == NULL)
                res = newNode;
            else
                last -> next = newNode;
            
            last = newNode;

        }

        return res;
    }
};