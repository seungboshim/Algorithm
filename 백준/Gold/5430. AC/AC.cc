#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;

void AC(string p) {
    bool reversed = false;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == 'R') {
            reversed = !reversed;
        } else if (p[i] == 'D') {
            if (dq.empty()) {
                cout << "error\n";
                return;
            } else {
                if (reversed) { // 뒤집힘
                    dq.pop_back();
                } else { // 안뒤집힘
                    dq.pop_front();
                }
            }
        }
    }

    int N = dq.size();
    if (reversed) {
        cout << "[";
        for (int i = 0; i < N; i++)
        {
            string temp = to_string(dq.back());
            cout << temp;
            if (dq.size() > 1) {
                cout << ",";
            }
            dq.pop_back();
        }
        cout << "]\n";
    } else {
        cout << "[";
        for (int i = 0; i < N; i++)
        {
            string temp = to_string(dq.front());
            cout << temp;
            if (dq.size() > 1) {
                cout << ",";
            }
            dq.pop_front();
        }
        cout << "]\n";
    }
    
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string p;
        int n;
        string x;

        cin >> p >> n >> x;

        if (p == "") { // 명령어 아무것도 없을때 그대로 출력
            cout << x << '\n';
            continue;
        }

        x = x.substr(1, x.size() - 2); // 괄호 제거

        istringstream ss(x);
        string buff;
        
        while (getline(ss, buff, ',')) {
            dq.push_back(stoi(buff));
        }
        
        AC(p);
        dq.clear();
        
    }
    
}