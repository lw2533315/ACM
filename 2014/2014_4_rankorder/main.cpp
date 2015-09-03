/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年5月29日, 上午11:37
 */

#include <cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
#include<iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    map<int, int>m1, m2;
    int len;
    cin>>len;
    int record=len;
    
    for(int i=1;i<=len;i++){
        int score;
        cin>>score;
        m1[score]=i;       
    }
//    for(map<int,int>::iterator iter=m1.begin();iter!=m1.end();iter++)
//        cout<<iter->first<<"\t"<<iter->second<<endl;
    for(int i=1;i<=len;i++){
        int score;
        cin>>score;
        m2[score]=i;       
    }
//    for(map<int,int>::iterator iter=m2.begin();iter!=m2.end();iter++)
//        cout<<iter->first<<"\t"<<iter->second<<endl;
    map<int,int>::iterator iter1=m1.end();
    map<int,int>::iterator iter2=m2.end();
    int pos=1;
    while(len>0){
//        cout<<len<<" iter is "<<iter1->second<<endl;
        if(iter1->second!=iter2->second){
            pos=1;
            cout<<iter1->second+1<<endl;       
            break;
        }
        pos=0;
        len--;
        iter1--;
        iter2--;    
    }  
    if(pos==0){
        cout<<"agree"<<endl;
    }  
    return 0;
}

