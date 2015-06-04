// Time:  O(n)
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Creates a dummy head.
        ListNode * dummy_head = new ListNode(INT_MIN);
        auto tail = dummy_head;

        while (l1 && l2) {
            AppendNode(l1->val < l2->val ? &l1 : &l2, &tail);
        }

        if (l1) {
            // Appends the remaining nodes of l1.
            AppendNode(&l1, &tail);
        } else if (l2) {
            // Appends the remaining nodes of l2.
            AppendNode(&l2, &tail);
        }
        return dummy_head->next;
    }

    void AppendNode(ListNode ** node,
                    ListNode ** tail) {
        (*tail)->next = *node;
        *tail = *node;  // Resets tail to the last node.
        *node = (*node)->next;
    }
};
