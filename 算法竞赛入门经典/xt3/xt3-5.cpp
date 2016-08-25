AC:
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char maps[5][7];
char cmd[1001];

int main()
{
    int cases = 0;
    while (gets(maps[0])) {
        if (maps[0][0] == 'Z') break;
        for (int i = 1 ; i < 5 ; ++ i)
            gets(maps[i]);
        int b_x = 0,b_y = 0;
        for (int i = 0 ; i < 5 ; ++ i)
            for (int j = 0 ; j < 5 ; ++ j)
                if (maps[i][j] == ' ') {
                    b_x = i;b_y = j;
                    break;
                }
        int count = 0;
        while (~scanf("%c",&cmd[count]))
            if (cmd[count] != '0') count ++;
            else break;
        cmd[count] = 0;getchar();

        int flag = 0,x = b_x,y = b_y;
        for (int i = 0 ; cmd[i] ; ++ i) {
            switch(cmd[i]) {
                case 'A':   x = b_x-1;y = b_y; break;
                case 'B':   x = b_x+1;y = b_y; break;
                case 'L':   x = b_x;y = b_y-1; break;
                case 'R':   x = b_x;y = b_y+1; break;
            }

            if (x < 0 || x > 4 || y < 0 || y > 4) {
                flag = 1;break;
            }else {
                maps[b_x][b_y] = maps[x][y];
                maps[x][y] = ' ';
                b_x = x; b_y = y;
            }
        }

        if (cases ++) printf("\n");
        printf("Puzzle #%d:\n",cases);

        if (flag)
            printf("This puzzle has no final configuration.\n");
        else {
            for (int i = 0 ; i < 5 ; ++ i) {
                printf("%c",maps[i][0]);
                for (int j = 1 ; j < 5 ; ++ j)
                    printf(" %c",maps[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}

WA:不知原因。
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{   int num=0;
    char s[5][7];
    while(gets(s[0]))//为了处理好输入截止条件，使用每次读入一行gets;
    {                  //读取的换行符被转换为‘\0’空字符
        if(s[0][0]=='Z') break;
        int x,y,flag=1;
        for(int i=1;i<5;i++)
            {
                gets(s[i]);
            }
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
        {
            if(s[i][j]==' ')
                {
                    x=i;y=j;
                    break;  //这里以垂直方向x，水平方向y；
                }
        }
        char c;
        while(scanf("%c",&c)&&(c!='0'))
        {
            switch (c){
            case 'L':{
                if(y-1>=0){
                 s[x][y]=s[x][y-1];
                 s[x][--y]=' ';
                }
                else{
                    flag=0;
                }
                break;
                }
            case 'R':{
                if(y+1<5){
                 s[x][y]=s[x][y+1];
                 s[x][++y]=' ';
                }
                else{
                    flag=0;
                }
                break;
                }
            case 'A':{
            if(x-1>=0){
                 s[x][y]=s[x-1][y];
                 s[--x][y]=' ';
                }
                else{
                    flag=0;
                }
                break;
                }
            case 'B':{
                if(x+1<5){
                 s[x][y]=s[x+1][y];
                 s[++x][y]=' ';
                }
                else{
                    flag=0;
                }
                break;
                }
            default :
                break;
            }
            if(!flag)
                break;
        }
        if(num++) printf("\n");
        if(flag)
        {
            printf("Puzzle #%d:\n",num);
            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
            {
                putchar(s[i][j]);
                if(j<4) putchar(' ');
                if(j==4) printf("\n");
                if(i==4&&j==4) printf("\n");
            }
        }
        else{
            printf("Puzzle #%d:\nThis puzzle has no final configuration\n\n",num);
        }
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//uva227
