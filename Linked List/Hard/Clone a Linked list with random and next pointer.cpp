/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // void Print(Node* head)
    // {
    //     Node* curr = head;
    //     while(curr != NULL)
    //     {
    //         cout<<curr -> val<<" "<<curr -> random<<", ";
    //         curr = curr -> next;
    //     }
    // }

    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        //1. insert the copy in between the nodes
        Node* curr = head;
        while(curr != NULL)
        {
            Node* copy = new Node(curr -> val);
            copy -> next = curr -> next;
            curr -> next = copy;
            curr = curr -> next -> next;
        }

        //2. connect the random pointer
        curr = head;
        while(curr != NULL)
        {
            //curr -> next -> random = curr -> random;
            curr -> next -> random = (curr -> random)?curr -> random -> next : NULL;
            curr = curr -> next -> next;
        }

        //3. De link the copy from the original
        curr = head;
        Node* res = new Node(0);
        Node* resIter = res;

        while(curr != NULL)
        {
            Node* temp = curr -> next;
            
            //curr of copy
            resIter -> next = temp;
            resIter = resIter -> next;

            //curr of original
            curr -> next = temp -> next;
            curr = curr -> next;
        }

        return res -> next;
    }
};