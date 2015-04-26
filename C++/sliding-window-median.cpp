#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        deque<int> window;
        for (int i = 0; i < k; ++i) {
            insert(window, nums[i]);
        }

        
        vector<int> ans;
        int x;
        int prev = nums[0];
        for (int i = k; i < nums.size(); ++i) {
            //cout << "erase " << prev << endl;
            erase(window, prev);
            //cout << "insert " << nums[i] << endl;
            insert(window, nums[i]);
            /*for (auto i : window) {
                cout << " " << i;
            }
            cout << endl;
*/
            ans.emplace_back(window[(k - 1) / 2]);
            prev = nums[i + 1 - k];
        }
        
        return ans;
    }
    
    void insert(deque<int>& window, int x) {
        int left = 0;
        int right = window.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (window[mid] > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
            
        }
        if(left == window.size()) {
            window.emplace_back(x);
        } else {
            window.insert(window.begin() + left, x);
        }
    }
    
    void erase(deque<int>& window, int x) {
        int left = 0;
        int right = window.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (window[mid] >= x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
            
        }
        window.erase(window.begin() + left);
    }
};

int main() {
    vector<int> nums{1,2,7,7,2};
    Solution().medianSlidingWindow(nums, 3);
    return 0;
}

