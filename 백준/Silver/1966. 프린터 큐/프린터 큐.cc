#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int range, key;
        cin >> range >> key; 
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int cnt = 0;

        for (int j = 0; j < range; j++)
        {
            int value; 
            cin >> value;
            q.push({j, value}); // 인덱스, 중요도
            pq.push(value);
        }

        int curr = 0;
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();

            if (temp.second < pq.top()) {
                q.push(temp);
            } else if (temp.second == pq.top()) {
                cnt++;
                pq.pop();
                if (temp.first == key) {
                    break;
                }
            }
        }
        
        cout << cnt << endl;
    }
    
}