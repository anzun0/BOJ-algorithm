#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int kor, eng, math;
    Student(string name, int kor, int eng, int math) {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->math = math;
    }
    bool operator <(Student &other) {
        if (this->kor == other.kor) {
            if (this->eng == other.eng) {
                if (this->math == other.math) {
                    return this->name < other.name;
                }
                return this->math > other.math;
            }
            return this->eng < other.eng;
        }
        return this->kor > other.kor;
    }
};

int n;
vector<Student> v;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor;
        int eng;
        int math;
        cin >> name >> kor >> eng >> math;
        v.push_back(Student(name, kor, eng, math));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
    return 0;
}