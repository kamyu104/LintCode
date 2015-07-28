// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            ++number_to_count[A[i]];
            for (const auto& kvp : number_to_count) {
                if (kvp.first >= A[i]) {
                    break;
                } 
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        unordered_map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            unordered_map<int, int> successor_to_count;
            ++number_to_count[A[i]];
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successor_to_count[A[j]];
                }
            }
            for (const auto& kvp : successor_to_count) {
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};

// Time:  O(n^3)
// Space: O(n)
class Solution3 {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        unordered_map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            unordered_map<int, int> successor_to_count;
            ++number_to_count[A[i]];
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successor_to_count[A[j]];
                }
            }
            for (const auto& kvp : successor_to_count) {
                --number_to_count[kvp.first];
                index += combination(number_to_count);
                ++number_to_count[kvp.first];
            }
        }
        return index;
    }

    long long combination(const unordered_map<int, int>& number_to_count) {
        int n = 0;
        for (const auto& kvp : number_to_count) {
            n += kvp.second;
        }
        long long count = 1;
        for (const auto& kvp : number_to_count) {
            // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
            for (int i = 1; i <= kvp.second; ++i, --n) {
                 count = count * n / i;
            }
        }
        return count;
    }
};
