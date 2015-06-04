// Time:  O(n)
// Space: O(n)

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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        const int old_size = hashTable.size();
        const int new_size = old_size * 2;
        if (old_size == 0) {
            return hashTable;
        }
        vector<ListNode*> rehashTable(new_size, nullptr);
        for (int i = 0; i < old_size; ++i) {
            if (hashTable[i] != nullptr) {
                rehash(hashTable, rehashTable, i);
            }
        }
        return rehashTable;
    }

    void rehash(vector<ListNode*>& hashTable, vector<ListNode*>& rehashTable, int i) {
        const int new_size = rehashTable.size();
        ListNode *curr = hashTable[i];
        while (curr != nullptr) {
            int val = curr->val;
            int new_pos = (val % new_size + new_size) % new_size;
            if (rehashTable[new_pos] == nullptr) {
                rehashTable[new_pos] = new ListNode(val);
            }
            else {
                ListNode *tmp = rehashTable[new_pos];
                while (tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                tmp->next = new ListNode(val);
            }
            curr = curr->next;
        }
    }
};

