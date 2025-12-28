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
        if(!head){
            return NULL;
        }
        Node* curr=head;
        while(curr){
            Node* copyNode=new Node(curr->val);
            copyNode->next=curr->next;
            curr->next=copyNode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* dummy=new Node(0);
        Node* temp=dummy;
        curr=head;
        while(curr){
            temp->next=curr->next;
            curr->next=curr->next->next;
            temp=temp->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};