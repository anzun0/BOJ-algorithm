// https://programmers.co.kr/learn/courses/30/lessons/60057
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int ans = 1e9;

    for (int i = 1; i <= s.size(); i++) { //1개 단위부터, 문자열의 전체 길이까지
        string result = "";

        int count = 1;
        string now = s.substr(0, i);

        for (int j = i; j < s.size(); j += i) {
            string next = s.substr(j, i);
            if (now == next) count += 1;
            else {
                if (count != 1) result += to_string(count);
                result += now;
                now = next;
                count = 1;
            }
        }
        if (count > 1) result += to_string(count);
        result += now;

        int size = result.size();
        ans = min(ans, size);
    }
    return ans;
}