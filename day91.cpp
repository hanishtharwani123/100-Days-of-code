// 91. Decode String
#include <string>
#include <stack>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> countStack;
        std::stack<std::string> resultStack;

        std::string currentString;
        int currentCount = 0;

        for (char ch : s) {
            if (std::isdigit(ch)) {
                currentCount = currentCount * 10 + (ch - '0');
            } else if (ch == '[') {
                countStack.push(currentCount);
                resultStack.push(currentString);
                currentCount = 0;
                currentString.clear();
            } else if (ch == ']') {
                int count = countStack.top();
                countStack.pop();

                std::string temp = currentString;
                for (int i = 1; i < count; ++i) {
                    currentString += temp;
                }

                currentString = resultStack.top() + currentString;
                resultStack.pop();
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string s = "3[a]2[bc]";
    std::string result = solution.decodeString(s);

    return 0;
}
