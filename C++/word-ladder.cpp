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
        unordered_map<string, unordered_set<string>> trace;

        // BFS, each round is a level
        unordered_set<string> levels[2];
        int cur_level = 0;

        levels[cur_level].emplace(start);
        while (dict.size() > 0 && levels[cur_level % 2].size() > 0) {
            // end is in current level, stop
            if (trace.count(end) == 1) {
                ++cur_level;
                break;
            }

            // clear words from the dictionary to avoid it' apear in future level again
            for (const auto& word : levels[cur_level % 2]) {
                dict.erase(word);
            }

            levels[(cur_level + 1) % 2].clear();
            for (const auto& from : levels[cur_level % 2]) {
                string new_word = from;
                for (int i = 0; i < new_word.length(); i++) {
                    char orig_c = from[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        new_word[i] = c;
                        if (dict.count(new_word) == 1) {
                            trace[new_word].emplace(from);
                            levels[(cur_level + 1) % 2].emplace(new_word);
                        }
                    }
                    new_word[i] = orig_c;
                }
            }

            ++cur_level;
        }

        return cur_level;
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
        vector<vector<string>> level(2, vector<string>());
        level[rounds % 2].emplace_back(start);
        unordered_set<string> visited;

        // BFS
        while (level[rounds % 2].size() > 0) {
            for (auto& word : level[rounds % 2]) {
                if (word == end) {
                    return rounds;
                }

                for (int i = 0; i < word.length(); ++i) {
                    for (int j= 'a'; j <= 'z'; ++j) {
                        string candidate(word);
                        candidate[i] = j; // Change one character.
                        if (visited.count(candidate) == 0 && dict.count(candidate) == 1) {
                            level[(rounds + 1) % 2].emplace_back(candidate);
                            visited.emplace(candidate); // Marked as visited
                        }
                    }
                }
            }
            level[rounds % 2].clear();
            ++rounds;
        }

        return 0;
    }
};

class Solution3 {
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
        que.emplace(start);
        unordered_set<string> visited;

        // BFS
        while (que.size() > 0) {
            int qSize = que.size();
            while (--qSize >= 0) {
                string w = que.front();
                que.pop();

                if (w == end) {
                    return rounds;
                }

                for (int i = 0; i < w.length(); ++i) {
                    char c = w[i]; // Keep the original character.
                    for (int j= 'a'; j <= 'z'; ++j) {
                        w[i] = j; // Change one character.
                        if (j != c && visited.count(w) == 0 && dict.count(w) == 1) {
                            que.emplace(w);
                            visited.emplace(w); // Marked as visited.
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
        que.emplace(start);

        // BFS
        while (que.size() > 0) {
            int qSize = que.size();
            while (--qSize >= 0) {
                string w = que.front();
                que.pop();

                if (w == end) {
                    return rounds;
                }

                for (int i = 0; i < w.length(); ++i) {
                    char c = w[i]; // Keep the original character.
                    for (int j= 'a'; j <= 'z'; ++j) {
                        w[i] = j; // Change one character.
                        if (j != c && dict.count(w) == 1) {
                            que.emplace(w);
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
