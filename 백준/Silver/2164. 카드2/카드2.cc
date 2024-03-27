#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> Q;
    for (int i = 1; i <= N; i++)
    {
        Q.push(i);
    }

    int i = 0;
    while(Q.size() > 1)
    {
        if (i%2 == 0) {
            Q.pop();
        } else {
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        i++;
    }
    
    cout << Q.front() << endl;
    return 0;
}