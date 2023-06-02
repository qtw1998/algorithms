//#include <stack>
#include <iostream>
#include <string>
#include "../LinearStructures/ArrayStack.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        ArrayStack<char> tmp;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                tmp.push(s[i]);
            } else {
                if (tmp.isEmpty()) return false;
                char top = tmp.peek();
                if (top == '{' && s[i] != '}') return false;
                if (top == '[' && s[i] != ']') return false;
                if (top == '(' && s[i] != ')') return false;
                tmp.pop();
            }
        }

        return tmp.isEmpty();
    }
};

int main() {
    cout << (new Solution())->isValid("()[]{}");
}