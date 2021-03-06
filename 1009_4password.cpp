/*
题目4 : 小Hi和小Ho的密码
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi和小Ho一直使用加密的方式传输消息。他们使用如下方法来生成一组密码：  

首先小Hi和小Ho选择一个整数 n = pk（其中p质数、k是正整数，也即n是质数或质数的幂）。  

其次，他们会求出两个整数a和b满足0 < a < b < n，并且{{1, a, b}, *(n)}恰好构成一个合法的群，其中*(n)表示模n意义下的乘法。  

最后小Hi选择a作为密钥、小Ho选择b作为密钥。

给定一个整数n= pk，你能帮小Hi和小Ho求出各自的密钥吗？

输入
第一行一个整数T表示数据组数，接下来T行每行一个整数n，意义和描述一样。

1 ≤ T ≤ 50  

对于30%的数据，满足n ≤ 100

对于60%的数据，满足n ≤ 106

对于100%的数据，满足n ≤ 109

输出
输出T行，每行3个整数表示1, a, b代表群的3个元素。如果不存解，输出一个-1。

样例输入
1
7
样例输出
1 2 4
*/

//运行时间： 占用内存：
