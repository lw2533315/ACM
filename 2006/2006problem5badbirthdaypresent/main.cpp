/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年8月4日, 下午10:37
 */

#include <cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

void sort(int array[][3], int size, int row) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (array[row][j] > array[row][j + 1]) {
                int temp;
                temp = array[row][j];
                array[row][j] = array[row][j + 1];
                array[row][j + 1] = temp;
            }
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    string temp;
    try {
        if (ifs) {
            while (getline(ifs, temp)) {
                int row = atoi(temp.c_str());
                int array[row][3];
                int iTemp;
                int size = row;
                row--;
                while (row >= 0) {
                    ifs >> array[row][0];
                    ifs >> array[row][1];
                    ifs >> array[row][2];
                    sort(array, size, row); //每行排序从小到大
                    row--;
                    getline(ifs,temp);//此处因为ifs不会读取换行符，所以要用
                    //getline将空行读取。    
                }
                for (int i = 0; i < size; i++) {//每列按第一个元素按小到大排序
                    for (int j = 0; j < size - 1; j++) {
                        int temp[3];
                        if (array[j][0] > array[j + 1][0]) {
                            temp[0] = array[j][0];
                            temp[1] = array[j][1];
                            temp[2] = array[j][2];
                            array[j][0] = array[j + 1][0];
                            array[j][1] = array[j + 1][1];
                            array[j][2] = array[j + 1][2];
                            array[j + 1][0] = temp[0];
                            array[j + 1][1] = temp[1];
                            array[j + 1][2] = temp[2];
                        }
                    }
                } /*开始判断层数排序后只要下一层每个长度数据都大于对应的长度数据
                   * 即可认为是可以放入的纸盒
                   */          
                int step = 1;
                int aTemp[3];
                for (int i = 0; i < size; i++) {
                    aTemp[0] = array[i][0]; //把第i行复制出来，因为下面会被覆盖掉
                    aTemp[1] = array[i][1];
                    aTemp[1] = array[i][2];
                    int stepTemp = 1;
                    for (int j = i; j < size - 1; j++) {
                        if (array[i][0] < array[j + 1][0] && array[i][1] < array[j + 1][1] && array[i][2] < array[j + 1][2]) {
                            stepTemp++;
                            array[i][0] = array[j + 1][0];
                            array[i][1] = array[j + 1][1];
                            array[i][2] = array[j + 1][2];
                        }
                    }
                    if (stepTemp > step)
                        step = stepTemp;
                    array[i][0] = aTemp[0]; //把被覆盖掉的i行还原
                    array[i][1] = aTemp[1];
                    array[i][2] = aTemp[2];
                }
                cout << step << endl;
            }
        } else throw "no the file";
    } catch (const char*e) {
        cout << e << endl;
    }
    return 0;
}

