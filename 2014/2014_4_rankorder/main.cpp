/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年2月16日, 下午4:11
 */

#include <cstdlib>
#include<vector>
#include<iterator>
#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream ifs;
    vector< pair<int, int> >vP;
    vector<int >v;
    ifs.open("input.txt");
    try {
        if (ifs) {
            int count = 0;
            int save;
            int k = 0;
            while (ifs >> save) {
                v.push_back(save);
                int inP;
                //注意循环的条件控制不是每次都从0开始
                for (int i = 0 + k; i < k + save; i++) {//以save 的长度一段一段录入vP，先first
                    ifs>>inP;
                    vP.push_back(make_pair(inP, 0));
                }
                for (int i = 0 + k; i < k + save; i++) {//替换本段的 second数值
                    ifs>>inP;
                    vP[i].second = inP;
                }
                k = save + k;
            }
            cout << v[0];
            int temp[2];
            while (v.size() > 0) {
                for (int i = 0; i < v[0]; i++) {
                    for (int j = 0; j < v[0] - 1; j++) {
                        if (vP[j].second < vP[j + 1].second) {
                            temp[0] = vP[j].first;
                            temp[1] = vP[j].second;
                            vP[j].first = vP[j + 1].first;
                            vP[j].second = vP[j + 1].second;
                            vP[j + 1].first = temp[0];
                            vP[j + 1].second = temp[1];
                        }
                    }
                }
                bool out = true;
                for (int i = 0; i < v[0] - 1; i++) {
                    if (vP[i].first < vP[i + 1].first) {
                        cout << i + 1 << endl;
                        out = false;
                        break;
                    }
                }
                if (out)
                    cout << "agree" << endl;
                //用完一段数据，删除对应的vector；
                vP.erase(vP.begin(), vP.begin() + v[0]);
                v.erase(v.begin());
            }
        } else throw "no this file";
    } catch (const char* e) {
        cout << e << endl;
    }
    ifs.close();
    return 0;
}
