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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numsLookup(nums.begin(), nums.end());
        int count = 0;
        bool inList = false;
        while (head) {
            if (numsLookup.count(head->val)) {
                if (!inList) {
                    count++;
                    inList = true;
                }    
            } else {
                inList = false;
            }
            head = head->next;
        }
        return count;
    }
};
