#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node {
    char name[10];
    int age;
    int money;
};
int cmp1(node a, node b) {
    if(a.money != b.money)
        return a.money > b.money;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}
 
int main() {
    int n, k, num, amin, amax;
    scanf("%d %d", &n, &k);
    vector<node> vt(n), v;
    vector<int> book(205, 0);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].money);
    }
    sort(vt.begin(), vt.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(book[vt[i].age] < 100) {
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &num, &amin, &amax);
        vector<node> t;
        for(int j = 0; j < v.size(); j++) {
            if(v[j].age >= amin && v[j].age <= amax)
                t.push_back(v[j]);
        }
        printf("Case #%d:\n", i + 1);
        int flag = 0;
        for(int j = 0; j < num && j < t.size(); j++) {
            printf("%s %d %d\n", t[j].name, t[j].age, t[j].money);
            flag = 1;
        }
        if(flag == 0) printf("None\n");
    }
    return 0;
}
