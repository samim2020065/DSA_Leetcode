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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prevGroup=dummy;
        while(true){
            ListNode* kth=prevGroup;
            for(int i=0;i<k&&kth;i++){
                kth=kth->next;
            }
            if(!kth){
                break;
            }
            ListNode* prev=NULL;
            ListNode* temp=prevGroup->next;
            ListNode* start=temp;
            for(int i=0;i<k;i++){
                ListNode* front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            prevGroup->next=prev;
            start->next=temp;

            prevGroup=start;
        }
        return dummy->next;
    }
};