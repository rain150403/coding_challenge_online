/*题目1 : 逃离迷宫4
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi被坏女巫抓进一座由无限多个格子组成的矩阵迷宫。

小Hi一开始处于迷宫(x, y)的位置，迷宫的出口在(a, b)。小Hi发现迷宫被女巫施加了魔法，假设当前他处在(x, y)的位置，那么他只能移动到(x+y, y)或者(x, x+y)的位置上。

小Hi想知道自己能不能逃离迷宫。

输入
第一行包含一个整数T，代表测试数据的组数。  

以下N行每行包含4个整数x, y, a, b，表示起点在(x, y)，出口在(a, b)。  

对于30%的数据，1 ≤ T ≤ 10, 1 ≤ x, y, a, b ≤ 100  

对于80%的数据，1 ≤ T ≤ 1000, 1 ≤ x, y, a, b ≤ 1000  

对于100%的数据，1 ≤ T ≤ 10000, 1 ≤ x, y, a, b ≤ 109

输出
对于每组数据输出一行YES或者NO，表示小Hi是否能逃离迷宫。

样例输入
2  
1 1 8 13  
2 2 100 101
样例输出
YES  
NO*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int x,y,a,b;
bool solve(){
    while(a&&b){
        if(x==a&&y==b)return 1;
        if(a>b){
            if(y==b){
                if(a>=x){
                    return (a-x)%b==0;
                }
                else return 0;
            }
            a%=b;
        }
        else{
            if(x==a){
                if(b>=y){
                    return (b-y)%a==0;
                }
                else return 0;
            }
            b%=a;
        }
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        puts(solve()?"YES":"NO");
    }
    return 0;
}
