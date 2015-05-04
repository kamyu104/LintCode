// Time:  O(n * d), n is length of the string, d is size of the dictionary
// Space: O(d)

class Solution {
public:
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return an integer
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int rounds = 1;
        queue<string> que;
        que.push(start);
        unordered_set<string> visited;
        
        // BFS
        while(que.size() > 0) {
            int qSize = que.size();
            while(--qSize >= 0) {
                string w = que.front();
                que.pop();
                
                if (w == end) {
                    return rounds;
                }
                
                for (int i = 0; i < w.length(); ++i) {
                    char c = w[i]; // Keep the original character.
                    for(int j= 'a'; j <= 'z'; ++j) {
                        w[i] = j; // Change one character.
                        if (j != c && visited.count(w) == 0 && dict.count(w) == 1) {
                            que.push(w);
                            visited.insert(w); // Marked as visited.
                        }
                    }
                    w[i] = c; // Rollback.
                }
            }
            ++rounds;
        }
        
        return 0;
    }
};

class Solution2 {
public:
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return an integer
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int rounds = 1;
        queue<string> que;
        que.push(start);
        
        // BFS
        while(que.size() > 0) {
            int qSize = que.size();
            while(--qSize >= 0) {
                string w = que.front();
                que.pop();
                
                if (w == end) {
                    return rounds;
                }
                
                for (int i = 0; i < w.length(); ++i) {
                    char c = w[i]; // Keep the original character.
                    for(int j= 'a'; j <= 'z'; ++j) {
                        w[i] = j; // Change one character.
                        if (j != c && dict.count(w) == 1) {
                            que.push(w);
                            dict.erase(w); // Marked as visited.
                        }
                    }
                    w[i] = c; // Rollback.
                }
            }
            ++rounds;
        }
        
        return 0;
    }
};
