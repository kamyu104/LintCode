// Time:  O(n)
// Space: O(1)

/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        ListNode *dummy_head = new ListNode(INT_MIN);

        while (head != nullptr) {
            ListNode *tmp = head->next;
            head->next = dummy_head->next;
            dummy_head->next = head;
            head = tmp;
        }

        return dummy_head->next;
    }
};

