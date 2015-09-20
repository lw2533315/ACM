/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年9月18日, 上午10:54
 */

#include <cstdlib>
#include<iostream>

#include<math.h>
using namespace std;
bool isPrime(int n);
bool cirPrime(int*, int);
int digit(int n);
bool isCircle(int*p, int d);
int* fillAry(int n, int d);

/*1到1000000中质数切旋转后仍为质数的数的个数
如197,971,719 就符和要求
 * 
 */
int main(int argc, char** argv) {
    int count = 1;//2符和；
    int d = 0;

    for (int i =1; i < 1000000; i=i+2) {
        
        if (isPrime(i)) {//先找出所有质数
            int d = digit(i);//判断每个质数有多少位
            int *p = new int[d];
            {
                p = fillAry(i, d);//将质数转换成对应数组
                if (cirPrime(p, d)) {//把数中含有0,2,4,5,6,8这些数字的数剔除，因为他们
				//旋转后不再是质数
                    if (isCircle(p, d)) {//旋转
                        
                        count++;
                    }
                }
            }
        }
    }
    cout << count;
	delete [] p;
    return 0;
}

int* fillAry(int n, int d) {
    int *ary = new int[d];
    for (int i = 0; i < d; i++) {
        int m=pow(10,d-1-i);
        ary[i] = n /m;
        n= n%m;
       
    }
        
    return ary;
}

bool cirPrime(int *p, int d) {
    for (int i = 0; i < d; i++) {
            if ((p[i] == 0 || p[i] == 2 || p[i] == 4 ||
                p[i] == 5 || p[i] == 6 || p[i] == 8)&&d!=1){
            return false;
        }
    }
        return true;
}

int digit(int n) {
    int sum = 0;
    while (n) {
        sum++;
        n /= 10;
    }return sum;
}

bool isPrime(int n) {
    if (n <=3)
        return n > 1;
    else if (n % 2 == 0 || n % 3 == 0) {
        return false;

    } else {
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

bool isCircle(int *p, int d) {
    int *temp=new int[d];
    
    for (int i = 0; i < d; i++) {//rotation d times;
        int cof = d - 1;//power;
        for (int k = 0; k < d; k++) {
            temp[k] = p[(k + i) % d];//旋转后产生新的数组
          
        }
             int test = 0;
        for (int j = 0; j < d; j++) {
            test = test+temp[j] * pow(10, cof);
            cof--;
        }       
    
        if (!isPrime(test)){
           
            delete []temp;
            return false;
        }
    }
    delete [] temp;
    return true;
}