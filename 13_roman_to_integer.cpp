#include <iostream>
#include <map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int> symbols = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        int result = 0;
        for (auto i = s.begin(); i != s.end(); ++i) {
            if ((i + 1) != s.end() && symbols[*i] < symbols[*(i + 1)]) {
                result -= symbols[*i];
            } else {
                result += symbols[*i];
            }
        }
        return result;
    }
};

int main() {
    std::cout << (new Solution())->romanToInt("MCMXCIV");
    return 0;
}