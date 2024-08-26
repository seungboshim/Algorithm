#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int countA = 0; // 한곳으로 몰아야 하는 a의 갯수
    int ans = 1000;
    for (auto &&i : s)
    {
        if (i == 'a') countA++;
    }

    for (int i=0; i<s.size(); i++) {
        int cnt = countA; // 복사 안하니까 안댐;; 왜냐면 루프돌때마다 countA로 초기화해야지 ㄹㅇ 이걸30분동안붙잡은멍청이
        int countB = 0;
        for (int j=i; j<i+s.size(); j++) { // s 크기만큼 슬라이딩 윈도우
            if (cnt == 0) break;

            if (s[j%s.size()] == 'b') {
                countB++;
                cnt--;
            } else cnt--;
        }
        ans = min(ans, countB);
    }


    cout << ans << '\n';
    return 0;
}