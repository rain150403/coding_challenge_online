/*
时间限制：1秒空间限制：32768K

输入一个ip地址串，判断是否合法。 
输入描述:

输入的第一行包括一个整数n(1<=n<=500)，代表下面会出现的IP地址的个数。
接下来的n行每行有一个IP地址，IP地址的形式为a.b.c.d，其中a、b、c、d都是整数。


输出描述:

可能有多组测试数据，对于每组数据，如果IP地址合法则输出"Yes!”，否则输出"No!”。

合法的IP地址为：
a、b、c、d都是0-255的整数。
示例1
输入

2
255.255.255.255
512.12.2.3
输出

Yes!
No!
*/

//运行时间：2ms 占用内存：372k

#include <string.h>
#include <stdio.h>

bool checkIP(char *s)
{
    int index = strlen(s) - 1;
    if (strlen(s) > 15)                          // 0.0.0.0 ~ 255.255.255.255
        return false;
    int i,dotCount = 0;
 
    for (i = 0; i <= index; i++)         // 判断是否存在非法输入
    {
        if (s[i] == '.')
        {
            dotCount++;
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return false;
    }
    if (dotCount != 3)                      // 合格的ip v4 地址有三个点
        return false;
 
    // 使指针首先指向字符串的最后一个字符，从后往前扫是为了方便计算
    while (1)
    {
        int num = 0, j = 1;
        while (s[index] != '.' && index >= 0)
        {
            num = num + (s[index] - '0') * j;
            j *= 10;
            index--;
        }
        index--;
        if (num > 255)
            return false;
        if (index < 0)
            break;
    }
    return true;
}
 
int main()
{
    char input[20];
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", input);
        bool a = checkIP(input);
        (a == false) ? printf("No!\n") : printf("Yes!\n");
    }
    return 0;
}
