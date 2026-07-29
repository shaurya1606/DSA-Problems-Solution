/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node* curr = head;

        while(curr) {
            if(!curr->child) {
                curr = curr->next;
                continue;
            }

            if(curr->child) {
                Node* currChild = curr->child;

                currChild->prev = curr;

                while(currChild->next){
                    currChild = currChild->next;
                }

                currChild->next = curr->next;
                if (curr->next) curr->next->prev = currChild;
            }

            curr->next = curr->child;
            curr->child = nullptr;
            curr = curr->next;
        }
        return head;
    }
};