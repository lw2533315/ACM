/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年9月7日, 下午9:37
 */

#include <cstdlib>
#include<fstream>
#include<cstring>
#include<iostream>
#include<iomanip>

using namespace std;
//int *creatAry(int);

/*
 * 
 */
int main(int argc, char** argv) {
    int index2;
    ifstream ifs;
    ifs.open("input.txt");
    string s;
    try {
        if (ifs) {
            int count = 0, row = 0;
             double array[30][3]={0};//存数据
//             cout<<"array"<<array[0][0];
            while (getline(ifs, s)) {//判断文件结尾
               

                if (s.length()!=1) {//如果不为空白行                    
                    string temp;
                    while (s.length() > 1) {                     
                        int index = s.find(" ");//找到字符串中空格
//                        cout<<"index is "<<index<<"  ";
                        if (index==-1){//字符串没有空格，证明只有一个数字
                         temp = s.substr();//抓出来
//                         cout<<"temp is "<<temp<<endl;
                       
                         s="";   //将s设置为空，跳出while 循环 
                        }
                        else {//如果字符串中有空格
                            temp=s.substr(0,index);//空格前第一个数字
//                            cout<<"temp is "<<temp<<endl;
                            s=s.substr(index+1);//s 设为空格后的字符串
                              index2=s.find(" ");

                            while(index2==0){//避免多个空格在数字间
                                s=s.substr(index2+1);
                                index2=s.find(" ");
                                if (index2==-1)
                                    break;
                            }
s;
                        }
                        double numTemp=atoi(temp.c_str());
                        if (count % 2 == 0) {//存入数字
                            array[row][0] =numTemp;
//                            cout<<"row is "<<row<<"; "<<array[row][0]<<endl;;
                             count++;
                        } else {
                            array[row][1] = numTemp;
                            array[row][2] = array[row][0] / array[row][1];
//                             cout<<"row is "<<row<<"; "<<array[row][1]<<endl<<"ratio is "
//                                     <<array[row][2]<<endl;
                            row++;
                            count++;
                        }
                    }
                } else {//读到空白行输出
//                    cout<<"here~~~~~~~~~~~~~~~~~~~~~~`"<<endl;
//                    for(int i=0;i<row;i++)
//                    cout<<"before oout the row is "<<row<<endl;
//                    cout<<"2,2 is "<<array[2][2]<<endl;
                    double a = 0, b = 0; //可以先按3排序
                    double tempArray[2];
                    for (int i = 0; i < row; i++) {
                        for (int j = 0; j < row-1; j++) {
                            if (array[j][2] > array[j + 1][2]) {
                                tempArray[0] = array[j][0];
                                tempArray[1] = array[j][1];
                                tempArray[2] = array[j][2];
//                              s  cout<<"1  d"<<tempArray[2]<<"~"<<endl;
                                array[j][0]=array[j+1][0];
                                array[j][1] = array[j + 1][1];
                                array[j][2] = array[j + 1][2];
                                array[j + 1][0] = tempArray[0];
                                array[j + 1][1] = tempArray[1];
                                array[j + 1][2] = tempArray[2];
                            }
                        }
                    }
                    for (int i = 0; i < row; i++) {
//                        cout<<array[i][0]<<"  "<<array[i][1]<<endl;
                        a += array[i][0];
                        b += array[i][1];
//                        cout<<"分子"<<a<<  "   分母"<<b<<endl;
                                
                    }
                    cout<<setprecision(1)<<fixed<<a/b*100<<" ";
                    a=(a-array[0][0]);
                    b=(b-array[0][1]);
                     cout<<setprecision(1)<<fixed<<a/b*100<<" ";
                    a=(a-array[1][0]);
                    b=(b-array[1][1]);
                     cout<<setprecision(1)<<fixed<<a/b*100<<" ";
                    a=(a-array[2][0]);
                    b=(b-array[2][1]);
                   cout<<setprecision(1)<<fixed<<a/b*100<<endl;
                    count == 0;
                    
                    row=0;
                    
                    continue;
                }
            }
        } else throw "no this file";

    } catch (const char*e) {
        cout << e << endl;
    }
    return 0;
}

