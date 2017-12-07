# PAT总结

## PAT中常用的STL容器

### 顺序容器

#### vector

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

#### queue

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

#### priority_queue

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

#### stack

```c++
#include<stack>
stack<Datatype> s;
s.push(Data); //入栈
s.pop(); //出栈
s.top(); //访问栈顶元素
s.empty(); //判断栈是否为空
s.size(); //栈元素个数
```

### 关联容器

#### map

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

#### set

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

## PAT常用算法

### 排序

#### STL函数

```c++
bool cmp(){}
sort(begin,end,cmp);
```

#### 冒泡排序

```c++
void BubbleSort(int A[], int n)
{
    for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
    {
        for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
        {
            if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
            {
                swap(A[i], a[i+1]);
            }
        }
    }
}
```

#### 插入排序

```c++
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
    {
        int get = A[i];                 // 右手抓到一张扑克牌
        int j = i;                  // 拿在左手上的牌总是排序好的
        while (j >0 && A[j-1] > get)    // 将抓到的牌与手牌从右向左进行比较
        {
            A[j] = A[j-1];            // 如果该手牌比抓到的牌大，就将其右移
            j--;
        }
        A[j] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
    }
}
```

#### 希尔排序

```c++
#include <stdio.h>  

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n)                          // 生成初始增量
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                    // 递减增量
    }
}
```

#### 归并排序

```c++
void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}
```

#### 堆排序

```c++
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
priority_queue<int> q;
void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // 建立一个最大堆
    while (q.size() > 0)    　　　　　　 // 堆（无序区）元素个数大于1，未完成排序
    {
        cout<<q.top();
        q.pop();
    }
}
```

#### 快速排序

```c++
#include <stdio.h>
int a[101],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
       return;
    temp=a[left]; //temp中存的就是基准数
    i=left;
    j=right;
    while(i!=j)
    {
        //顺序很重要，要先从右边开始找
        while(a[j]>=temp && i<j)
                j--;
        //再找右边的
        while(a[i]<=temp && i<j)
                i++;
        //交换两个数在数组中的位置
        if(i<j)
        {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
        }
    }
    //最终将基准数归位
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);//继续处理左边的，这里是一个递归的过程 
    quicksort(i+1,right);//继续处理右边的 ，这里是一个递归的过程 
}
```

### 最短路径

