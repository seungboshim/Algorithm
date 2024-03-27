#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;
    stack<int> S;

    for (int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0 && !S.empty()) {
            S.pop();
        } else {
            S.push(temp);
        }
    }

    int sum = 0;
    while (!S.empty()) {
        sum+=S.top();
        S.pop();
    }

    cout << sum << endl;
    return 0;
    
}