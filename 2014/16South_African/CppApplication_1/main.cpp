/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年4月26日, 上午11:20
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<vector>
#include <vector>

using namespace std;

template<typename T>
int tole(T a[], int size) {
    int small = a[0];
    int big = a[0];
    for (int i = 1; i < size - 2; i++) {
        if (a[i] > a[0])
            big = a[i];
        if (a[i] < a[0])
            small = a[i];
    }
    return big - small;
}

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    try {
        if (!ifs)
            throw "this file do not exist";
    } catch (const char* e) {
        cout << e << endl;
    }
    string temp;
    int space;
    int n[4];
   
    int stand = 0;
    while (getline(ifs, temp)) {
        int i = 0;
        if (temp[0] != '-' && temp[1] != '1') { //不为-1   
            while (i < 4) { //有4个数字
                space = temp.find(' ');//寻找空格
                if (space != -1) {//最后一个数字后面没有空格，会返回-1
                    n[i] = atoi(temp.substr(0, space).c_str());
                    temp = temp.substr(space + 1);
                    i++;
                } else {
                    n[i] = atoi(temp.substr(0).c_str());
                    i++;
                }
            }
            int d = tole(n, 4);//调用函数比较大小数值差
            stand = n[3];
            if (d <= stand)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}

