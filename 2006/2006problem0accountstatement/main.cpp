/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年8月4日, 下午9:27
 */

#include <cstdlib>
#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    string temp;
    const char*split = " ";
    
    try {
        if (ifs) {
            while (getline(ifs, temp)) {
                vector <string>v;
                char c[temp.length()];
                strcpy(c, temp.c_str());
                char *p = strtok(c, split);
                while (p != NULL) {
                    v.push_back(p);
                    p = strtok(NULL, split);
                }
                cout<<v[0]<<endl;
                double balance;
                stringstream ss;
                ss<<v[1];
                ss>>balance;
                int day;
                stringstream ss1;
                ss1<<v[2];
                ss1>>day;
                stringstream ss2;
                double interest;
                ss2<<v[3];
                ss2>>interest;
                interest=interest*0.01/365*31*balance;
                cout<<"         "<<interest<<endl;
                cout<<"         "<<balance+interest<<endl;
            }
        } else throw "no the file";
    } catch (const char*e) {
        cout << e << endl;
    }
    return 0;
}

