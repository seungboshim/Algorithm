#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, w, L;
    cin >> n >> w >> L;
    vector<int> truck(n);
    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }
    queue<int> q;
    int time = 0, weight = 0;
    for(int t: truck) {
        while (true) {
            if (q.size() == w) { // 다리 풀방
                weight -= q.front(); // 앞에꺼 보내고 뒤에꺼 추가
                q.pop();
            }
            if (weight + t <= L) { // 다리에 추가 가능
                break;
            }
            q.push(0); // 추가 불가능
            time++;
        }
        q.push(t);
        weight += t;
        time++;

    }
    cout << time + w << '\n';
    return 0;
}