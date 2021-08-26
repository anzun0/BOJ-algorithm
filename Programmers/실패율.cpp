//https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> p1, pair<int, double> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    
    int length = stages.size();
    
    for (int i = 1; i <= N; i++) {
        int cnt = count(stages.begin(), stages.end(), i);
    
        double fail = 0;
        if (length > 1) {
            fail = (double) cnt / length;
        }
        v.push_back({i, fail});
        length -= cnt;
    }
    
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].first);
    }
    
    return answer;
}