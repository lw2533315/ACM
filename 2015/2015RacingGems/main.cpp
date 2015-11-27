#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int> >v;
    vector<pair<pair<int, int>, int> >v1;
    int number, rate, tempX, tempY;
    if (!cin.eof()) {
        cin >> number >> rate >> tempX>>tempY;
        while (!cin.eof()) {
            cin >> tempX>>tempY;
            v.push_back(make_pair(tempX, tempY));
        }
    }
    int bigNum = 1;
    int inputNum = 1;
    sort(v.begin(), v.end(), cmp);
    v1.push_back(make_pair(make_pair(v[v.size() - 1].first, v[v.size() - 1].second), 1));
    //最后一组x,y坐标和值1 放入新的vector v1
    //下面这个循环i把每组x,y坐标push进v1,同时计算出新的 值
    for (int i = v.size() - 2; i >= 0; i--) {
        int bigcount = 1;
        bigNum = 1;
        for (int j = 0; j < v1.size(); j++) {//遍历v1 找到值 最大的那组值。把值存到bigcount
            int count = 0;
            bigcount = 1;
            if (v[i].first == v1[j].first.first) {
                count = 1 + v1[j].second;
            } else if (abs(v1[j].first.second - v[i].second) / abs(v1[j].first.first - v[i].first) >= rate) {
                count = 1 + v1[j].second;
            } else {
            }
            if (count > bigcount)
                bigcount = count;
            if (bigcount > bigNum)
                bigNum = bigcount;
        }
        v1.push_back(make_pair(make_pair(v[i].first, v[i].second), bigNum));
    }
    cout << " answer is " << bigNum << endl;
  
    return 0;
}