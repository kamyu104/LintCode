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
        return deserializeHelper(data, &start);
    }

private:
    bool getNumber(const string &data, int *start, int *num) {
        int sign = 1;
        if (data[*start] == '#') {
            *start += 2;  // Skip "# ".
            return false;
        } else if (data[*start] == '-') {
            sign = -1;
            ++(*start);
        }

        for (*num = 0; isdigit(data[*start]); ++(*start)) {
            *num = *num * 10 + data[*start] - '0';
        }
        *num *= sign;
        ++(*start);  // Skip " ".

        return true;
    }

    void serializeHelper(const TreeNode *root, string *prev) {
        if (!root)  {
            prev->append("# ");
        } else {
            prev->append(to_string(root->val).append(" "));
            serializeHelper(root->left, prev);
            serializeHelper(root->right, prev);
        }
    }

    TreeNode *deserializeHelper(const string& data, int *start) {
        int num;
        if (!getNumber(data, start, &num)) {
            return nullptr;
        } else {
            TreeNode *root = new TreeNode(num);
            root->left = deserializeHelper(data, start);
            root->right = deserializeHelper(data, start);
            return root;
        }
    }
};


// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        istringstream in(data);  // Space: O(n)
        return deserializeHelper(in);
    }

private:
    void serializeHelper(const TreeNode *root, ostringstream& out) {
        if (!root)  {
            out << "# ";
        } else {
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
    }

    TreeNode *deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(in);
            root->right = deserializeHelper(in);
            return root;
        }
    }
};
