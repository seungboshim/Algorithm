#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> V;
    unordered_map<int, int> map;

    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        V.push_back(temp);
        map[temp]++; // {temp, 빈도수} 저장
    }

    vector<pair<int, int>> freq; // 빈도수 정렬용 벡터
    for (auto &&it : map)
    {
        freq.push_back({it.first, it.second});
    }
    sort(freq.begin(), freq.end(), cmp); // 빈도수를 기준으로 내림차순 정렬, 같을 땐 first 오름차순
    
    
    sort(V.begin(), V.end());
    double avg = sum/(double)N;
    int rounded = round(avg);
    if (rounded == -0) {
        rounded = 0;
    }
    cout << rounded << endl;

    int mid = V[N/2];
    cout << mid << endl;

    // 최빈값
    if (freq.size() > 1 && freq[0].second == freq[1].second) {
        cout << freq[1].first << endl;
    } else {
        cout << freq[0].first << endl;
    }

    int diff = V[N-1] - V[0];
    cout << diff << endl;

    return 0;
}