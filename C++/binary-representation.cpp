// Time:  O(1)
// Space: O(1)

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        int int_part = atoi(n.substr(0, n.find('.')).c_str());
        double dec_part = atof(n.substr(n.find('.')).c_str());
        string int_str = "";
        string dec_str = "";
        
        if (int_part == 0) {
            int_str.push_back('0');
        }
        
        while (int_part > 0) {
            int c = int_part % 2;
            int_str.push_back('0' + c);
            int_part = int_part >> 1;
        }
        reverse(int_str.begin(), int_str.end());
        
        while (dec_part > 0.0) {
            if (dec_str.length() > 32) {
                return "ERROR";
            }
            double r = dec_part * 2;
            if (r >= 1.0) {
                dec_str.push_back('1');
                dec_part = r - 1.0;
            }
            else {
                dec_str.push_back('0');
                dec_part = r;
            }
        }
        return dec_str.length() > 0? int_str + "." + dec_str : int_str;
    }
};

