#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string makeString(int n) {
    string str;
    for (int i = 0; i < pow(3, n); i++) {
        str.push_back('-'); // 3^n 개 만큼의 '-' 스트링
    }
    return str;
}

void insertBlank(string& s, int start, int length) {
    for (int i = 0; i < length; i++) {
        s[start + i] = ' '; // start~ length만큼 공백으로 대체
    }
}

void cantor(int n, int idx, string& s) { // index 0부터 시작
    if (idx == n) {
        cout << s << endl;
        return;
    }

    int unit = pow(3, idx); // 각 단계의 공백 갯수
    int cut = pow(3, n - idx - 1);
    for (int i = 0; i < cut; i++) {
        insertBlank(s, unit + i * 3 * unit, unit);
    }
    cantor(n, idx + 1, s);
}

int main() {
    int n;

    while (cin >> n) {
        string s = makeString(n);
        cantor(n, 0, s);
    }

    return 0;
}
