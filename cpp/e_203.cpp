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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        while (head && head->val == val) head = head->next;
        ListNode* dummy = head;
        ListNode* del;
        while (dummy) {
            if (dummy->next && dummy->next->val == val) {
                del = dummy->next;
                dummy->next = dummy->next->next;
                delete del;
            } else {
                dummy = dummy->next;
            }
        }
        return head;
    }
};
