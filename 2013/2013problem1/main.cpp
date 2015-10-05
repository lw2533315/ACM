/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年10月3日, 下午8:25
 */

#include <cstdlib>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    vector<int>score;
    vector<pair<char, char> >v;
    ifs.open("input.txt");
    int temp;
    char cTemp;
    string cString, cString2;
    try {
        if (ifs) {
            while (ifs >> temp && temp != 0) {
                score.push_back(temp);
            }
            
            getline(ifs, cString);
            int count = 0;
            while (getline(ifs, cString)) {               
                getline(ifs, cString2);               
                int sum = 0;
                int mutiple = 1;             
                for (int i = 0; i < cString.size() - 1; i++) {
                    if (48 < (int) cString[i]&&(int) cString[i] < 58) {//要强制转换int
                        //ascii 0->48,9->57
                        //超出score vector范围的值都认为是0
                        (cString2[i]-65)>score.size()||(cString2[i]-65)<0?sum=sum+0:
                        sum = sum + score[(cString2[i] - 65)]*((int) cString[i] - 48);//65->A
                        //-65,对应相应大写字母，正好是第一个vector表中对应读入的字母score
                    } else {
                           (cString2[i]-65)>score.size()||(cString2[i]-65)<0?sum=sum+0:sum = sum + score[cString2[i] - 65];
                    }
                    if ((int) cString[i] == 100) {//100对应d，表示sum的两倍
                        mutiple = mutiple * 2;
                    } else if ((int) cString[i] == 116) {//116对应t，3倍
                        mutiple = mutiple * 3;
                    } else {
                    }
                }
                cout << sum * mutiple << endl;
            }
        } else throw "no this file";
    } catch (const char* e) {
        cout << e << endl;
    }
    return 0;
}

