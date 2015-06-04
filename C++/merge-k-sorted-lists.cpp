// Time:  O(n * logk)
// Space: O(k)

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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;

        // Use min heap to keep the smallest node of each list
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (const auto& n : lists) {
            if (n != nullptr) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // Get min of k lists.
            ListNode *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }

    struct Compare {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
};



