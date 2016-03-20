// Time:  O(1)
// Space: O(1)

// Thread-Safe, Lazy Initilization
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // C++ 11 thread-safe local-static-initialization. (lazy initialization)
        static Solution *instance = new Solution();

        return instance;
    }

    // Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;

private:
    Solution() {}
    ~Solution() {}
};
