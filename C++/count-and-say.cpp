// Time:  O(n * 2^n)
// Space: O(2^n)

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string seq{"1"};
        for (int i = 0; i < n - 1; ++i) {
            seq = getNext(seq);
        }
        return seq;
    }

    string getNext(const string& seq) {
        stringstream  next_seq;
        for (int i = 0; i < seq.length(); ++i) {
            int cnt = 1;
            while (i < seq.length() - 1 && seq[i] == seq[i + 1]) {
                ++cnt, ++i;
            }
            next_seq << cnt << seq[i];
        }
        return next_seq.str();
    }
};
