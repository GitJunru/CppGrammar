#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool cmp(int x, int y){
    return x > y;
}

struct echo{
    int x, y;
    bool operator < (const echo &a) {
		return x < a.x || x == a.x && y < a.y;
    }

};

int main (){
    vector<int> a = {34, 54, 21, 44, 34, 21};
    for (int i = 1; i < 5; i++) a.push_back(i);
    cout << "a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;


    //随机打乱
    srand(time(0));
    random_shuffle(a.begin(), a.end());
    cout << "random_shuffle a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;

    //翻转
    reverse(a.begin(), a.end());
    cout << "reverse a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;

    //排序
    sort(a.begin(), a.end());
    cout << "sort a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;

    //由大到小排序
    sort(a.begin(), a.end(), cmp);
    cout << "sort cmp a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;

    //去重，返回指向最后的逆向迭代器，多余的没有删掉，都放在后面
    auto ite = unique(a.begin(), a.end());
    a.erase(ite, a.end());
    cout << "unique a = ";
    do{
        --ite;
        cout << *ite << ' ';
    } while (ite != a.begin());
    cout << endl;

    cout << "a = " ;
    for (auto x : a) cout << x << ' ';
    cout << endl;
    
    
    echo e[5];
    for (int i = 0; i < 5; i++) e[i].x = -i, e[i].y = i;
    cout << "e = ";
    for (auto k : e) cout << '(' << k.x << ", " << k.y << ") ";
    cout << endl;


    sort(e, e + 5);
    cout << "sort e = ";
    for (auto j : e) cout << '(' << j.x << ", " << j.y << ") ";
    cout << endl;

    //可以预分配vector的长度
    vector<int> b(5);
    for(auto x : b){
        cout << '!' << x;
        b.push_back(1);
    }
    cout << "\nvector b的长度为："<< b.size();//结果为10
    return 0;
}