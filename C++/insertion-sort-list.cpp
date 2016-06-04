// Time:  O(n^2)
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
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy{numeric_limits<int>::min()};

        auto curr = head;
        ListNode *position = nullptr;

        while (curr) {
            position = findInsertPosition(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = position->next;
            position->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (auto curr = head; curr && curr->val <= x;
             prev = curr, curr = curr->next);
        return prev;
    }
};
