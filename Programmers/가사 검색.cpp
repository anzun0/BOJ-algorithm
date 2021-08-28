//https://programmers.co.kr/learn/courses/30/lessons/60060
#include <bits/stdc++.h>

using namespace std;

vector<string> arr[10001];
vector<string> reverse_arr[10001];

int countByRange(vector<string>& v, string leftValue, string rightValue) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

string replaceAll(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos) {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reverse_arr[word.size()].push_back(word);
    }

    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reverse_arr[i].begin(), reverse_arr[i].end());
    }

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int res = 0;

        if (query[0] != '?') { // 와일드카드가 접미사(뒤)에 붙은 경우
            res = countByRange(arr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        else { // 와일드카드가 접두사(앞)에 붙은 경우
            reverse(query.begin(), query.end());
            res = countByRange(reverse_arr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        answer.push_back(res);
    }
    return answer;
}