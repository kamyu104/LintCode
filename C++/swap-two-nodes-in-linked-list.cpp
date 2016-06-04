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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = &dummy;
        ListNode *prev_node1{nullptr}, *prev_node2{nullptr};
        while (curr && curr->next) {
            if (curr->next->val == v1) {
                prev_node1 = curr;
            }
            if (curr->next->val == v2) {
                prev_node2 = curr;
            }
            if (prev_node1 && prev_node2) {
                auto node1 = prev_node1->next;
                auto node2 = prev_node2->next;
                auto node1_next = node1->next;
                auto node2_next = node2->next;
                if (node1->next == node2) {
                    prev_node1->next = node2;
                    node2->next = node1;
                    node1->next = node2_next;
                } else if (node2->next == node1) {
                    prev_node2->next = node1;
                    node1->next = node2;
                    node2->next = node1_next;
                } else {
                    prev_node1->next = node2;
                    node2->next = node1_next;
                    prev_node2->next = node1;
                    node1->next = node2_next;
                }
                break;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
