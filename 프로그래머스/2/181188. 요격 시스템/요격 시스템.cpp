#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
	// 1 4
	// 4 5
	// 3 7
	// 4 8
	// 5 12
	// 11 13
	// 10 14
    int curr = targets[0][1]; // 4 인데 3.9999라고생각 ㄱ
    int bomb = 1;
    for (auto t: targets) {
        if(t[0] >= curr) {
            curr = t[1];
            bomb++;
        }
    }
    answer=bomb;
    return answer;
}