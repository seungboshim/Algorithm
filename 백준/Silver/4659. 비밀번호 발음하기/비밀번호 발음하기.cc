#include <iostream>
#include <string>
#include <stack>
using namespace std;

void checkStr(string s) {
    bool containVowel = false; // 모음 여부
    bool throwFlag = false; // 불가능한 문자열인지 여부

    stack<char> vowel;
    stack<char> consonant;

    for (int i=0; i<s.length(); i++)
    {
        if (throwFlag) {
            break;
        }
        char curr = s[i];
        
        if (i > 0) {
            char prev = s[i-1]; // 이전 문자
            if (prev == curr) // 두번 연속 나오는 경우
                if (curr != 'e' && curr != 'o')
                    throwFlag = true;
        }

        if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u') { // 모음 나옴
            containVowel = true;
            vowel.push(curr);
            if (vowel.size() == 3) // 모음 3개 연속
                throwFlag = true;
            else {
                while (!consonant.empty()) { // 자음 스택 clear
                    consonant.pop();
                }
            }
        } else {
            consonant.push(curr);
            if (consonant.size() == 3) // 자음 3개 연속
                throwFlag = true;
            else {
                while (!vowel.empty()) { // 모음 스택 clear
                    vowel.pop();
                }
            }
        }
    }
    
    if (!containVowel || throwFlag) {
        cout << "<" << s << "> is not acceptable.\n";
        return;
    } else {
        cout << "<" << s << "> is acceptable.\n";
        return;
    }
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "end") {
            break;
        }

        checkStr(s);
    }
}