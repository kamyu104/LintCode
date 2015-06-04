// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // sort numbers
        sort(num.begin(), num.end(), [](const int &i, const int &j) {
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });

        // combine the numbers
        string max_num;
        for (auto& i : num) {
            max_num.append(to_string(i));
        }

        // special case: start with zero (e.g. [0, 0])
        if (max_num[0] == '0')  {
            return "0";
        }

        return max_num;
    }
};
