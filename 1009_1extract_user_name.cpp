/*
题目1 : 提取用户名
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
在现在的各种互联网应用中，在一段文字中使用'@'字符来提起一名用户是流行的做法。  

例如：

"@littleho submitted his code 30 times before he got passed the system test."  

其中littleho就是一个用户名。我们规定在一段文字中，'@'字符之后一段连续的、非空的大小写英文字母组成的字符串被视为提起的用户名。  

给定一段文字，请你输出其中所有提到的用户名。

输入
一行文本，只包含大小写字母、标点符号和空格。长度不超过800。

输出
按文本中的顺序输出所有提到的用户名，之间用一个空格隔开。重复提到的相同用户名也重复输出。

样例输入
@abc:@@,@littleho's code is so confusing. @abc.
样例输出
abc littleho abc
*/

//运行时间：0ms 占用内存：0MB

//一般的编程问题这些头文件基本就够用了，平常都摆上也没事
//#include <iostream>
#include <cstdio>
#include <cstring>
//#include <cstdlib>
#include <algorithm>
//#include <map>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <set>

//using namespace std;

char ch[1000];
string ans[1000];
int n, m;

void work(){
    gets(ch);
    n = strlen( ch );
    for( int i = 0; i < n; ++i ){
        if( ch[i] == '@' ){
            string s = "";
            for( i = i + 1; i < n; ++i ){
                if( ( ch[i] >= 'A' && ch[i] <= 'Z' ) || ( ch[i] >= 'a' && ch[i] <= 'z' ) ){
                    s += ch[i];
                }else{
                    break;
                }
            }
            if( s != "" ){
                ans[m++] = s;
            }
            i--;
        }
    }
    
    for( int i = 0; i < m; ++i ){
        printf( "%s", ans[i].c_str() );
        printf( i == m-1? "\n":" " );
    }
}

int main(){
    
    int TC = 1;
    //scanf( "%d", &TC );
    for( int i = 1; i <= TC; ++i ){
        work();
    }
}
