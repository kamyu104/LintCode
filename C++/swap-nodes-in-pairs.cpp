// Time:  O(n)
// Space: O(1)

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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(numeric_limits<int>::min());
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode *next_one = cur->next;
            ListNode *next_two = next_one->next;
            ListNode *next_three = next_two->next;
            cur->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            cur = next_one;
        }
        return dummy.next;
    }
};
