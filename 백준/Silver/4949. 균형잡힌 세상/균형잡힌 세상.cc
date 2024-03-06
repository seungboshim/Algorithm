#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    while(true) {
        string s;
        getline(cin, s);
        if (s == ".") { 
            break;
        }

        stack<char> bracket;
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char curr = s[i];
            if (curr == '(') {
                bracket.push('(');
            }
            if (curr == ')') {
                if (!bracket.empty() && bracket.top() == '(') {
                    bracket.pop();
                } else {
                    bracket.push(')');
                }
            }

            if (curr == '[') {
                bracket.push('[');
            }
            if (curr == ']') {
                if (!bracket.empty() && bracket.top() == '[') {
                    bracket.pop();
                } else {
                    bracket.push(']');
                }
            }
        }

        if (bracket.empty()) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
        
    }
    
}