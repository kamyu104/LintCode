// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
            return to_string(i) + to_string(j) < to_string(j) + to_string(i);
        });

        string min_num;
        for (const auto& i : nums) {
            min_num.append(to_string(i));
        }

        int i = 0;
        while (i + 1 < min_num.length() && min_num[i] == '0')  {
            ++i;
        }
        
        return min_num.empty() ? "0" : min_num.substr(i);
    }
};
