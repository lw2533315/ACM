/* 
 * File:   newmain.cpp
 * Author: Administrator
 *
 * Created on 2015年3月30日, 下午10:53
 */

#include<cstdlib>
#include<iostream>
#include<Exception>

using namespace std;

int main() {
    bool t = true;
    while (t) {
        cout << "enter(1-4)" << endl;
        int choice = 0;
        try {
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1024, '\n');
                throw"plese input interger";
            } else {
                if (choice < 1 || choice > 4)
                    throw "out of range";
            }
        } catch (const char* e) {
            cout << e << endl;
        } catch (...) {
            cout << "wrong" << endl;
        }
        switch (choice) {
            case 1: cout << "1.game";
                break;
            case 2: cout << "2 game";
                break;
            case 3: cout << "3 game";
                break;
            case 4: t = false;
                break;
        }
    }
    return 0;
}