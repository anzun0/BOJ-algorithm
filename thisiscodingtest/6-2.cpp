#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string name, int score) {
        this -> name = name;
        this -> score = score;
    }
    bool operator <(Student &other) {
        return this->score < other.score;
    }
};

int n;
vector<Student> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        v.push_back(Student(name, score));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i].name << ' ';
    }
}