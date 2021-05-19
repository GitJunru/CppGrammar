#include<iostream>
#include<unordered_map>

using namespace std;



int main(){
    //unorderd_map 基本操作
    //注意：C++11才开始支持括号初始化
    unordered_map<int, string> myMap={{ 5, "张大" },{ 6, "李五" }};//使用{}赋值
    myMap[2] = "李四";  //使用[ ]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
    myMap.insert(pair<int, string>(3, "陈二"));//使用insert和pair插入
    myMap.insert(make_pair(7, "xiaoliu"));//用insert不会覆盖

    //判断是否有元素
    if(myMap.empty()){
        cout << "myMap为空" << endl;
    }
    else{
        cout << "myMap共有" << myMap.size() << "个元素" << endl;
    }

	//遍历输出+迭代器的使用
    //iter的类型为 unordered_map<int, string>::iterator
    auto iter = myMap.begin();//auto自动识别为迭代器类型unordered_map<int,string>::iterator
    while (iter!= myMap.end())//不能等于end
    {  
        cout << iter->first << "," << iter->second << endl;  
        ++iter;  
    }  
	cout << endl;


    //查找是否有对应的元素
    if(myMap.count(3) != 0){
        cout << "3存在" << endl;
    }
    else cout << "3不存在" << endl;


	//查找元素并输出+迭代器的使用
    auto iterator = myMap.find(2);//find()返回一个指向2的迭代器
    if (iterator != myMap.end())
	    cout << endl<< iterator->first << "," << iterator->second << endl;
    //删除操作
    myMap.erase(iterator);//用迭代器删除
    int res = myMap.erase(7);//用key值删除，删除了返回1，否则返回0
    cout << "删除操作 res = " << res << endl;
    return 0;
}