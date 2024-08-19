#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[200001] = {0};
int cnt[100001] = {0}; // 각 숫자 빈도수 저장

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        cnt[arr[i]]++;
        end = i;

        while (cnt[arr[i]] > K) { // 중복된 숫자가 K개 넘김
            cnt[arr[start]]--; // 시작포인터 빼기
            start++; // 시작포인터 이동
        }
        answer = max(answer, end - start + 1);
    }
    cout << answer << '\n';
    return 0;
}