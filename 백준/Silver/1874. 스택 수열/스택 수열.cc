#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> S;
int pushCount = 1; // 다음에 넣을 숫자
vector<string> result; // 연산자 저장 벡터
bool stop = false; // NO 인 경우가 나오면 true

void checkStack(int k) {
    // 비어있을 때
    if (S.empty()) { 
        S.push(pushCount);
        result.push_back("+");
        pushCount++;
    }

    // '1 2 5 3 4' case 에서, checkStack(3) 호출하면 top()==4 인 상태일 때 "NO"
    if (S.top() > k) { 
        stop = true;
        return;
    }

    while (S.top() <= k) {
        if (S.top() == k) {
            result.push_back("-");
            S.pop();
            break;
        } else {
            if (pushCount > n) {
                stop = true;
                return;
            }
            result.push_back("+");
            S.push(pushCount);
            pushCount++;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        checkStack(k);
    }

    if (stop) {
        cout << "NO" << '\n';
    } else {
        for (auto &&i : result)
        {
            cout << i << '\n';
        }
    }
    

    return 0;
}