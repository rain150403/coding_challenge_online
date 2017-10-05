/*
题目1 : 顺序三元组
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
给定一个长度为N的数组A=[A1, A2, ... AN]，已知其中每个元素Ai的值都只可能是1, 2或者3。

请求出有多少下标三元组(i, j, k)满足1 ≤ i < j < k ≤ N且Ai < Aj < Ak。  

输入
第一行包含一个整数N  

第二行包含N个整数A1, A2, ... AN。(1 ≤ Ai ≤ 3)  

对于30%的数据，1 ≤ N ≤ 100  

对于80%的数据，1 ≤ N ≤ 1000  

对于100%的数据，1 ≤ N ≤ 100000  

输出
一个整数表示答案

样例输入
6
1 3 2 1 2 3
样例输出
3
*/

//运行时间：28ms, 占用内存：0M

#include <iostream>

using namespace std;

using ll = long long;

int N;
int v[100000 + 10];

int main () {
  cin >> N;
  for(int i = 0; i < N; ++i) 
    cin >> v[i];

  ll t1 = 0;
  ll t12 = 0;
  ll t123 = 0;

  for(int i = 0; i < N; ++i) {
    const int c = v[i];
    if (c == 1) {
      t1++;
    } else if (c == 2) {
      t12 += t1;
    } else if (c == 3) {
      t123 += t12;
    }
  }

  cout << t123 << endl;
}
