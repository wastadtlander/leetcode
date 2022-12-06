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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;

        ListNode *walk = head, *run = head->next, *link = head->next;

        while (walk->next && run->next) {
            walk->next = run->next;
            run->next = walk->next->next;
            walk = walk->next;
            run = run->next;
        }

        walk->next = link;

        return head;
    }
};
