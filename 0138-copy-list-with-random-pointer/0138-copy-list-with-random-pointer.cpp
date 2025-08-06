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
    Node* copyRandomList(Node* head) {
        if(head == NULL) return nullptr;
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        for(Node* curr=head;curr;curr = curr->next->next){
            curr->next->random = (curr->random == NULL)?NULL:curr->random->next;
        }

        Node* h2 = head->next;
        Node* clone = h2;
        for(Node* curr = head; curr; curr = curr->next){
            curr->next = curr->next->next;
            clone->next = clone->next?clone->next->next:NULL;
            clone = clone->next;
        }
        return h2;
    }
};