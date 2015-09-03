/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年7月23日, 下午10:40
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    int size = 0;
    int sum = 0;
    try {
        if (ifs) {
            string temp;
            int index=1;
            while (getline(ifs, temp)) {                
                size = atoi(temp.c_str());
                char cArray[size];
                int array[size][size];
                for (int i = 0; i < size; i++) {
                    getline(ifs, temp);
                    strcpy(cArray, temp.c_str());
                    const char* split = " ";
                    char*p;
                    p = strtok(cArray, split);
                    int column = 0;
                    while (p != NULL) {
                        array[i][column] = atoi(p);
                        p = strtok(NULL, split);
                        column++;
                    }
                }
                int row = 0, col = 0;
                sum = array[row][col];
                                while (row != size - 1 || col != size - 1) {
                    if (array[row][col + 1] < array[row + 1][col] && col + 1 < size && row + 1 < size) {
                        sum += array[row][col + 1];
                        col += 1;
                    } else if (array[row][col + 1] >= array[row + 1][col] && col + 1 < size && row + 1 < size) {
                        sum += array[row + 1][col];
                        row += 1;
                    } else if (col + 1 == size && row + 1 < size) {
                        sum += array[row + 1][col];
                        row += 1;
                    } else {
                        sum += array[row][col + 1];
                        col += 1;
                    }

                }
             
                cout <<"problem "<<index++<<": "<< sum << endl;
                
            }
        }
        else throw "no this file";

    } catch (const char*e) {
        cout << e << endl;
    }
	ifs.close();
    return 0;
}

