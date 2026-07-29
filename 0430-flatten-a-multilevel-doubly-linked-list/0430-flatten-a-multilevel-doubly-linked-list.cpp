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
        if (head == nullptr) return nullptr;

        stack<Node*> st;
        Node* tail = head;

        while (tail) {
            if (tail->child) {
                if(tail->next) st.push(tail->next);
                tail->child->prev = tail;
                tail->next = tail->child;
                tail->child = nullptr;
            }
            else if (tail->next == nullptr && !st.empty()) {
                tail->next = st.top();
                st.top()->prev = tail;
                st.pop();
            }

            tail = tail->next;
        }

        return head;
    }
};