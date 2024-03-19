#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;

void checkStr(string str) {
    size_t pos = str.find(" ");
    if (pos != string::npos) {
        int val = stoi(str.substr(pos+1));
        s.push(val);
    } else if (str == "pop") {
        if (s.empty()) {
            cout << "-1" << endl;
        } else {
            cout << s.top() << endl;
            s.pop();
        }
    } else if (str == "size") {
        cout << s.size() << endl;
    } else if (str == "empty") {
        if (s.empty()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else if (str == "top") {
        if (s.empty()) {
            cout << "-1" << endl;
        } else {
            cout << s.top() << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i <= T; i++)
    {
        string str;
        getline(cin, str);
        checkStr(str);
    }
    
    return 0;
}