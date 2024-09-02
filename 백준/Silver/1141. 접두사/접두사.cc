#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end()); // 정렬 ㄱㄱ
    // h hello hi rerun run running
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cnt++; // 첫번째 단어
        } else {
            if (words[i].find(words[i - 1]) == 0) { // 다른것의 접두사인것
                continue;
            } else {
                cnt++;
            }
        }
    }  
    cout << cnt << '\n';
    return 0;
}