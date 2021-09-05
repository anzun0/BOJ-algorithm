#include <bits/stdc++.h>
using namespace std;

class Date {
public:
    int month;
    int day;
    Date(int month, int day) {
        this -> month = month;
        this -> day = day;
    };
    bool operator <(const Date& other) const {
        if (this -> month == other.month)
            return this -> day < other.day;
        return this -> month < other.month;
    }
};

int n, result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<pair<Date, Date>> v;
    for (int i = 0; i < n; i++) {
        int startMonth, startDay, endMonth, endDay;
        cin >> startMonth >> startDay >> endMonth >> endDay;
        Date start = Date(startMonth, startDay);
        Date end = Date(endMonth, endDay);
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());

    int idx = -1;
    Date temp = Date(0, 0);
    for (Date i = Date(3, 1); i < Date(12, 1); i = temp) {
        bool flag = false;

        idx += 1;
        for (int j = idx; j < v.size(); j++) {
            if (i < v[j].first) break;
            flag = true;
            if (temp < v[j].second) {
                temp = v[j].second;
                idx = j;
            }
        }
        if (flag) result += 1;
        else {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << result << '\n';
}