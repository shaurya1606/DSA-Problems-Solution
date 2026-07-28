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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(curr != nullptr) {
           curr->next = prev;
           
           prev = curr;
           curr = nxt;
           if(nxt != nullptr) nxt = nxt->next;
        }

        return prev;
    }
};