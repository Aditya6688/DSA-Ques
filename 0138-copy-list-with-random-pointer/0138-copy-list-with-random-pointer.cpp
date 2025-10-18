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
        if(!head) return head;

        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        for(Node* curr = head; curr!=NULL; curr = curr->next->next){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
        }

        Node* head1 = head->next;
        Node* temp = head1;

        for(Node* curr = head; curr!=NULL; curr = curr->next){
            curr->next = curr->next->next;
            temp->next = temp->next?temp->next->next:NULL;
            temp = temp->next;
        }

        return head1;
    }
};