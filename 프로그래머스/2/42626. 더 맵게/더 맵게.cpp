#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    // for (int i=0; i<scoville.size(); i++) {
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }
    
    while (pq.top() < K) {
        if (pq.size() < 2) {
            return -1;
        }
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + b*2);
        answer++;
    }
    

    
    return answer;
}