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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        DoublyListNode *prev = nullptr, *head = nullptr;
        treeToDoublyList(root, &prev, &head);
        return head;
    }

    void treeToDoublyList(TreeNode *p, DoublyListNode **prev, DoublyListNode **head) {
      if (!p) {
          return;
      }
      treeToDoublyList(p->left, prev, head);
      DoublyListNode *root = new DoublyListNode(p->val);
      if (!*prev) {
          *head = root;
      } else {
          root->prev = *prev;
          (*prev)->next = root;
      }
      *prev = root;
      treeToDoublyList(p->right, prev, head);
    }
};
