/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年7月26日, 上午11:05
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;
typedef char*p;
/*recursion.
 */
string divid(string str, vector<string>&v, int row, bool&isDivid, string a,vector<string>&back) {
    if (str.length() == 0) {
        bool mark=false;
        isDivid = true;
        const char*split="-";
        char*p;
        char array[200];
        strcpy(array,a.c_str());        
        p=strtok(array,split);
//        cout<<back[0]<<endl;
        
        while(p!=NULL){
//            cout<<p<<endl;
            for(int i=0;i<back.size();i++)
                if(back[i]==p){                    
                    mark=true;
                    break;
                }
            p=strtok(NULL,split);
        }
        if(mark)
        cout <<"?"<< a <<endl;
        else
            cout<<a<<endl;
        return "";
    } else {
        for (int i = 0; i < row; i++) {
            string tempS = a;
            string temp;
            if (v[i] == str.substr(0, v[i].length())) {
                //                  cout<<"test"<<endl;
                temp = str.substr(v[i].length(), str.size() - v[i].length());
                if (temp.length() > 0)
                    tempS=tempS+v[i]+"-";
                    //cout << v[i] << "-";
                else
                    tempS=tempS+v[i];
//                    cout << v[i];
                divid(temp, v, row, isDivid,tempS,back);

            }

            //            else {cout<<"test"<<endl;return "";}
        }
        return "";

    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    vector<string>v;
    vector<string>vBack;
    string temp;
    int row = 0;
    int markNum = 0; //问号开头的word的个数
    ifs.open("input.txt");
    try {
        if (ifs) {
            int count = 0;
            while (getline(ifs, temp)) {
                v.push_back(temp.substr(0, temp.length() - 1));
                if (temp.length() == 1)
                    row = count;
                count++;
            }


            for (int i = 0; i < row; i++) {
                if (v[i].substr(0, 1) == "?") {
                    markNum++;
                    v[i] = v[i].substr(1);
                    vBack.push_back(v[i]);
                }
            }
//            for(int i=0;i<vBack.size();i++)
//                cout<<vBack[i]<<" ";

            string sTemp;
            char a[33];
            char b[33];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < row - 1; j++) {
                    strcpy(a, v[j].c_str());
                    strcpy(b, v[j + 1].c_str());
                    if ((int) a[0]>(int) b[0]) {
                        sTemp = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = sTemp;
                    }
                }
            }
            for (int i = row + 1; i < v.size(); i++) {
                bool isDivid = false;
                string tString = "";
                cout<<v[i]<<":"<<endl;
                cout << divid(v[i], v, row, isDivid, tString,vBack)<<endl;
                if (!isDivid)
                    cout << "!No words be founded";
            }

            //                                   for(int i=0;i<row;i++)
            //                                    cout<<v[i]<<endl;

        } else throw "no this file";
    } catch (const char*e) {
        cout << e << endl;
    }
    ifs.close();




    return 0;
}

