#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int,int> moveChess(int &x, int &y, string curr) {
    int nx = x, ny = y;
    if (curr[0] == 'R') {
        nx = x+1;
    }
    if (curr[0] == 'L') {
        nx = x-1;
    }
    if (curr.find('B') != string::npos) {
        ny = y-1;
    }
    if (curr.find('T') != string::npos) {
        ny = y+1;
    }

    return make_pair(nx, ny);
}

int main() {
    string king, stone;
    vector<string> move;
    int N;

    cin >> king >> stone >> N;
    move.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> move[i];
    }

    /* 체스판
    A8 B8 C8 D8 E8 F8 G8 H8
    A7 B7 C7 D7 E7 F7 G7 H7
    A6 B6 C6 D6 E6 F6 G6 H6
    A5 B5 C5 D5 E5 F5 G5 H5
    A4 B4 C4 D4 E4 F4 G4 H4
    A3 B3 C3 D3 E3 F3 G3 H3
    A2 B2 C2 D2 E2 F2 G2 H2
    A1 B1 C1 D1 E1 F1 G1 H1
    */

    int kingX = king[0] - 'A' + 1; // A~H -> 1~8
    int kingY = king[1] - '0';
    int stoneX = stone[0] - 'A' + 1;
    int stoneY = stone[1] - '0';

    for (int i = 0; i < N; i++)
    {
        string curr = move[i];

        pair<int, int> newKing = moveChess(kingX, kingY, curr);
        int newKingX = newKing.first;
        int newKingY = newKing.second;

        if (newKingX == stoneX && newKingY == stoneY) {
            pair<int, int> newStone = moveChess(stoneX, stoneY, curr);
            int newStoneX = newStone.first;
            int newStoneY = newStone.second;

            if (newStoneX >= 1 && newStoneX <= 8 && newStoneY >= 1 && newStoneY <= 8) {
                kingX = newKingX;
                kingY = newKingY;
                stoneX = newStoneX;
                stoneY = newStoneY;
            }
        } else if (newKingX >= 1 && newKingX <= 8 && newKingY >= 1 && newKingY <= 8) {
            kingX = newKingX;
            kingY = newKingY;
        }
    }

    char kingXChar = char(kingX + 65 - 1);
    char stoneXChar = char(stoneX + 65 - 1);

    std::cout << kingXChar << kingY << '\n';
    std::cout << stoneXChar << stoneY << '\n';
    return 0;
}