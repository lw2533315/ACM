/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2015年10月5日, 上午10:57
 */

#include <cstdlib>
#include<iostream>
#include<vector>

using namespace std;

void printtest(int **p, int row, int col) {
    for (int i = 0; i < row; i++) {
        cout << endl;
        for (int j = 0; j < col; j++) {
            cout << p[i][j] << " ";
        }
    }
    cout << endl;
}
int** creatAry(int row, int col);
void fillBlock(int**);
void move(int**, int loc_x, int loc_y, vector<int>&, int
        , int, int, bool&);
void right(int**, int, int, int, int, int, vector<int>&, bool&);
void down(int**, int, int, int, int, int, vector<int>&, bool&);
void left(int**, int, int, int, int, int, vector<int>&, bool&);
void up(int**, int, int, int, int, int, vector<int>&, bool&);

/*
 * 
 */
int main(int argc, char** argv) {
     int empty = 4;//每次都要改的数据
    int row = 3;//自己填
    int col = 4;//自己填
    int **p = creatAry(row + 2, col + 2);//多一个边框
    int direction;//记录运行方向1,2,3,4=right,down,left,up
    int count;
    vector<int>v;//存转弯次数
    //边填成-1
    for (int i = 0; i < col + 1; i++) {
        p[0][i] = -1;
        p[row + 1][i] = -1;
    }
    for (int i = 0; i < row + 1; i++) {
        p[i][col + 1] = -1;
        p[i][0] = -1;
    }
    fillBlock(p);//根据题目要求，自己填写
    int **p1 = creatAry(row + 2, col + 2);//备份二维数组，当选取点不能完成时
    //还原数组数组
    for (int i = 0; i < row + 2; i++) {
        for (int j = 0; j < col + 2; j++) {
            p1[i][j] = p[i][j];
        }
    }
    bool go = true;//判定是否4个方向都是block
    for (int i = 1; i < row+1; i++) {
        for (int j = 1; j < col+1; j++) {//逐个查找空点
            if (p[i][j] != -1) {
                p[i][j] = -1;
                count = 0;//变相计数
                for (int k = 1; k < 5; k++) {//每个点都有4个方向可以选择
                    direction = k;
                    go = true;
                    move(p, i, j, v, direction, count, empty, go);
					if (!go) {//当不能走完时，还原数组，以便下个点使用
                go = true;
                for (int i = 0; i < row + 2; i++) {
                    for (int j = 0; j < col + 2; j++) {
                        p[i][j] = p1[i][j];
                    }
                }
            }
                }
            }
            
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    for (int i = 0; i < row + 2; i++) {
        delete p[i];
        delete p1[i];
    }
    delete []p1;
    delete [] p;
    return 0;
}

void right(int**p, int count, int empty, int dir, int x, int y, vector<int>& v, bool& go) {
//    printtest(p, 4, 5);
    if (p[x][y + 1] != -1) {//能否向右
        p[x][y + 1] = -1; //走过的为-1
        y += 1;
        empty--;
        move(p, x, y, v, dir, count, empty, go);//递归调用
    } else {
        count++;//不能向右，转向+1
        if (p[x + 1][y] != -1) {//向下判断
            p[x + 1][y] = -1;
            x += 1;
            dir = 2;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x][y - 1] != -1) {//向左判断
            p[x][y - 1] = -1;
            y -= 1;
            dir = 3;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x - 1][y] != -1) {//向上判断
            p[x - 1][y] = -1;
            x -= 1;
            dir = 4;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else {//都不行
            go = false;
        }
    }
}

void down(int**p, int count, int empty, int dir, int x, int y, vector<int>& v, bool& go) {
//    printtest(p, 4, 5);
    if (p[x + 1][y ] != -1) {
        p[x + 1][y] = -1;
        x += 1;
        empty--;
        move(p, x, y, v, dir, count, empty, go);
    } else {
        count++;
        if (p[x ][y + 1] != -1) {
            p[x][y + 1] = -1;
            y += 1;
            dir = 1;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x][y - 1] != -1) {
            p[x][y - 1] = -1;
            y -= 1;
            dir = 3;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x - 1][y] != -1) {
            p[x - 1][y] = -1;
            x -= 1;
            dir = 4;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else {
            go = false;
        }
    }
}

void left(int**p, int count, int empty, int dir, int x, int y, vector<int>& v, bool& go) {
//    printtest(p, 4, 5);
    if (p[x][y - 1] != -1) {
        p[x][y - 1] = -1;
        y -= 1;
        empty--;
        move(p, x, y, v, dir, count, empty, go);
    } else {
        count++;
        if (p[x + 1][y] != -1) {
            p[x + 1][y] = -1;
            x += 1;
            dir = 2;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x][y + 1] != -1) {
            p[x][y + 1] = -1;
            y += 1;
            dir = 1;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x - 1][y] != -1) {
            p[x - 1][y] = -1;
            x -= 1;
            dir = 4;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else {
            go = false;
        }
    }
}

void up(int**p, int count, int empty, int dir, int x, int y, vector<int>& v, bool& go) {
//    printtest(p, 4, 5);
    if (p[x - 1][y ] != -1) {
        p[x - 1][y] = -1;
        x -= 1;
        empty--;
        move(p, x, y, v, dir, count, empty, go);
    } else {
        count++;
        if (p[x + 1][y] != -1) {
            p[x + 1][y] = -1;
            x += 1;
            dir = 2;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x][y - 1] != -1) {
            p[x][y - 1] = -1;
            y -= 1;
            dir = 3;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else if (p[x ][y + 1] != -1) {
            p[x][y + 1] = -1;
            y += 1;
            dir = 1;
            empty--;
            move(p, x, y, v, dir, count, empty, go);
        } else {
            go = false;
        }
    }
}

void move(int**p, int x, int y, vector<int>&v, int dir, int count, int empty, bool& go) {
    if (empty > 0 && go) {
        switch (dir) {
            case 1: right(p, count, empty, dir, x, y, v, go);
                break;
            case 2: down(p, count, empty, dir, x, y, v, go);
                break;
            case 3: left(p, count, empty, dir, x, y, v, go);
                break;
            case 4: up(p, count, empty, dir, x, y, v, go);
                break;
        }
    } else if (!go&&empty>0) {
    } else v.push_back(count);//完成将计数存入
}

int **creatAry(int row, int col) {
    int**p = new int*[row];
    for (int i = 0; i < row; i++) {
        p[i] = new int[col];
    }
    return p;
}

void fillBlock(int **p) {//根据要求设置障碍
    p[1][1] = p[1][2] = p[1][3] = p[1][4] = p[2][1]
            = p[3][1] = p[3][4] = -1;
    //    p[1][1]=p[1][2]=p[3][5]=p[4][3]=-1;
}