// Time:  O(m + n)
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto currA = headA, currB = headB;
        ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
        while (currA && currB) {
            if (currA == currB) {
                begin = currA;
                break;
            }
   
            if (currA->next) {
                currA = currA->next;
            } else if (!tailA) {
                tailA = currA;
                currA = headB;
            } else {
                break;
            }

            if (currB->next) {
                currB = currB->next;
            } else if (!tailB) {
                tailB = currB;
                currB = headA;
            } else {
                break;
            }
        }
        
        return begin;
    }
};
