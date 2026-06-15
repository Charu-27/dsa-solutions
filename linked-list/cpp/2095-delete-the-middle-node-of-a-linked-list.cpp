// Problem: delete-the-middle-node-of-a-linked-list (LeetCode #2095)
// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Approach: Two Pointers (slow/fast) to find middle, then delete
// Time: O(n) | Space: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = slow->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
