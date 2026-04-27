#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    int arr[11] = {0};
    int i = 0;
    
    while (n > 0) {
        arr[i] = n % 10;
        n /= 10;
        i++;
    }
    
    sort(arr, arr+i);
    
    for (int j = 0; j < i; j++) {
        answer += arr[j] * pow(10, j);    
    }
    
    return answer;
}