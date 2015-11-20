/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年11月19日, 上午11:15
 */

#include <cstdlib>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");

    while (!ifs.eof()) {
        string num;
        ifs>>num;
        string rec = num;
        int step = 0;
        while (rec.size() > 1) {
            int len = rec.size();
            int result = 1;
            for (int i = 0; i < len ; i++) {
                result*=(rec[i]-48);
            }
            stringstream s;
            s<<result;
            s>>rec;
            step++;
        }
        cout << num << " " << step<<endl;
    }
    ifs.close();

    return 0;
}

