#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string cipher;
    int N;

    cin >> cipher;
    cin >> N;

    vector<string> hint(N);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> hint[i];
    }


    for (int i = 0; i < 26; i++)
    {
        for (int k = 0; k < N; k++) // 현재 cipher 에서 hint 포함이면 끝내기 
        {
            if (cipher.find(hint[k]) != string::npos) {
                cout << cipher << endl;
                return 0;
            } 
        }
        
        for (int j = 0; j < cipher.size(); j++) // 모든 cipher 1칸씩 밀기
        {
            int ascii = static_cast<int>(cipher[j]);
            if (ascii == 122) {
                ascii = 97;
            } else {
                ascii++;
            }

            cipher[j] = static_cast<char>(ascii);
        }
        
    }
    
    return 0;
}