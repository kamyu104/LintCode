// Time:  O(n)
// Space: O(h)

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
private:
    bool getNumber(const string &data, int *start, int *num) {
        if (data[*start] == '#') {
            *start += 2;  // Skip "# ".
            return false;
        }

        for (*num = 0; isdigit(data[*start]); ++(*start)) {
            *num = *num * 10 + data[*start] - '0';
        }
        ++(*start);  // Skip " ".

        return true;
    }

    void deserializeHelper(const string& data,
                           int *start,  TreeNode **root) {
        int num;
        if (!getNumber(data, start, &num)) {
            *root = nullptr;
            return;
        } else {
            *root = new TreeNode(num);
            deserializeHelper(data, start, &((*root)->left));
            deserializeHelper(data, start, &((*root)->right));
        }
    }

    void serializeHelper(const TreeNode *root, string *prev) {
        if (!root)  {
            prev->append("# ");
        } else {
            stringstream buffer;
            buffer << root->val << " ";
            prev->append(buffer.str());
            serializeHelper(root->left, prev);
            serializeHelper(root->right, prev);
        }
    }

public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string output;
        serializeHelper(root, &output);
        return output;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        TreeNode *root = nullptr;
        int start = 0;
        deserializeHelper(data, &start, &root);
        return root;
    }
};
