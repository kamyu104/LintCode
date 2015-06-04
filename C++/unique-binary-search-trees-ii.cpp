// Time:  O(n * 4^n / n^(3/2)) ~= Catalan numbers
// Space: O(n)

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
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> output;
        if (start > end) {
            output.emplace_back(nullptr);
            return output;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftSubTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightSubTrees = generateTrees(i + 1, end);
            for (const auto& left : leftSubTrees) {
                for (const auto& right : rightSubTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = clone(left);
                    root->right = clone(right);
                    output.emplace_back(root);
                }
            }

        }
        return output;
    }

    TreeNode *clone(TreeNode *root) {
        TreeNode *newRoot = nullptr;

        if (root) {
            newRoot = new TreeNode(root->val);
            newRoot->left = clone(root->left);
            newRoot->right = clone(root->right);
        }

        return newRoot;
    }
};
