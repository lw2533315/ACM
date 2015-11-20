/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年11月19日, 上午10:38
 */

#include <cstdlib>
#include<iostream>
#include<set>
#include<vector>
#include<fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    set<int>s;
    vector<pair<int ,int > >v;
    ifstream ifs;
    ifs.open("input.txt");
    string str;
    int line=1;
    while(getline(ifs,str)){
        for(int i=0;i<str.length();i++){
            if(str[i]=='x'){
                v.push_back(make_pair(line,i+1));
            }
        }
        line++;
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            int dis=abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
            s.insert(dis);
        }
    }
    cout<<s.size();
    return 0;
}

