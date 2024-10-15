#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, C;
vector<int> countOrder;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
  return a.second > b.second;
}

int main() {
  cin >> N >> C;
  unordered_map<int, int> count;

  for (int i = 0; i < N; i++)
  {
    int temp;
    cin >> temp;
    if (count.find(temp) == count.end()) {
      countOrder.push_back(temp);
      count.insert({temp, 1});

    } else {
      count[temp]++;
    }
  }

  vector<pair<int,int>> v;
  for (int i = 0; i < countOrder.size(); i++)
  {
    v.push_back({countOrder[i], count[countOrder[i]]});
  }
  

  stable_sort(v.begin(), v.end(), cmp);
  
  for (auto &&i : v)
  {
    for (int j = 0; j < i.second; j++)
    {
      if (i == v.back() && j == i.second-1) {
        cout << i.first;
        break;
      }
      cout << i.first << " ";
    }
  }
  return 0;
}