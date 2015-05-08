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
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // split linked list
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        
        return mergeList(sortList(head), sortList(slow)); // merge sorted list
    }
    
private:
    ListNode *mergeList(ListNode *list1, ListNode *list2) {
        ListNode dummy(INT_MIN);
        dummy.next = nullptr;
        ListNode *head = &dummy;
        
        for (;list1 && list2; head = head->next) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
        }
        
        if (list1) {
            head->next = list1;
        } else if (list2) {
            head->next = list2;
        }
        
        return dummy.next;
    }
};



