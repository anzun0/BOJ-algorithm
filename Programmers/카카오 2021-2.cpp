#include<bits/stdc++.h>

using namespace std;

string convert(int num, int k){
    char code[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string tmp = "";
    while (num / k != 0) {
        tmp = code[num % k] + tmp;
        num = num / k;
    }
    tmp = code[num % k] + tmp;
    return tmp;
}

bool sosu(long long num) {
    if (num < 2) return false;
    int a = (int) sqrt(num);
    for (int i = 2; i <= a; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = convert(n ,k);

    int index = 0;
    bool flag = true;

    for (int i = 0; i <= num.size(); i++) {

        if (num[i] == '\0' && flag) {
            string temp = num.substr(index);
            long long tempNum = stoul(temp);
            if (sosu(tempNum)) answer += 1;
        }

        if (num[i] != '0' && !flag) {
            flag = true;
            index = i;
        }
        if (num[i] == '0' && flag) {
            string temp = num.substr(index, i - index);
            long long tempNum = stoul(temp);
            if (sosu(tempNum)) answer += 1;
            flag = false;
        }
    }
    return answer;
}