// Time:  O(n), n is the lengh of the linked list.
// Space: O(1)

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        auto slow = head, fast = head;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
