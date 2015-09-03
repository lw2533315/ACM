/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年5月6日, 下午4:25
 */

#include <cstdlib>
#include<iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    int count=0;
//    int *array=new int[12];
//    for(int i=0;i<12;i++){
//        array[i]=rand()%10;
//    }
    int array [12]={0,1,2,4,3,1,3,4,5,2,1,0};
    int small=0;
    for(int i=0;i<12;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=0;i<12;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<11;i++){
        small=array[i];
        for(int j=i;j<11;j++){
            if(small>array[j])
                small=array[j];
            if(small>array[j+1]&&small>array[i-1]){
                count++;
                cout<<"i="<<i<<" j="<<j<<" small="<<small<<" count="<<count<<endl;
            }
        }
    }
    cout<<count;
    return 0;
}

