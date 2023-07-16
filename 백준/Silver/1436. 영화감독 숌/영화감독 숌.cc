#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int num = 665;

	while (cnt < n) {
		num++;
		string str = to_string(num);
		if (str.find("666") != string::npos) {
			cnt++;
		}
	}

	cout << num << endl;
	return 0;
}