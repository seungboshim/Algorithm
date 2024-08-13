#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
vector<int> blocks;

int main() {
    cin >> H >> W;
    blocks.resize(W);
    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }

    int sum = 0;


    for (int i = 1; i < W-1; i++) // 양끝은 비 안참
    {
        int leftTop = 0, rightTop = 0;
        for (int j = 0; j < i; j++)
        {
            leftTop = max(leftTop, blocks[j]);
        }
        for (int j = i+1; j < W; j++)
        {
            rightTop = max(rightTop, blocks[j]);
        }

        sum += max(0,(min(leftTop, rightTop) - blocks[i]));
        
    }
    
    cout << sum << endl;
    return 0;
}