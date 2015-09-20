/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年9月18日, 上午9:33
 */

#include <cstdlib>
#include<iostream>


using namespace std;

/*1900年1月1日星期1， 求1901-2000年有多少个月的1日是星期天
 * 
 */
int main(int argc, char** argv) {  
    int begin=1901;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};    
    int sundayCount=0;
    int beginNumber=367;
//    bool bigMon=0;
    while(begin<2001){
        if(begin%4==0){
            mon[1]=29;
           for(int i=0;i<12;i++){
               beginNumber+=mon[i];
               if(beginNumber%7==0)
//                   cout<<beginNumber<<endl;
                   sundayCount++;
               //ifi==12 check next year jan 1
           }
           begin++;
        }
        else{
            mon[1]=28;
            for(int i=0;i<12;i++){
                beginNumber+=mon[i];
                if(beginNumber%7==0)
//                    cout<<beginNumber<<endl;
                    sundayCount++;
            }
            begin++; 
        }      
    }
    if (beginNumber%7==0)//多算了2001年1月一日
        sundayCount--;
    if(367%7==0)//少算了1901年1月一日
     sundayCount++;
    cout<<sundayCount;
    return 0;
}

