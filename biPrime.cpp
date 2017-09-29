//具体题目忘了，大概是找到第k小的素数，所谓双素数：本身和它的反转都是素数的数，比如13和31.

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> sushu;
map<int,int> mmap;

bool isPrime(int n){
    int i;
    for(i = 2; i <= (int)sqrt(n); i ++)
        if(n%i == 0) return false;
    return true;
}

int main(){
    for(int i=10;i<=1000000;i++){
        if(isPrime(i)){
        	sushu.push_back(i);
            mmap[i]=1;
        }
    }
    vector<int> r;
    for(int i=0;i<sushu.size();i++){
        string t=to_string(sushu[i]);
        string ttt=t;
        reverse(t.begin(),t.end());
        if(t==ttt)
            continue;
        int tt=stoi(t);
        if(mmap[tt])
            r.push_back(sushu[i]);
    }
    int k;
    cin>>k;
    if(k>=r.size())
        cout<<-1<<endl;
    else
        cout<<r[k-1]<<endl;
    return 0;
}
