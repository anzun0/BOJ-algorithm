// https://programmers.co.kr/learn/courses/30/lessons/60062
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;

    int weak_len = weak.size();
    int dist_len = dist.size();
    for (int i = 0; i < weak_len - 1; i++)
        weak.push_back(weak[i] + n);

    sort(dist.begin(), dist.end());

    do {
        for (int i = 0; i < weak_len; i++) {
            int start = weak[i];
            int end = weak[i + weak_len - 1];

            for (int j = 0; j < dist_len; j++) {
                start += dist[j];
                if (start >= end) {
                    answer = min(answer, j + 1);
                    break;
                }
                int next_index = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next_index];
            }
        }

    } while(next_permutation(dist.begin(), dist.end()));

    if (answer == 1e9) return -1;
    return answer;
}