#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <cmath>

#include "header.h"
#include "headerWorker.cpp"

using namespace std;

//gcc -c mainWorker.cpp
//nm *.o

//枚举
enum WEEK{SUN = 7, MON = 1, TUE, WEN, THU, FIR, SAT};
//枚举类
enum class num:char{GRADE, BIYE, YANBI};


int main (){
#ifdef DEBUG
    cout << "Debug mode!" << endl;
#endif

    /***********************************************************/
    //枚举
    WEEK week = WEEK::MON;
    //枚举类,强类型赋值
    num n = num::GRADE;
    //cout << sizeof n << endl;
    /***********************************************************/

    /***********************************************************/
    //构造常对象，只能调用常函数
    const Worker mayun("mayun", 57, 2000);
    mayun.getCount();
    coutInfo(mayun);

    //复制构造函数
    Worker yewenjie(mayun);
    yewenjie.setName("yewenjie");
    coutInfo(yewenjie);

    //让xiaoming定义为和yewenjie一样的类型
    decltype(yewenjie) luoji = (string)"luoji";
    coutInfo(luoji);
    //二进制输出, <>内为输出的位数
    cout << "luoji's age = " << bitset<16> (luoji.getAge()) << endl;
  
    //静态成员函数的调用方法
    Worker::showCount();
    yewenjie.showInfo(luoji);
    
    salaryExchange(yewenjie, luoji);
    coutInfo(luoji);
    /***********************************************************/

    /***********************************************************/
    int q[4] = {};
    cout << "q数组的长度 = " << sizeof(q)/sizeof(q[0])  << endl;//获得数组的长度
    //遍历并修改数组的值
    for(int& x : q){
        x += 2;
    }
    /***********************************************************/

    /***********************************************************/
    void* ptr;
    int intA = 5;
    ptr = &intA;//给void*赋值
    int* qtr = static_cast<int*>(ptr);//void*转换为int*

    //指向const类型的指针
    const int* p = &intA;
    //*p = 4;//错误
    intA = 4;//可以
    int intB = 7;
    p = &intB;//正确，p本身的值可以改变

    //常指针
    int* const constPtr = &intA;
    //constPtr = &intB; //错误
    *constPtr = 33; //可以
    /***********************************************************/

    /***********************************************************/
    int* intC = new int(sizeof(int));
    cout << (void*)intC << ' ' << (void*)&intC << endl;
    Worker* xiaoye = new Worker("xiaoye");
    Worker* xiaoluo = new Worker("xiaoluo");//指针存在栈区，指向的地址为堆区
    cout << (void*)&xiaoye << ' ' << (void*)&xiaoluo << endl;
    cout << (void*)xiaoye << ' ' << (void*)xiaoluo << endl;//输出地址
    delete(xiaoye);delete(xiaoluo);delete(intC);

    //用一个类Workers动态创建Worker数组
    Workers team1(2);
    Workers team2 = team1;

    team1.getElem(0).setName("changweisi");
    cout << "team1 leader = " << team1.getElem(0).getName() << endl;
    cout << "team2 leader = " << team2.getElem(0).getName() << endl;
    /***********************************************************/

    /***********************************************************/
    double douA = 123.456;
    //floor()向下取整
    floor(douA * 100 + 0.5)/100;//四舍五入到小数点后两位
    //Ceil()向上取整

    //指针数组构成的二维数组 和 二维数组 的区别
    //: 二维数组的内存空间是连续的，指针数组不一定连续

    //指针函数：返回值类型为指针的函数
    //可以在函数中new一个空间，再返回地址，要注意在主函数中记得delete

    /* 函数指针
        定义形式：
            存储类型 数据类型 (*函数指针名)();
        含义：
            函数指针指向的是程序代码存储区
    */
    int intD = compu(intA, intB, &add);
    /***********************************************************/




    

    return 0;
}

