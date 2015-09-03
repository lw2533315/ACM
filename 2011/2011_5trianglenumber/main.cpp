/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年5月29日, 下午12:24
 */

#include <cstdlib>
#include<iostream>
#include<math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    long num;
    cin>>num;
    int cNum=1;
    if(2*num==int(sqrt(2*num))*(int(sqrt(2*num))+1)){        
        for(int i=1;i<=num;i++){
            if(num==cNum&&cNum<=num){
                cout<< i<<endl;
                return 0;
            }
            else if(cNum<num){
                cNum+=i+1;
            }
            else{
                cout<<"bad"<<endl;
            }
        }
    }
    else{
        cout<< "no"<<endl;
    }       

    return 0;
}

