#include <iostream>
#include <cstring>
#include <cassert>
#include "header.h"

using namespace std;

//内联函数，内部不能有switch、循环
//定义必须在前
//内部不能有异常接口声明
inline void swap(int& a, int& b){
    static int count = 3; int t = a; a = b; b = t;
}

//抽象类
class Living{
public:
    virtual int getCount() const = 0;
};

class Worker : public Living{
private:
    //const成员变量在这直接初始化，或在构造函数初始化
    //const影响类用=赋值
    //const string kind = "human";
    const string kind;
    string name;
    int age;
    int salary;
    //类静态成员,在类的内部声明，在类的外部赋值，为整个类共享
    static int count;
    /*如果两个类互相包含，使用前向引用声明也没用，可以使用指针
      Tri* pTri;
    */

public:
    Worker() : Worker("AA", 30, 1500){};
    Worker(const Worker& sb) : name(sb.name), age(sb.age), salary(sb.salary), kind("human"){
        //cout << "复制构造" << endl;
        count ++;
    };
    //常成员赋值必须在初始化列表中赋值，不能在函数体中赋值
    Worker(string _name, int _age = 30, int _salary = 1500) : name(_name), age(_age), salary(_salary), kind("human"){
        count ++;
    };
    //虚析构函数，当对象以指针传入函数并delete时，可以正确调用析构函数
    virtual ~Worker(){
        count --;
    };

    Worker& operator=(const Worker& w){
        name = w.name;
        age = w.age;
        salary = w.salary;
        return *this;
    }

    void setName(string _name){ name = _name;}
    void setAge(int _age){ age = _age;}
    void setSalary(int _salary = 1500){ salary = _salary;}
    
    string getName() {return name;}
    //常成员函数，const后缀可以用来区分重载函数
    string getName() const{ return name;}
    int getSalary() { return salary;}
    int getSalary() const{ return salary;}
    int getAge() const{ return age;}
    //虚函数，实现运行时多态
    //必须是非静态成员
    virtual int getCount() const override{ //override,确保该函数为虚函数并覆写来自基类的虚函数
        //cout << "Getting Worker Count!" << endl;
        return count;
    }

    //静态成员函数，可以直接通过类名调用，也能通过对象调用
    static void showCount(){ cout << "Worker count = " << count << endl;}
    //在静态成员函数中如果使用与对象相关的变量，需要传入对象
    static void showInfo(Worker& a){
        cout << "Name : " << a.getName() << " age : " << a.getAge() << " salary : " << a.getSalary() << '$' << endl;
    }
    //友元,单向
    friend void salaryExchange(Worker&, Worker&);
    friend class Tri;
};
//类静态成员count在类外赋值,必须赋值
int Worker::count = 0;

class Workers{
private:
    Worker* workers;
    int num;
    
public:
    Workers(int n) : num(n){
        //cout << "Construction complete!" << endl;
        workers = new Worker[num];
    };
    //深拷贝
    Workers(const Workers& w) : num(w.num){
        workers = new Worker[num];
        for(int i = 0; i < num; i++){
            workers[i] = w.workers[i];
        }
    };
    Workers(Workers && w) : num(w.num), workers(w.workers){
        w.workers = nullptr;
        cout << "移动构造完成" << endl;
    };
    ~Workers(){
        //cout << "Destruction OVER!" << endl;
        delete[] workers;
    };

    Worker& getElem(int index){
        assert(index >=0 && index < num);
        return workers[index];
    }

};


void salaryExchange(Worker& a, Worker& b){
    int x = a.salary;
    a.salary = b.salary;
    b.salary = x;
}

//参数为&时，不能传入const，所以要在参数前面加const
//常引用是只读的引用
void coutInfo(const Worker& b){
    cout << "Name : " << b.getName() << " age : " << b.getAge() << " salary : " << b.getSalary() 
        << '$' << " count : " << b.getCount()<< endl;
}

int compu(int a, int b, int (*func)(int, int)){
    return func(a, b);
}

int add(int a, int b){
    return a + b;
}