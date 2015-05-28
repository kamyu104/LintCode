// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        map<int, string, greater<int>> numeral_map = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, 
                                                      {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, 
                                                      {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, 
                                                      {1000, "M"}};
        string result;
        while (n > 0) {
            for (const auto& kvp : numeral_map){
                while (n / kvp.first > 0) {
                    n -= kvp.first;
                    result.append(kvp.second);
                }
            }
        }        
        return result;
    }
};
