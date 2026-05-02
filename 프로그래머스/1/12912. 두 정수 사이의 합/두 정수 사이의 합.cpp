#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int maxVal = max(a, b);
    int minVal = min(a, b);
    for (int i = minVal; i<=maxVal;i++) {
        answer += i;
    }
    
    return answer;
}