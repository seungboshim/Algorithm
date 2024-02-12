#include <iostream>

using namespace std;

int dp[40] = {0};

int fibonacci(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (dp[n] != 0) {
        return dp[n];
    } else {
        return dp[n] = fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        if (N == 0) {
            cout << "1 0" << endl;
        } else {
            cout << fibonacci(N-1) << " " << fibonacci(N) << endl;
        }
    }
    
    return 0;
}