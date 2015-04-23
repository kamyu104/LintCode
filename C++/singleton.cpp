// Time:  O(1)
// Space: O(1)

// Thread-Safe, Lazy Initilization
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution *instance = new Solution();
        return instance;
    }
private:
    Solution() {}
};