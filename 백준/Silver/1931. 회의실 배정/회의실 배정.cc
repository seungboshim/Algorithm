#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//vector<pair<pair<int, int>, int>> meeting;
vector<pair<int, int>> meeting;

bool compare (pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        //int durate = end - start;
        //meeting.push_back(make_pair(make_pair(start, end), durate));
        meeting.push_back(make_pair(start, end));
    }

    // 빨리 끝나는 순서대로 정렬
    sort(meeting.begin(), meeting.end(), compare);    

    // int rooms = 1;
    // for (int i = 0; i < N; i++)
    // {
    //     int curr = meeting[i].second; // 현재루프의 첫회의가 끝나는 시각
    //     int currRooms = 1; // 현재루프의 선택가능한 회의갯수
    //     for (int j = i+1; j < N; j++)
    //     {
    //         if (meeting[j].first >= curr) {
    //             curr = meeting[j].second;
    //             currRooms++;
    //         } else {
    //             continue;
    //         }
    //     }
    //     rooms = max(rooms, currRooms);
    // }    
    
    int rooms = 1;
    int curr = meeting[0].second; 
    // 제일 빨리 끝나는 회의는 무조건 선택됨 -> rooms = 1부터 시작
    for (int i = 1; i < N; i++)
    {
        // 현재 끝난 회의시간 이후 시작하는 회의만 
        if (meeting[i].first >= curr) {
            curr = meeting[i].second;
            rooms++;
        }
        // 1-4, 5-7, 8-11, 12-14
    }
    
    cout << rooms << endl;
    return 0;
    
}