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
        int L = 1;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        
        // Slow and fast pointer only meet when there is a cycle.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Count length of the cycle.
                slow = slow->next;
                while (slow != fast) {
                    slow = slow->next;
                    ++L;
                }
                
                // Fast pointer walks L steps ahead.
                fast = dummy;
                while (L > 0) {
                    fast = fast->next;
                    --L;
                }
                
                // The start of the cycle is the node they meet.
                slow = dummy;
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



