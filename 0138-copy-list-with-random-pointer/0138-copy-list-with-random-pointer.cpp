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
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*>m;
        Node* temp = head;

        while (temp != NULL) {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        m.insert({NULL,NULL}); // for the case when temp->random not exist 
        temp = head;

        while (temp != NULL) {
           m[temp]->next = m[temp->next];
           m[temp]->random = m[temp->random];
           temp = temp->next;
        }

        return m[head];
    }
};