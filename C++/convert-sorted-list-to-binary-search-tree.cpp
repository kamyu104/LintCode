// Time:  O(n)
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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *L) {
        auto curr = L;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return BuildBSTFromSortedDoublyListHelper(&L, 0, n);
    }

    // Builds a BST from the (s + 1)-th to the e-th node in L, and returns the
    // root. Node numbering is from 1 to n.
    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **L, int s, int e) {
        if (s >= e) {
            return nullptr;
        }

        int m = s + ((e - s) / 2);
        TreeNode *left = BuildBSTFromSortedDoublyListHelper(L, s, m);
        TreeNode *curr = new TreeNode((*L)->val);  // The last function call sets L to the successor of the
                                                   // maximum node in the tree rooted at left.
        *L = (*L)->next;
        curr->left = left;
        curr->right = BuildBSTFromSortedDoublyListHelper(L, m + 1, e);
        return curr;
    }
};
