#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkStr(string str) { // (()(()))
	stack<char> s;
	int n = str.length();
	
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			s.push(str[i]); // 여는 괄호를 스택에 넣다가..

		else { // 닫는 괄호를 만난다면
			if (s.empty()) // 스택이 비어있을 땐 false
				return false; 
			else // 스택에 여는 괄호가 남아있을 땐 짝지어서 pop
				s.pop();
		}
	}

	if (s.empty()) return true; // 스택이 비면 괄호의 짝이 맞은것
	else return false;
}

int main() {
	int t;
	cin >> t; // 입력 데이터 갯수 T

	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;

		if (checkStr(str) == 1) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}