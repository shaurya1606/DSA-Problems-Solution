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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* it = head;

        unordered_map<ListNode*, int> mp;
    
        while(it) {
            mp[it]++;
            if(mp[it] > 1) return it;
            it = it->next;
        }

        return nullptr;
    }
};