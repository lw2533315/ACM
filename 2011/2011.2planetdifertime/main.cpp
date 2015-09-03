/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年7月16日, 下午11:23
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
       vector<int>v;
   
    int len;
    int input;
    string sInput;
    while(getline(cin,sInput)){
        len=sInput.length();        
        char cArray[len];
        strcpy(cArray,sInput.c_str());
        if(len==1&&atoi(cArray)==0)break;//遇到0 字符串长为1值为0，退出
        char* p;
        const char*split=" /-:";//strtok拆分标准（多标准，" ","/","-")
        p=strtok(cArray,split);
        while(p!=NULL){
            input=atoi(p);  
            v.push_back(input);
            p=strtok(NULL,split);
        }        
    }
    while(v.size()>0){
         int result,seconds, minutes, hours, months=0,years,days,monNumber=0;
    years=v[12+v[3]]-v[v[3]+6];
    for(int i=1;i<v[10+v[3]];i++){
        months=v[i+3]+months;
       // cout<<"m1 is "<<months<<endl;
    }
    int temp=0;
    for(int i=1;i<v[v[3]+4];i++){
        temp=v[i+3]+temp;
        //cout<<"m2 is "<<temp<<endl;
    }
   months=months-temp; 
//    months=v[10+v[3]]-v[v[3]+1];
    days=v[11+v[3]]-v[v[3]+5];
    hours=v[13+v[3]]-v[v[3]+7];
    minutes=v[14+v[3]]-v[v[3]+8];
    seconds=v[15+v[3]]-v[v[3]+9];
    //cout<<"seconds is "<<seconds<<endl;
    for(int i=0;i<v[3];i++){
        monNumber=v[i+4];
    }
    years=years*monNumber*v[2]*v[1]*v[0];
    //cout<<"years is "<<years<<endl;
    months=months*v[2]*v[1]*v[0];
    //cout<<"month is "<<months<<endl;
    days=days*v[2]*v[1]*v[0];
    //cout<<"days is "<<days<<endl;
    hours=hours*v[1]*v[0];
    //cout<<"hours is "<<hours<<endl;
    minutes=minutes*v[0];
    //cout<<"minutes is "<<minutes<<endl;
    result=years+months+days+hours+minutes+seconds;
    cout<<result<<endl;
    v.erase(v.begin(),v.begin()+16+v[3]);
    }
    return 0;
}

