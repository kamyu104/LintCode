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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = head, curr_dummy = &dummy;
        int length = 0;

        while (curr) {
            ListNode *next_curr = curr->next;
            length = (length + 1) % k;

            if (length == 0) {
                ListNode *next_dummy = curr_dummy->next;
                reverse(&curr_dummy, curr->next);
                curr_dummy = next_dummy;
            }
            curr = next_curr;
        }
        return dummy.next;
    }

    void reverse(ListNode **begin, const ListNode *end) {
        auto first = (*begin)->next, curr = first->next;

        while (curr != end) {
            first->next = curr->next;
            curr->next = (*begin)->next;
            (*begin)->next = curr;
            curr = first->next;
        }
    }
};
