// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> longest_words;
        for (const auto& word : dictionary) {
            if (!longest_words.empty() &&
                word.length() > longest_words[0].length()) {
                longest_words = move(vector<string>{word});
            } else if (longest_words.empty() ||
                       word.length() == longest_words[0].length()) {
                longest_words.emplace_back(word);
            }
        }
        return longest_words;
    }
};
