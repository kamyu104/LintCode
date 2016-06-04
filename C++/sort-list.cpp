// Time:  O(nlogn)
// Space: O(logn)

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
     * @return: You should return the head of the sorted linked list,
     using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split linked list.
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        return mergeTwoLists(sortList(head), sortList(slow));
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
