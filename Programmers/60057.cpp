// https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int ans = s.size();

    for (int i = 1; i <= s.size() / 2; i++) {
        string convert, temp;
        int count = 1;
        temp = s.substr(0, i);

        for (int j = i; j < s.size(); j += i) {
            if (temp == s.substr(j, i)) count += 1;
            else {
                if (count > 1) convert += to_string(count);
                convert += temp;
                temp = s.substr(j, i);
                count = 1;
            }
        }
        if (count > 1) convert += to_string(count);
        convert += temp;

        int size = convert.size();
        ans = min(ans, size);
    }
    return ans;
}