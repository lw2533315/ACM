/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年11月18日, 下午11:43
 */

#include <cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

bool isPrime(unsigned long n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    int input;
    while (!ifs.eof()) {
        ifs>>input;
        if (input < 3 || input == 4 || input == 5 || input == 6)
            cout << "no such base" << endl;
        else if (3 == input) {
            cout << 4 << endl;
        }
        else if (isPrime(input - 3)) {
            cout << input - 3 << endl;
        } else {
            int n = 4;
            while ((input - 3) % n != 0) {
                n++;
            }
            cout << n << endl;
        }
    }
    ifs.close();
    return 0;
}

