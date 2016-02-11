// Time:  O(n + k)
// Space: O(k)

// Wiki of KMP algorithm:
// http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source != nullptr && target != nullptr) {
            const string src(source), tgt(target);
            if (tgt.empty()) {
                return 0;
            }

            return KMP(src, tgt);
        }
        return -1;
    }

    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};


// Time:  O(n * k)
// Space: O(k)
class Solution2 {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source != nullptr && target != nullptr) {
            const string src(source), tgt(target);
            for (int i = 0; i < src.length() - tgt.length() + 1; ++i) {
                if (src.substr(i, tgt.length()) == tgt) {
                    return i;
                }
            }
        }
        return -1;
    }
};

