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
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        ListNode *prev = &dummy;
        
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode *head2 = prev;
        
        prev = prev->next;
        ListNode *cur = prev->next;
        
        for (int i = m; i < n; ++i) {
            prev->next = cur->next;  // remove cur from the list
            cur->next = head2->next; // add cur to the head
            head2->next = cur;       // add cur to the head
            cur = prev->next;        // get next cur
        }
        
        return dummy.next;
    }
};
