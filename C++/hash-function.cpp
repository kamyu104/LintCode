// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        long long value = 0L;
        for (const auto& c : key) {
            value = value * 33L % HASH_SIZE;
            value = (value + static_cast<const long long>(c) % HASH_SIZE) % HASH_SIZE;
        }
        return static_cast<int>(value);
    }
};
