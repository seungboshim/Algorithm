#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Time { // 시간 구조체
  int h, m;

  bool operator<=(const Time& t) const {
    if (h == t.h) return m <= t.m;
    return h <= t.h;
  }
};

Time strToTime(string str) {
  int h = stoi(str.substr(0, 2));
  int m = stoi(str.substr(3, 2));
  return {h, m};
}

int main() {
  string S, E, Q;
  cin >> S >> E >> Q;
  
  Time start = strToTime(S);
  Time end = strToTime(E);
  Time quit = strToTime(Q);

  
  map<string, Time> timestamp;
  int count = 0;
  
  string timeStr, name;
  while (cin >> timeStr >> name) {
    Time t = strToTime(timeStr);

    if (t <= start) { // 시작 이전 채팅한 사람
      if (timestamp.find(name) == timestamp.end()) {
        timestamp.insert({name, t});
      }
    } else if (end <= t && t <= quit) { // 끝나고 채팅한 사람
      if (timestamp.find(name) != timestamp.end()) {
        count++;
        timestamp.erase(name);
      }
    }
  }

  cout << count;
  return 0;
}