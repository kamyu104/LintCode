// Time:  O(n^3)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int len = nums.size();
        int left, right, sum;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                sum = target - nums[i] - nums[j];
                left = j + 1, right = len - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        res.emplace_back(move(vector<int>{nums[i], nums[j], nums[left], nums[right]}));
                        ++left, --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > sum) {
                            --right;
                        } else {
                            ++left;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Time:  O(n^2 * p), p is max number of the same two sum pairs.
// Space: O(n^2 * p)
class Solution2 {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end()); // Make sure quadruplets are in non-descending orders.
        unordered_map<int, vector<vector<size_t>>> two_sum; // two_sum saves "sum to (i, j) pairs, which i < j."
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                bool have_duplicate = false;
                for (const auto& vec : two_sum[nums[i] + nums[j]]) {
                    if (nums[vec.front()] == nums[i]) {  // Duplicated.
                        have_duplicate = true;
                        break;
                    }
                }
                if (!have_duplicate) {  // Not duplicated
                    vector<size_t> new_vec = {i, j};
                    two_sum[nums[i] + nums[j]].emplace_back(move(new_vec));
                }
            }
        }

        unordered_set<string> answers; // Use hash to filter duplicated.
        vector<vector<int>> res;
        for (size_t i = 2; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                auto it = two_sum.find(target - nums[i] - nums[j]);
                if (it == two_sum.end()) {
                    continue;
                }
                for (const auto& vec : it->second) {
                    if (vec.back() >= i) {
                        continue;
                    }
                    // {vec.front() < vec.back() < i < j}
                    vector<int> candidate = {nums[vec.front()], nums[vec.back()], nums[i], nums[j]};
                    if (answers.emplace(join_vector(candidate)).second) {  // Not duplicated.
                        res.emplace_back(move(candidate)); // Add to answers.
                    }
                }
            }
        }
        return res;
    }

    // Hash vector to string.
    string join_vector(const vector<int>& nums) {
        string ret;
        for (const auto& n : nums) {
            ret += to_string(n);
            ret += ' ';
        }
        return ret;
    }
};
