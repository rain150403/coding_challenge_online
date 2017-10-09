/*
题目2 : 两个机器人
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
一个N × M的2D迷宫中有两个机器人。机器人A在迷宫左上角，只能向右或向下移动；机器人B在迷宫右下角，只能向左或向上移动。机器人不能移动到迷宫外。此外，由于奇怪的同步机制，这两个机器人只能同时向相反的方向移动。也就是说或者机器人A向右同时机器人B向左；或者机器人A向下同时机器人B向上移动。  

迷宫中有一些格子存在障碍，机器人不能移动到有障碍的格子上。如果某个机器人的移动方向上的下一个格子有障碍，它会停在当前格子上；这时另一个机器人不受影响，仍能向相反方向移动。迷宫范围之外可以视为全部都是障碍。

此外，两个机器人在移动中不能“相撞”。相撞是指：  

1. 两个机器人同时处在同一个格子上；

2. 两个机器人在一次移动中互换位置。  

小Hi想知道，最少经过多少次移动可以使机器人A走到右下角，同时机器人B走到左上角。

输入
第一行包含两个正整数N和M。 (1 ≤ N, M ≤ 50)  

以下是一个N × M的01矩阵，其中0表示格子上没有障碍，1表示格子上有障碍。

输出
输出一个整数代表最少移动的步数。如果目标不能达成，输出-1。

样例输入
5 5  
00001  
00000  
00100  
01000  
00000
样例输出
9
*/