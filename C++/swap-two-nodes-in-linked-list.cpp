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
        ListNode *cur = &dummy;
        ListNode *pre_node1{nullptr}, *pre_node2{nullptr};
        while (cur && cur->next) {
            if (cur->next->val == v1) {
                pre_node1 = cur;
            }
            if (cur->next->val == v2) {
                pre_node2 = cur;
            }
            if (pre_node1 && pre_node2) {
                auto *node1 = pre_node1->next;
                auto *node2 = pre_node2->next;
                auto *node1_next = node1->next;
                auto *node2_next = node2->next;
                if (node1->next == node2) {
                    pre_node1->next = node2;
                    node2->next = node1;
                    node1->next = node2_next;
                } else if (node2->next == node1) {
                    pre_node2->next = node1;
                    node1->next = node2;
                    node2->next = node1_next;
                } else {
                    pre_node1->next = node2;
                    node2->next = node1_next;
                    pre_node2->next = node1;
                    node1->next = node2_next;
                }
                break;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
