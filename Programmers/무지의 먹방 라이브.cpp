//https://programmers.co.kr/learn/courses/30/lessons/42891
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {

    long long summary = 0;
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) return -1;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({-food_times[i], i + 1});
    }

    summary = 0; // 지금까지 사용한 시간
    long long previous = 0;
    long long length = food_times.size(); // 남은 음식

    while (summary + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1;
        previous = now;
    }

    vector<pair<int, int>> result;
    while(!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({food_time, num});
    }
    sort(result.begin(), result.end(), compare);

    return result[(k - summary) % length].second;
}