#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(string W, int K) {
    vector<int> alphabet[26];
    for (int i = 0; i < W.length(); i++) {
        alphabet[W[i] - 'a'].push_back(i); // 각 알파벳 위치 저장
    }
    
    int minStrLength = 10001;
    int maxStrLength = 0;
    for (int i = 0; i < 26; i++)
    {
        int freq = alphabet[i].size();
        if (freq == K) { // K번 나온 알파벳
            // cout << char(i+65) << "는 " << freq << "번 나왔습니다." << '\n';
            // for (auto &&i : alphabet[i]) {
            //     cout << i << " ";
            // } cout << '\n';
            
            minStrLength = min(minStrLength, alphabet[i][freq - 1] - alphabet[i][0] + 1);
            maxStrLength = max(maxStrLength, alphabet[i][freq - 1] - alphabet[i][0] + 1);
        } else if (freq > K) { // K번 이상 나온 알파벳
            // cout << char(i+65) << "는 " << freq << "번 나왔습니다." << '\n';
            // for (auto &&i : alphabet[i]) {
            //     cout << i << " ";
            // } cout << '\n';
            
            for (int j = 0; j <= freq - K; j++) { // K개 넘기는 경우, K개씩 앞에서부터 묶어서 최소값 최대값 찾기
                // cout << "확인 window: " << alphabet[i][j] << " ~ " << alphabet[i][j + K - 1] << '\n';
                minStrLength = min(minStrLength, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
                maxStrLength = max(maxStrLength, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
                // cout << "min: " << minStrLength << " max: " << maxStrLength << '\n';
            }
        } else {
            continue;
        }
    }

    if (minStrLength == 10001) {
        cout << -1 << '\n';
    } else {
        cout << minStrLength << ' ' << maxStrLength << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string W;
        int K;
        cin >> W >> K;
        solution(W, K);
    }
    return 0;
}