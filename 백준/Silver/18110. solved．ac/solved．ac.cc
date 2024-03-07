#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int diff;
        cin >> diff;
        v.push_back(diff);
    }
    sort(v.begin(), v.end());

    int cut = round(n * 0.15);
    // cout << "커엇" <<cut <<endl;
    // for (int i = 0; i < cut; i++)
    // {
    //     v.pop_back();
    //     v.erase(v.begin());
    // }
    
    // int sum = 0;
    // for (auto &&i : v)
    // {
    //     sum+=i;
    // }

    int sum = 0;
    for (int i = cut; i < n - cut; i++)
    {
        sum += v[i];
    }

    //cout << sum<<endl;
    int res = v.size() - cut * 2;

    cout << round(sum / (float)res) << endl;
    return 0;
}