#include <iostream>
#include <vector>
using namespace std;

void combinations(vector<int>& comb, vector<int>& S, int idx, int p) {
	if (comb.size() == 6) { // 조합의 크기가 6이면 출력
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = idx; i < p; i++) {
		comb.push_back(S[i]);
		combinations(comb, S, i+1, p);
		comb.pop_back();
	}
}

int main() {
	int k = 1;
	int s;

	vector<int> K;
	vector<int> S;
	
	while (k != 0) {
		cin >> k;
		K.push_back(k);
		if (k <= 6) break;
		for (int i = 0; i < k; i++)
		{
			cin >> s;
			S.push_back(s);
		}
	}

	vector<int> comb;
	for (int i = 0; i < K.size(); i++)
	{
		int num = K[i];
		if (num == 0) break;
		combinations(comb, S, 0, num);
		cout << endl;

		S.erase(S.begin(), S.begin() + num);
	}

	return 0;
}