#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int idx = 0;
    
    for (string s: seoul) {
        if (s == "Kim") {
            break;
        }
        idx++;
    }
    
    answer = "김서방은 " + to_string(idx) + "에 있다";
    
    return answer;
}