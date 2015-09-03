/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年4月18日, 上午11:33
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<vector>
//用vector 存读出的字符串
//一行一行读
//使用try catch throw 判断文件打开是否成功
//用比较法排序，然后在原vector中删除对应字符串，同时存入新字符串

using namespace std;
bool smaller(string str,char c1,char c2);

int main(){
    ifstream ifs;
    string modle;
    string temp;
    int bigLen=0;  //最长的字符串
    vector<string>v1;
    try{
   ifs.open("input.txt");   
   if(ifs){
       getline(ifs,modle);
       modle=" "+modle;
       cout<<modle<<endl;
//       while(!ifs.eof()){//判断文件末尾
//           getline(ifs,temp);
//           v1.push_back(temp);           
//       } 
       
       while(getline(ifs,temp)){           
           v1.push_back(temp);
           if(temp.length()>bigLen)
               bigLen=temp.length();//寻找最长字符串
       }       
   }
   else throw" no this file"; 
    }
    catch(const char*e){
        cout<<e<<endl;                
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;      
    } 
    vector<string>v2(v1.size());
    while(v1.size()>0){
    string temp=v1[0];
    int recorder=0;
    for(int i=1;i<v1.size();i++){        
        int j=0;        
        while(j<bigLen){           
            if(v1[i][j]!=temp[j]){
                if(smaller(modle,v1[i][j],temp[j])){
                    temp=v1[i];    
                    recorder=i;
                }
                else {j++;}
                break;
            }
            else {
                j++;
            }           
        }
    }
    v1.erase(v1.begin()+recorder);//删除找到的字符串
    v2.push_back(temp);
    }
    for(int i=0;i<v2.size();i++)
        cout<<v2[i]<<endl;      
    return 0;
}
bool smaller(string str,char a1,char a2){//判断哪个字符串在前
    
    int index1,index2;
    index1=str.find(a1);
    index2=str.find(a2);
    return index1<=index2;
}