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
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                slow = head;
                // Both pointers advance at the same time.
                while (slow != fast) {
                    slow = slow->next, fast = fast->next;
                }
                return slow;  // slow is the begin of cycle.
            }
        }
        return nullptr;  // No cycle.
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;

        // Slow and fast pointer only meet when there is a cycle.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Count length of the cycle.
                int L = 0;
                do {
                    slow = slow->next;
                    ++L;
                } while (slow != fast);

                // Fast pointer walks L steps ahead.
                fast = head;
                while (L--) {
                    fast = fast->next;
                }

                // The start of the cycle is the node they meet.
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }
        return nullptr;
    }
};
