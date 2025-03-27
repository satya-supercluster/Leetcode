/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mp;
        for(ListNode*root=headA;root!=nullptr;root=root->next){
            mp[root]++;
        }
        for(ListNode*root=headB;root!=nullptr;root=root->next){
            mp[root]++;
            if(mp[root]==2) return root;
        }
        return nullptr;
    }
};