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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy{0};
        dummy.next = head;
        auto prev = &dummy, curr = dummy.next;
        
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
