#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;

void check(string S) {
    size_t idx = S.find("push");
    int len = S.length();
    if (idx != string::npos) {
        string temp = S.substr(idx+5, len);
        int val = stoi(temp);
        Q.push(val);
    } else if (S == "pop") { 
        if (Q.empty()) {
            cout << -1 << endl;
        } else {
            cout << Q.front() << endl;
            Q.pop();
        }
    } else if (S == "size") {
        cout << Q.size() << endl;
    } else if (S == "empty") {
        if (Q.empty()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else if (S == "front") {
        if (Q.empty()) {
            cout << -1 << endl;
        } else {
            cout << Q.front() << endl;
        }
    } else if (S == "back") {
        if (Q.empty()) {
            cout << -1 << endl;
        } else {
            cout << Q.back() << endl;
        }
    } 
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        string S;
        getline(cin, S);
        check(S);
    }

    return 0;
    
}