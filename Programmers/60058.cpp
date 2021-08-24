//https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>
#include <stack>

using namespace std;
string answer;

string process(string str) {
    string temp = str.substr(1, str.size() - 2);

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }
    return temp;
}

void separate(string str) {
    int openCount = 0;
    int closeCount = 0;
    string u, v;
    stack<char> s;

    if (str.empty()) return;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            openCount += 1;
            u.push_back('(');
            s.push('(');
        }
        if (str[i] == ')') {
            closeCount += 1;
            u.push_back(')');
            if (!s.empty() && s.top() == '(') s.pop();
            else s.push(')');
        }

        if (openCount == closeCount) {
            for (int j = i + 1; j < str.size(); j++)
                v.push_back(str[j]);
            break;
        }
    }

    if (s.empty()) {
        // u가 올바른 문자열인 경우
        answer += u;
        separate(v);
        return;
    }
    else {
        // u가 올바르지 않은 문자열인 경우
        answer.push_back('(');
        separate(v);
        answer.push_back(')');
        answer += process(u);
        return;
    }

}

string solution(string p) {
    separate(p);
    return answer;
}