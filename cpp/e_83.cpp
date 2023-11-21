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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        while (head) {
            s.insert(head->val);
            head = head->next;
        }
        ListNode* ret = new ListNode();
        ListNode* dummy = new ListNode();
        ret = dummy;
        for (int n : s) {
            dummy->next = new ListNode();
            dummy->next->val = n;
            dummy = dummy->next;
        }
        return ret->next;
    }
};
