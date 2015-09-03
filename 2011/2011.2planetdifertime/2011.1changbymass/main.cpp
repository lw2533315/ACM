/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年7月15日, 下午11:46
 */

#include <cstdlib>
#include<iostream>
#include<vector>
using namespace std;

void display(int cents) {
    if (cents / 25 > 0) {
        cout << "1*25 ";
        cents -= 25;
    }
    if (cents / 10 > 1) {
        cout << "2*10 ";
        cents -= 20;
    }
    if (cents / 10 > 0) {
        cout << "1*10 ";
        cents -= 10;
    }
    if(cents/5>0){
        cout<<"1*5 ";
        cents-=5;
        if(cents!=0)
        cout<<cents<<"*1";
        else
            cout<<"";
    }
    else {
        if(cents!=0)
        cout<<cents<<"*1";
        else 
            cout<<"";
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
         
    int cents, five;
     
    while(cin>>cents){
        cin>> five;
        if (cents / 50 > 0 && five > 0) {
            cout << "1*50 ";
            cents -= 50;
            display(cents);

        } else if (cents / 50 > 0 && five == 0) {
            cout << "2*25 ";
            cents -= 50;
            display(cents);
        } else {
            display(cents);
        }
        cout << "\n";
    }

    return 0;
}

