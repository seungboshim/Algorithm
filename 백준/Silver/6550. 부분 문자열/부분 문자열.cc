#include <iostream>
#include <string>
using namespace std;

bool checkSubString(string s, string t) {
    
    int i = 0;
    int j = 0;

    while (i <= t.size()) {
        if (j == s.size()) {
            return true;
        }

        if (s[j] == t[i]) {
            j++;
            i++;
            continue;
        } else {
            i++;
            continue;
        }
    }
    
    return false;
}

int main() {
    string s, t;

    while (cin >> s >> t) {
        if (checkSubString(s, t) == true) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    
    return 0;
}
