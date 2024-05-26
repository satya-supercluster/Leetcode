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
    void push(ListNode*&nw,ListNode* &node,ListNode*&last){
        if(nw==nullptr){
            nw=new ListNode(node->val,nullptr);
            last=nw;
        }
        else{
            last->next=new ListNode(node->val,nullptr);
            last=last->next;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* nw=nullptr;
        ListNode* last=nullptr;
        while(l1!=nullptr and l2!=nullptr){
            if(l1->val<=l2->val)push(nw,l1,last),l1=l1->next;
            else push(nw,l2,last),l2=l2->next;
        }
        while(l1!=nullptr){
            push(nw,l1,last),l1=l1->next;
        }
        while(l2!=nullptr){
            push(nw,l2,last),l2=l2->next;
        }
        return nw;
    }
};