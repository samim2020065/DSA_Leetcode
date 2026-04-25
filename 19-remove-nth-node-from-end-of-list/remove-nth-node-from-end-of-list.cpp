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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int len=0;
        while(curr){
            curr=curr->next;
            len++;
        }
        int target=len-n+1;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        curr=dummy;
        while(--target){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return dummy->next;
    }
};