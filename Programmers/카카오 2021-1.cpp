#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> m;
    map<string, int> count;

    for (int i = 0; i < report.size(); i++) {
        int idx = report[i].find(" ");
        string a = report[i].substr(0, idx);
        string b = report[i].substr(idx + 1);

        m[a].insert(b);
    }

    for (int i = 0; i < id_list.size(); i++) {
        string now = id_list[i];
        set<string>::iterator iter;

        for (iter = m[now].begin(); iter != m[now].end(); iter++) {
            string name = *iter;
            if (count.find(name) == count.end()) {
                count[name] = 1;
            }
            else count[name] += 1;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        int result = 0;
        string now = id_list[i];
        set<string>::iterator iter;

        for (iter = m[now].begin(); iter != m[now].end(); iter++) {
            string name = *iter;
            if (count[name] >= k) result += 1;
        }
        answer.push_back(result);
    }

    return answer;
}