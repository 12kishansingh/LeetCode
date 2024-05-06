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
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* last=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return last;
}
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
    
    int maxnode=-1;
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        maxnode=max(maxnode,curr->val);
         if(curr->val < maxnode){
            prev->next=curr->next;
            ListNode* temp=curr;
            curr=curr->next;
            delete(temp);
        
         }
         else{
            prev=curr;
            curr=curr->next;
         }
    }
    return reverse(head);
    }
};
