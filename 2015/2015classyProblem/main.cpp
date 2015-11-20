/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年11月19日, 上午12:00
 */

#include <cstdlib>
#include<vector>
#include<fstream>
#include<iostream>
//#include<iomanip>

using namespace std;

void quickSort(vector<pair<string, long double> >&v, int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        vector< pair<string, long double> >x(1);
        x[0] = v[l];
        while (i < j) {
//            cout << "outer loop" << endl;
            while (i < j && v[j].second <= x[0].second) {
//                cout << "inner loop" << endl;
                if (v[j].second == x[0].second) {
                    if (v[j].first.compare(x[0].first) < 0) {
//                        cout << "determine the string" << endl;
                        break;
                    }
                }
                j--;
            }
            if (i < j) {
                v[i] = v[j];
                i++;
            }
            while (i < j && v[i].second >= x[0].second) {
//                  if (v[i].second == x[0].second) {
//                    if (v[i].first.compare(x[0].first) > 0) {
//                        cout << "determine the string" << endl;
//                        break;
//                    }
//                }
                i++;
            }
            if (i < j) {
                v[j] = v[i];
                j--;
            }
        }
        v[i] = x[0];
        quickSort(v, l, i);
        quickSort(v, i + 1, r);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream ifs;
    ifs.open("input.txt");
    vector<pair<string, long double> >v;
    string str;
    while (getline(ifs, str)) {
        int nameIndex = str.find(':');
        //        cout<<"index is "<<nameIndex<<endl;
        string name = str.substr(0, nameIndex);
        //        cout<<name<<endl;
        int end = str.find('c');
        int len = end - nameIndex - 3; //key part's length
        str = str.substr(nameIndex + 2, len);
        //        cout<<str<<endl;/
        string temp = str;
        if (str[0] == 'm') {
            while (temp[0] == 'm') {
                temp = temp.substr(0 + 7, len - 7);
            }
            str = temp;
        }
        //        cout<<str<<endl;
        len = str.length();
        double coef = 1;
        long double count = 0;
        int pos = len - 1;
        for (int i = pos; i >= 0; i--) {
            //            cout<<"i is "<<i<<endl;
            //            cout<<"xishu is "<<coef<<endl;
            if (str[i] == '-') {
                if (str[i + 1] == 'u') {
                    count = count + 3 * coef;
                } else if (str[i + 1] == 'm') {
                    count = count + 2 * coef;
                } else count = count + 1 * coef;
                coef *= (1.0 / 4);
            }
            if (i == 0) {
                if (str[i] == 'u') {
                    count = count + 3 * coef;
                } else if (str[i] == 'm') {
                    count = count + 2 * coef;
                } else count = count + 1 * coef;
                coef = coef * (1.0 / 4);
            }
        }
        //        cout<<"count is "<<count<<endl;
        v.push_back(make_pair(name, count));

    }
    quickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first <<endl;
//    << " : " << fixed << setprecision(30) << v[i].second << endl;
    ifs.close();
    return 0;
}

