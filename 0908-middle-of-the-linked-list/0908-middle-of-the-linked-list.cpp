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
    ListNode* middleNode(ListNode* head) {
        int n{};
        ListNode*p=head;
        while(p!=nullptr){
            n++;
            p=p->next;
        }
        p=head;
        int i{};
        while(p!=nullptr){
            i++;
            if(i==(n/2+1)){
                return p;
            }
            p=p->next;
        }
        return head;
    }
};