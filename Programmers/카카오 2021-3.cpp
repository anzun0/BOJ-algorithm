#include <bits/stdc++.h>

using namespace std;

map<int, pair<string, string>> m;
map<int, int> totalMap, result;

int calculateTime(pair<string, string> p) {
    string inTime = p.first;
    string outTime = p.second;

    int idx1 = inTime.find(":");
    int idx2 = outTime.find(":");

    int inHour = stoi(inTime.substr(0, idx1));
    int inMin = stoi(inTime.substr(idx1 + 1));
    int outHour = stoi(outTime.substr(0, idx2));
    int outMin = stoi(outTime.substr(idx2 + 1));

    return (outHour - inHour) * 60 + (outMin - inMin);
}

void out(int carNumber, int baseTime, int baseFee, int unitTime, int unitFee) {
    int timeSum = totalMap[carNumber];

    if (timeSum <= baseTime) {
        result[carNumber] = baseFee;
    }
    else {
        int temp = (timeSum - baseTime) / unitTime;
        int plusFee = ((timeSum - baseTime) % unitTime == 0) ? temp * unitFee : (temp + 1) * unitFee;
        int totalFee = baseFee + plusFee;

        result[carNumber] = totalFee;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    for (int i = 0; i < records.size(); i++) {
        string time, type;
        int carNumber;
        int idx1 = records[i].find(" ");
        int idx2 = records[i].find(" ", idx1 + 1);

        time = records[i].substr(0, idx1);
        carNumber = stoi(records[i].substr(idx1 + 1, idx2));
        type = records[i].substr(idx2 + 1);

        if (type == "IN") m[carNumber] = {time, ""};
        if (type == "OUT") {
            m[carNumber].second = time;
            int timeSum = calculateTime(m[carNumber]);
            if (totalMap.find(carNumber) == totalMap.end()) totalMap[carNumber] = timeSum;
            else totalMap[carNumber] += timeSum;
            m[carNumber] = {"", ""};
        }
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if ((iter -> second).first != "") {
            int carNumber = iter->first;
            m[carNumber].second = "23:59";
            int timeSum = calculateTime(m[carNumber]);
            if (totalMap.find(carNumber) == totalMap.end()) totalMap[carNumber] = timeSum;
            else totalMap[carNumber] += timeSum;
        }
    }

    for (auto iter = totalMap.begin(); iter != totalMap.end(); iter++) {
        int carNumber = iter->first;
        int timeSum = iter->second;
        out(carNumber, baseTime, baseFee, unitTime, unitFee);
    }

    for (auto iter = result.begin(); iter != result.end(); iter++) {
        answer.push_back(iter->second);
    }

    return answer;
}