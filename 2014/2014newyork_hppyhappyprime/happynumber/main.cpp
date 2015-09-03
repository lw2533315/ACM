/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年5月5日, 下午4:43
 */

#include <cstdlib>
#include<vector>
#include<Exception>
#include<iostream>
#include<math.h>

using namespace std;

bool isHappyPrime(int a) {
    int store[3] = {0};
    int compareNumber = -1;
    int temp = 0;
    int compareA = a;
  
    while (compareNumber != 1) {
        store[0] = a / 100;
//        cout << "array[0]: " << store[0];
        temp = a % 100;
        store[1] = temp / 10;
//        cout << "\tarray[1]: " << store[1];
        store[2] = temp % 10;
//        cout << "\tarray[2]: " << store[2] << endl;
        compareNumber = pow(store[0], 2) + pow(store[1], 2) + pow(store[2], 2);
//        cout << "compare: " << compareNumber << endl;

        if (compareNumber == compareA) {
            return false;
        }
        a = compareNumber;
//        cout << "a: " << a << endl;
    }
    return true;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int input;
    int setNum ,loop ;
    int index = 0;
      int *a;
    cout << "enter a number between 1-`1000" << endl;
   
    try {
        if (!(cin >> setNum)) {
            cin.clear();
            cin.ignore(1024, '\n');
            throw "please input integer \n";
        } else if (setNum <= 1 || setNum >= 1000) {
            throw " out of number range (1-1000)\n";
        } else  {        
           a=new int[setNum]; 
           loop=setNum;        
        while (setNum > 0) {             
            if (!(cin >> input)) {               
                cin.clear();
                cin.ignore(1024, '\n');
                throw "please input integer\n";
            } else if (input <= 1 || input >= 10000)
                throw"out of input range(1-10000)\n";
            else {
                            
                a[index] = input;
                index++;
                setNum--;
            }
        }
        }
    } catch (const char*e) {
        cout << e;
        return 0;
    }
    catch(...){
        cout<<"wrong"<<endl;
        return 0;
    }  

    for (int i = 0; i < loop; i++) {
        if (isHappyPrime(a[i])) {
            cout << a[i] << "   Yes  " << endl;
        } else
            cout << a[i] << "   No" << endl;
    }

    delete a;



    return 0;
}

