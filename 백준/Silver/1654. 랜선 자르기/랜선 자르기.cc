#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int K, N;
vector<ll> v;

ll binarySearch() {
    ll left = 1;
    ll right = v[K-1];
    ll result = 0;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        int lans = 0;

        for (int i = 0; i < K; i++)
        {
            lans += v[i] / mid;
        }

        //cout << left << " " << right << endl;

        if (lans == N) {
            result = max(result, mid);
            left = mid + 1;
        } else if (lans < N) {
            right = mid - 1;
        } else if (lans > N) {
            result = max(result, mid);
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        ll res;
        cin >> res;
        v.push_back(res);
    }

    sort(v.begin(), v.end());

    cout << binarySearch() << endl;
}