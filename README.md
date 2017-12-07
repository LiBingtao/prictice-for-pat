PAT总结
=================

[toc]

# PAT中常用的STL容器

## 顺序容器

### vector

```c++
#include<vector>
using namespace std;
vector<DataType> v;
v.push_back(Data);    //尾部添加元素
int size = v.size(); //元素个数
bool isEmpty = v.empty(); //是否为空
v.pop_back(); //删除末尾元素
v.clear(); //清空元素
//遍历
int length = v1.size();
for(int i=0;i<length;i++)
{
    cout<<v[i];
}
```

### queue

```c++
#include<queue>
queue<Datatype> q;
q.push(Data); //入队
q.pop(); //队首出队
q.front(); //队首元素
q.back(); //队尾元素
q.empty(); //判断队列是否为空
q.size(); //队列元素个数
```

### priority_queue

```c++
#include <iostream>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a,int b){
    return a>b;
    }
};
/**************************************
struct Node{
    int a
};
bool operator<(Node a,Node b){
    return a>b;
}
**************************************/
int main(){
    priority_queue<int,vector<int>,cmp> q;
    //priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    for(int i=9;i>=0;i--){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}
```

### stack

```c++
#include<stack>
stack<Datatype> s;
s.push(Data); //入栈
s.pop(); //出栈
s.top(); //访问栈顶元素
s.empty(); //判断栈是否为空
s.size(); //栈元素个数
```

## 关联容器

### map

```c++
#include<map>
//1.定义和初始化
map<int,string> map1;                  //空map

//2.常用操作方法
map1[3] = "Saniya";                    //添加元素
map1.insert(map<int,string>::value_type(2,"Diyabi"));//插入元素
//map1.insert(pair<int,string>(1,"Siqinsini"));
map1.insert(make_pair<int,string>(4,"V5"));
string str = map1[3];                  //根据key取得value，key不能修改
map<int,string>::iterator iter_map = map1.begin();//取得迭代器首地址
int key = iter_map->first;             //取得key
string value = iter_map->second;       //取得value
map1.erase(iter_map);                  //删除迭代器数据
map1.erase(3);                         //根据key删除value
map1.size();                       //元素个数
map1.empty();                       //判断空
map1.clear();                      //清空所有元素

//3.遍历
for(map<int,string>::iterator iter = map1.begin();iter!=map1.end();iter++)
{
    int keyk = iter->first;
    string valuev = iter->second;
}
```

### set

```c++
#include<map>
using namespace std;
set<int> s;
s.insert; //插入元素
s.erase(); //根据健值插入元素
s.clear(); //删除所有元素
s.empty(); //是否为空
s.find(); //返回指向查找元素位置的迭代器，找不到则返回s.end()
s.size(); //元素个数
//遍历
set<string>::iterator iter=set_str.begin();  
while(iter!=set_str.end())  
{  
    cout<<*iter<<endl;  
    ++iter;  
}  
```
