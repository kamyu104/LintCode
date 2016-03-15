// Time:  O(n)
// Space: O(1)

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy{0};
        dummy.next = head;

        auto *prev = &dummy;

        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        auto *head2 = prev;

        prev = prev->next;
        auto *cur = prev->next;

        for (int i = m; i < n; ++i) {
            prev->next = cur->next;  // Remove cur from the list.
            cur->next = head2->next; // Add cur to the head.
            head2->next = cur;       // Add cur to the head.
            cur = prev->next;        // Get next cur.
        }

        return dummy.next;
    }
};
