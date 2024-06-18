
class Solution {
public:
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    ListNode* last=reverse(head->next);
    head->next->next=head;
    head->next=NULL;

    return last;
}
    ListNode* doubleIt(ListNode* head) {
       head=reverse(head);
       
       ListNode* curr=head;
       ListNode* prev=NULL;

       int carry=0;

       while(curr!=NULL){
        int x=(curr->val)*2+ carry;
        curr->val= x%10;
        if(x>=10){
            carry=1;
        }
        else{
            carry=0;
        }
        prev=curr;
        curr=curr->next;

       }
       if(carry!=0){
        ListNode* newhead=new ListNode(carry);
        prev->next=newhead;
       }
       return reverse(head);

    }
};
