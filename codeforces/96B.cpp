#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;

//一打表法,找数字累还容易漏

int lucky[]={47,74,4477,4747,4774,7447,7474,7744,444777,447477,447747,
447774,474477,474747,474774,477447,477474,477744,744477,744747,744774,747447,
747474,747744,774447,774474,774744,777444,44447777,44474777,44477477,44477747,
44477774,44744777,44747477,44747747,44747774,44774477,44774747,44774774,44777447,
44777474,44777744,47444777,47447477,47447747,47447774,
47474477,47474747,47474774,47477447,47477474,47477744,47744477,47744747,47744774,
47747447,47747474,47747744,47774447,47774474,47774744,47777444,74444777,74447477,
74447747,74447774,74474477,74474747,74474774,74477447,74477474,74477744,74744477,
74744747,74744774,74747447,74747474,74747744,74774447,74774474,74774744,74777444,
77444477,77444747,77444774,77447447,77447474,77447744,77474447,77474474,77474744,
77477444,77744447,77744474,77744744,77747444,77774444};

int main()
{
   int n ;
   cin>>n;
   int i=0;
   if(n>77774444)
    {
        cout<<4444477777<<endl;
        return 0;
    }
    else if(77747444<n)
        {
        cout<<77774444<<endl;
        return 0;
    }
   for(;lucky[i]<n;i++)
    ;
   cout<<lucky[i]<<endl;

    return 0;
}




//二使用next_permutation算法求表
int main()
{
    int num=0;//lucky 数量
    long long lucky[1000]={0};
    int startnumber[]={47,4477,444777,44447777};//字典序最小的基底
    char startnumch[10];
    for(int i=0;i<4;i++){
    sprintf(startnumch,"%d",startnumber[i]);// int to array
    do{
        lucky[num++]=atoi(startnumch);  //  array to int
    }while(next_permutation(startnumch,startnumch+(i+1)*2));

    }
    lucky[num++]=4444477777;//exceed int
    int n,i=0;
    cin>>n;
    while(lucky[i]<n)
    {
     i++;
    }
    cout<<lucky[i]<<endl;
    return 0;
}

//关于next_permutation 函数 详见http://blog.sina.com.cn/s/blog_9f7ea4390101101u.html

/******************************************************************************/
这是一个求一个排序的下一个排列的函数，可以遍历全排列,要包含头文件<algorithm>
 下面是以前的笔记    与之完全相反的函数还有prev_permutation
  
  
 (1) int 类型的next_permutation
  
 int main()
 {
  int a[3];
 a[0]=1;a[1]=2;a[2]=3;
  do
 {
 cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
 } while (next_permutation(a,a+3)); //参数3指的是要进行排列的长度
  
 //如果存在a之后的排列，就返回true。如果a是最后一个排列没有后继，返回false，每执行一次，a就变成它的后继
  
  
 }
  
 输出：
  
  1 2 3
  1 3 2
  2 1 3
  2 3 1
  3 1 2
  3 2 1
  
  
 如果改成 while(next_permutation(a,a+2));
 则输出：
  1 2 3
  2 1 3
  
 只对前两个元素进行字典排序
 显然，如果改成 while(next_permutation(a,a+1)); 则只输出：1 2 3
  
  
  
 若排列本来就是最大的了没有后继，则next_permutation执行后，会对排列进行字典升序排序,相当于循环
  
  int list[3]={3,2,1};
 next_permutation(list,list+3);
 cout<<list[0]<<" "<<list[1]<<" "<<list[2]<<endl;
  
 //输出: 1 2 3

  
  
  
  
 (2) char 类型的next_permutation
  
 int main()
 {
  char ch[205];
 cin >> ch;
  
 sort(ch, ch + strlen(ch) );
 //该语句对输入的数组进行字典升序排序。如输入9874563102 cout<<ch; 将输出0123456789,这样就能输出全排列了
  
  char *first = ch;
  char *last = ch + strlen(ch);
  
  do {
 cout<< ch << endl;
 }while(next_permutation(first, last));
  return 0;
 }
  
 //这样就不必事先知道ch的大小了，是把整个ch字符串全都进行排序
 //若采用 while(next_permutation(ch,ch+5)); 如果只输入1562，就会产生错误，因为ch中第五个元素指向未知
 //若要整个字符串进行排序，参数5指的是数组的长度，不含结束符

  
  
  
  
  
 (3) string 类型的next_permutation
  
 int main()
 {
  string line;
  while(cin>>line&&line!="#")
 {
  if(next_permutation(line.begin(),line.end())) //从当前输入位置开始
 cout<<line<<endl;
  else cout<<"Nosuccesor\n";
 }
 }
  
  
  
 int main()
 {
  string line;
  while(cin>>line&&line!="#")
 {
 sort(line.begin(),line.end());//全排列
 cout<<line<<endl;
  while(next_permutation(line.begin(),line.end()))
 cout<<line<<endl;
 }
 }
  
  
  
  
  
  
  next_permutation 自定义比较函数
  
  
 #include<iostream> //poj 1256 Anagram
 #include<string>
 #include<algorithm>
 using namespace std;
 int cmp(char a,char b) //'A'<'a'<'B'<'b'<...<'Z'<'z'.
 {
  if(tolower(a)!=tolower(b))
  return tolower(a)<tolower(b);
  else
  return a<b;
 }
 int main()
 {
  char ch[20];
  int n;
 cin>>n;
  while(n--)
 {
 scanf("%s",ch);
 sort(ch,ch+strlen(ch),cmp);
  do
 {
 printf("%s\n",ch);
 }while(next_permutation(ch,ch+strlen(ch),cmp));
 }
  return 0;
 }	
