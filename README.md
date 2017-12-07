# PAT中常用的STL容器

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
int length = vec1.size();
for(int i=0;i<length;i++)
{
    cout<<vec1[i];
}
cout<<endl;