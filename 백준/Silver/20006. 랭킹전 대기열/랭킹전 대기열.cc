#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<pair<int, string>>> rooms; // 방 번호, {레벨, 닉네임}

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second < b.second;
}

int main() {
    int p, m;
    cin >> p >> m;

    for (int i = 0; i < p; i++) {
        int l;
        string n;
        cin >> l >> n;

        if (i == 0) { // 첫 유저
            rooms.push_back({{l, n}}); // 0번 방에 push
            //cout << i << "번 방에 입갤 " << l << " " << n << "\n";
        } else { // 이후 유저
            bool isEntered = false;
            for (int j = 0; j < rooms.size(); j++) // 첫 방부터 탐색 ㄱㄱ
            {
                auto& r = rooms[j];
                int firstLevel = r[0].first;
                if (l >= firstLevel - 10 && l <= firstLevel + 10 && r.size() < m) { // 레벨 범위 내, 자리 남음
                    r.push_back({l, n}); // 그 방에 넣으셈
                    isEntered = true;
                    //cout << j << "번 방에 입갤 " << l << " " << n << "\n";
                    break;
                }
            }

            // 못들어갔으면 새 방을 만들자
            if (!isEntered) {
                rooms.push_back({{l, n}}); 
                //cout << rooms.size()-1 << "번 방에 입갤 " << l << " " << n << "\n";
            }
        }
    }

    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].size() < m) { // 꽉 안찬 방
            cout << "Waiting!\n";
            sort(rooms[i].begin(), rooms[i].end(), cmp);
            for (auto &&r : rooms[i])
            {
                cout << r.first << " " << r.second << "\n";
            }
        } else { // 꽉찬 방
            cout << "Started!\n";
            sort(rooms[i].begin(), rooms[i].end(), cmp);
            for (auto &&r : rooms[i])
            {
                cout << r.first << " " << r.second << "\n";
            } 
        }
    }
    
    return 0;
    
}