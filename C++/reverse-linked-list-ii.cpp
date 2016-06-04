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

        auto prev = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        auto head2 = prev;
        prev = prev->next;
        auto curr = prev->next;
        for (int i = m; i < n; ++i) {
            prev->next = curr->next;  // Remove curr from the list.
            curr->next = head2->next; // Add curr to the head.
            head2->next = curr;       // Add curr to the head.
            curr = prev->next;        // Get next curr.
        }

        return dummy.next;
    }
};
