/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年7月25日, 下午9:07
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    int row = 0;
    string input;
    vector<string>v;
    ifs.open("input.txt");
    try {
        if (ifs) {
            while (getline(ifs, input)) {
                row++;
                const char*split = ":";
                char cArray[input.length()];
                strcpy(cArray, input.c_str());
                char *p = strtok(cArray, split);
                while (p != NULL) {//使用strtok将文件用:隔开后读入vector v
                    v.push_back(p);
                    p = strtok(NULL, split);
                }
            }
            int zeroP[row] = {0};
            vector<string>v1;
            vector<string>v2;
            string temp1, temp2;
            for (int i = 0; i < row; i++) {
                v1.push_back(v[i * 5 + 2]); //participantID 读入v1
                v2.push_back(v[i * 5 + 1]); //documenttype store in v2
            }
            /*sort by v1, when v1 equal, sort by v2
             * 
             * */
            for (int j = 0; j < v1.size(); j++) {
                for (int i = j; i < v1.size() - 1; i++) {
                    if (atoi(v1[i].c_str()) > atoi(v1[i + 1].c_str())) {
                        temp1 = v1[i];
                        temp2 = v2[i];
                        v1[i] = v1[i + 1];
                        v2[i] = v2[i + 1];
                        v1[i + 1] = temp1;
                        v2[i + 1] = temp2;
                    } else if (atoi(v1[i].c_str()) == atoi(v1[i + 1].c_str()) &&
                            atoi(v2[i].c_str()) > atoi(v2[i + 1].c_str())) {
                        temp1 = v1[i];
                        temp2 = v2[i];
                        v1[i] = v1[i + 1];
                        v2[i] = v2[i + 1];
                        v1[i + 1] = temp1;
                        v2[i + 1] = temp2;
                    }
                }
            }
            /*
             enlarge v1, and v2, than forloop do not miss the last element.
             */
            v1.push_back("-1");
            v2.push_back("-1");
            int count = 1; //se number;ame document type number;
            for (int i = 0; i < v2.size() - 1; i++) {
                if (v1[i] != v1[i + 1]) {
                    cout << v1[i] << " " << v2[i] << " " << count << endl;
                    count = 1;
                } else if (v1[i] == v1[i + 1] && v2[i] != v2[i + 1]) {
                    cout << v1[i] << " " << v2[i] << " " << count << endl;
                    count = 1;
                } else {
                    count++;
                }
            }
        } else throw "no this file";
    } catch (const char*e) {
        cout << e << endl;
    }
    ifs.close();
    return 0;
}

