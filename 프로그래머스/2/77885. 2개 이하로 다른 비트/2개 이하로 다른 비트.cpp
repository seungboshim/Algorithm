#include <string>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long number: numbers) {
        if (number%2 == 0) {
            answer.push_back(number+1);
        } else {
            bitset<50> binary(number);
            for (int i=0; i<binary.size(); i++) {
                // 011 -> 101 : 3 -> 5.. i=2 // 2
                // 0111 -> 1011 : 7 -> 11.. i=3 // 4
                // 1011 -> 1101 : 11 -> 13.. i=2 // 2
                // 01111 -> 10111 : 15 -> 23.. i=4 // 8
                if (binary[i]==0) {
                    answer.push_back(number+pow(2, i-1));
                    break;
                }
            }
        }
    }
    
    return answer;
}