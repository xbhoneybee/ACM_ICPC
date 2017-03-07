# C语言
#### 文件读写
重新定向：在main函数入口加入
```
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
```
#### 输入输出

#### cstdlib
rand()返回0到32767之间的一个整数
srand(time(NULL));在程序开始执行一次以当前时间初始化随机种子，确保每次程序运行使用的是不同套的随机数。 

#### 进制 
0x3f3f3f3f = ‭1061109567

0x7f7f7f7f = ‭2139062143‬
# c++
#### 输入输出
getline(cin,str);在使用时前面如果刚输入数字并回车会吃掉回车产生错误，此时要多用一次getline
#### goto
```
label :
{}
goto label;
```
## C++  STL
### 库函数
#### sort
sort处理vector
```
sort(v.begin(), v.end(),less<int>());//升
sort(v.begin(), v.end(),greater<int>());//降
```
lower_bound(begin,end,val)

返回大于或等于val的第一个位置,一般要-begin才是其在数组中的下标值
### string
string.substr(start,length);

string gap(60,'-'); //直接生成字符串

reverse(str.begin(), str.end()); 翻转 

string /int
```
string getstring ( const int n )
{
    std::stringstream newstr;
    newstr<<n;
    return newstr.str();
}
int getint ( string s )
{
    return atoi(s.c_str());
}
```
string toupper/tolower
```
void Toupper(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::toupper);
}
void Tolower(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::tolower);
}
```
### vector
```
vec.assign(size,value) //对vector vec 的size 个赋值为value
vector   vec（size ， value）初始化创建一个vector 确定大小和value
vector <int >vec (10) 确定vector的capacity 为10 
vector <int > vec[10] 建立了一个向量数组  vector[i]表示 一个向量
vector<int > vec2(vec1) 复制
vec.insert(vec.begin()+2,5) 向迭代器 指向元素前插入新元素 5
vec.front ()  第0个成员 vec.back()最后一个成员;
vec.at(4)  下标为4成员
vec.pop_back()删除尾元素
vec.erase（it） 删除迭代器所指向元素
vec.erase（first,last）删除迭代器所指定序列【  first ，last）
```
##### 复杂度 
由数组构成的vector，其inser/erase/find 都是O（N）
### pair
pair<int,int>p;//默认构造函数赋值0,0


### priority_queue
优先队列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序出队（默认为大者优先，出队函数是pop(),有点像栈，队尾（栈顶）先出。

也可以通过指定算子来指定自己的优先顺序。priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比较算子。其中后两个都可以省略
默认容器为vector，默认算子为less，即小的往前排，大的往后排（出队时序列尾的元素出队）。

priority_queue<int> q1;

priority_queue< pair<int, int> > q2; 

priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队

如果要定义自己的比较算子，方法有多种，这里介绍其中的一种：重载比较运算符。优先队列试图将两个元素x 和y 代入比较运算符(对less 算子，调用x<y，对greater 算子，调用x>y)，若结果为真，则x 排在y 前面，y 将先于x 出队，反之，则将y 排在x 前面，x 将先出队。
看下面这个简单的示例：
```
class T{
public:
int x, y, z;
T(int a, int b, int c):x(a), y(b), z(c){}
};
bool operator < (const T &t1, const T &t2){
return t1.z < t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
```
###### 复杂度
push pop 都是 O（N）；

### map
 map<string,string>::iterator it;
 
 在遍历时，*it是一个pair，it->first 是key it->second 是value
 
 map.erase(iterator);erase 之后iterator 自动指向下一个位置；而且可以使用iterator = map.find（key）确定位置
 ```
std::map<std::string, std::string > mapTest; 
bool TestVal(const std::string & val);
std::map<std::string,std::string>::iterator it = mapTest.begin();
while(it!=mapTest.end())
{
        if(TestVal(it->second))
        {
                mapTest.erase(it++);
        }
            else
                it++;
}
```
该方法中利用了后++ 的特点，这个时候执行mapTest.erase(it++);这条语句分为三个过程 

1. 先把it的值赋值给一个临时变量做为传递给erase的参数变量
2. 因为参数处理优先于函数调用，所以接下来执行了it++操作，也就是it现在已经指向了下一个地址。
3. 再调用erase函数，释放掉第一步中保存的要删除的it的值的临时变量所指的位置。
 ### hash_map
insert ()  erase()  [] ： O(1)
 ### deque
 deque(int nSize,const T&t):创建一个deque,元素个数为nSize,且值均为t

que.pop_front();弹出队首元素 不返回值

 ### list 
 不支持[]
 #####  复杂度 
 insert   erase  O(1)
 
 sort O (nlgn)(lg n) 