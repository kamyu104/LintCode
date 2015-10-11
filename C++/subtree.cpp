// Time:  O(m * n), n is number of the nodes in larger tree, m is number of the nodes in smaller one.
// Space: O(1)

/**
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
 
 // Morris Traversal (Preorder) if the data of the tree nodes could be modified.
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (!T2) {
            return true;
        }
        bool found = false;
        TreeNode *curr = T1;
        while (curr) {
            if (!curr->left) {
                if (!found && isSameTree(curr, curr, T2)) {
                    found = true;
                }
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                // Traverse the left child if only if the subtree is not found.
                if (!found && !node->right) {
                    if (isSameTree(curr, curr, T2)) {
                        found = true;
                    }
                    node->right = curr;
                    curr = curr->left;
                } else {
                    // Rollback the modification.
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        // Complete the traversal to rollback the modification due to Morris Traversal.
        return found;
    }

    bool isSameTree(const TreeNode *T1_root,
                    const TreeNode *T1, const TreeNode *T2) {

        if (!T1 && !T2) {
            return true;
        }

        if (T1 && T2) {
            return T1->val == T2->val &&
                   isSameTree(T1_root, T1->left, T2->left) &&
                   isSameTree(T1_root, realRightChild(T1), T2->right);
        }

        return false;
    }
    
    // Treat the right child as nullptr if it has been used for
    // Morris Traversal.
    TreeNode *realRightChild(const TreeNode *curr) {
        TreeNode* curr_right = curr ? curr->right : nullptr;
        if (curr_right && curr_right->left) {
            TreeNode *node = curr_right->left;
            while (node->right && node->right != curr_right) {
                node = node->right;
            }
            if (node->right) {
                curr_right = nullptr;
            }
        }
        return curr_right;
    }
};

// Time:  O(m * n)
// Space: O(h)
class Solution2 {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (!T2) {
            return true;
        } else if (!T1) {  // !T1 && T2
            return false;
        } else {  // T1 && T2
            return isSameTree(T1, T2) ||
                   isSubtree(T1->left, T2) ||
                   isSubtree(T1->right, T2);
        }

    }

    bool isSameTree(TreeNode *T1, TreeNode *T2) {
        if (!T1 && !T2) {
            return true;
        }

        if (T1 && T2) {
            return T1->val == T2->val &&
                   isSameTree(T1->left, T2->left) &&
                   isSameTree(T1->right, T2->right);
        }

        return false;
    }
};
