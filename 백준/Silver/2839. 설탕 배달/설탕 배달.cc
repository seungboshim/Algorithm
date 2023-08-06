#include <iostream>
using namespace std;

int N;
int bags[5001] = { 0 };

int main() {
	cin >> N;
	bags[3] = 1;
	bags[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		if (bags[i - 3] != 0) {
			bags[i] = bags[i - 3] + 1;
		}
		if (bags[i - 5] != 0 && (bags[i] == 0 || bags[i] > bags[i - 5] + 1)) {
			bags[i] = bags[i - 5] + 1;
		}
	}

	if (bags[N] != 0)
		cout << bags[N] << "\n";
	else cout << -1 << "\n";
	return 0;
}