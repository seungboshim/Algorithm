#include <iostream>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;
    int Z = 100 * Y/X;
    int newZ;
    long long left = 0, right = 1000000000;
    long long mid = (left + right) / 2;

    // 99에서 100이될 수는 없다
    if (Z >= 99) {
        cout << -1 << '\n';
        return 0;
    }

    while (left <= right) {
        mid = (left + right) / 2;
        newZ = 100 * (Y + mid) / (X + mid);
        if (newZ > Z) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << '\n';
    return 0;
}