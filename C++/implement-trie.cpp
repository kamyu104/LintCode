// Time:  O(n), per operation
// Space: O(1)

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():is_string(false) {
    }
    bool is_string;
    unordered_map<char, TrieNode *> leaves;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (const auto& c : word) {
            if (!cur->leaves.count(c)) {
                cur->leaves[c] = new TrieNode();
            }
            cur = cur->leaves[c];
        }
        cur->is_string = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = childSearch(word);
        if (node) {
            return node->is_string;
        }
        return false;   
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }

    TrieNode * childSearch(const string& word) {
        TrieNode *cur = root;
        for (const auto& c : word) {
            if (cur->leaves.count(c)) {
                cur = cur->leaves[c];
            } else {
                return nullptr;
            }
        }
        return cur;
    }

private:
    TrieNode* root;
};
