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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* beforeLeft=dummy;
        for(int i=1;i<left;i++){
            beforeLeft=beforeLeft->next;
        }
        ListNode* prev=NULL;
        ListNode* temp=beforeLeft->next;
        ListNode* start=temp;
        for(int i=0;i<=(right-left);i++){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        beforeLeft->next=prev;
        start->next=temp;
        return dummy->next;
    }
};