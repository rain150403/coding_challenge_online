/*
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
给定一个形如"HH:MM:SS"的时间(范围从00:00:00至23:59:59)。假设我们可以重复使用其中出现的数字来组成一个新的时刻，你能求出在给定时间之后并且最接近给定时间的时刻是多少吗？  

注意答案允许是第二天的时刻。

输入
第一行一个整数 T，代表测试数据的组数。(1 ≤ T ≤ 1000)  

以下T行每行一个形如"HH:MM:SS"的时间。

输出
对于每组数据输出一个形如"HH:MM:SS"的时刻。

样例输入
2  
15:10:30  
23:59:59
样例输出
15:10:31  
22:22:22

*/

///运行时间：1269ms,占用内存：0MB

//考点：字符串

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
	int gao(string s){       //把字符串转换成整数
		int hh = ( s[0] - '0' ) * 10 + s[1] - '0';
		int mm = ( s[3] - '0' ) * 10 + s[4] - '0';
		int ss = ( s[6] - '0' ) * 10 + s[7] - '0';
		return hh * 3600 + mm * 60 + ss;
	}

	string rev( int i ){   //  把接下来的每一个时刻都转换成字符串00：00：00
		int hh = i / 3600;
		int mm = (i / 60) % 60;
		int ss = i % 60;

		string res;
		if( hh < 10 ){
			res = "0" + to_string(hh);
		}else{
			res = to_string(hh);
		}
		res.push_back(':');
		if(mm < 10){
			res.append("0" + to_string(mm));
		}else{
			res.append( to_string(mm) );
		}
		res.push_back(':');
		if(ss<10){
			res.append( "0" + to_string(ss) );
		}else{
			res.append(to_string(ss));
		}
		return res;
	}

public:
	string nextClosestTime( string time ){
		vector<bool> foo(10, false);        ///哈希表，散列， 一共只有10个数字
		foo[time[0] - '0'] = true;
		foo[time[1] - '0'] = true;
		foo[time[3] - '0'] = true;
		foo[time[4] - '0'] = true;
		foo[time[6] - '0'] = true;
		foo[time[7] - '0'] = true;

		int start = gao(time);      //把字符串时间转换成整数，比如24*3214s
		for( int i = start + 1; i < 24 * 3600; ++i ){  //从这一时刻起到23：59：59，这样才是最近的
			string tmp = rev(i);    //这一时刻的字符串形式，，并且判断这个值是否有效（即是否每个数字都在给定的时间里）
			if(foo[tmp[0] - '0'] && foo[tmp[1] - '0'] && foo[tmp[3] - '0'] && foo[tmp[4] - '0'] && foo[tmp[6] - '0'] && foo[tmp[7] - '0']){
				return tmp;  //如果在23：59：59之前能找到这个值，那就直接返回这个就行了，下面不运行
			}
		}
		for( int i = 0; i <= start; ++i ){  //  因为01：23：56不比 23：46：56大（不能比较大小），但是却在它的后面，所以分开来算
			string tmp = rev(i);
			if(foo[tmp[0] - '0'] && foo[tmp[1] - '0'] && foo[tmp[3] - '0'] && foo[tmp[4] - '0'] && foo[tmp[6] - '0'] && foo[tmp[7] - '0']){
				return tmp;
			}
		}
	}
};


int main(){
	Solution sol;
	int t;
	cin >> t;     //另一种输入方式
	while(t--){
		string time;
		cin >> time;
		cout << sol.nextClosestTime(time) << endl;
	}
	return 0;
}
