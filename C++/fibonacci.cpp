// Time:  O(n)
// Space: O(1)

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }

        int n_i = 1, n_i_1 = 1, n_i_2 = 0;
        for (int i = 2; i < n; ++i) {
            n_i = n_i_1 + n_i_2;
            n_i_2 = n_i_1;
            n_i_1 = n_i;
        }

        return n_i;
    }
};

