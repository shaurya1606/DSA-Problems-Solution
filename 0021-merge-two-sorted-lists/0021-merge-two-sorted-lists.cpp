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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* it1 = list1;
        ListNode* it2 = list2;
        ListNode* it3 = head;

        while(it1 != nullptr && it2 != nullptr) {
            if(it1->val <= it2->val) {
                ListNode* temp = new ListNode(it1->val);
                if(head == nullptr) {
                    head = temp;
                    it3 = temp;
                    it1 = it1->next;
                    continue;
                }
                it3->next = temp;
                it3 = it3->next;
                it1 = it1->next;
            }
            else {
                ListNode* temp = new ListNode(it2->val);
                if(head == nullptr) {
                    head = temp;
                    it3 = temp;
                    it2 = it2->next;
                    continue;
                }
                it3->next = temp;
                it3 = it3->next;
                it2 = it2->next;
            }
        }
        while(it2 != nullptr) {
                ListNode* temp = new ListNode(it2->val);
                it3->next = temp;
                it3 = it3->next;
                it2 = it2->next;
            }
            while(it1 != nullptr) {
                ListNode* temp = new ListNode(it1->val);
                it3->next = temp;
                it3 = it3->next;
                it1 = it1->next;
            }
        return head;
    }
};