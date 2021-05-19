#include "ETOheader.h"
#include "headerWorker.cpp"
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

enum class ETOTeam {Adventists, Redemptionists, Survivors};

/*类的继承：公有继承public
  继承的访问控制
   -基类的public和protected成员：访问属性在派生类中保持不变
   -基类的private成员：不可直接访问
  访问权限
   -派生类中的成员函数：可以直接访问基类中的public和protected成员，
    但不能直接访问基类的private成员。
   -通过派生类的对象：只能访问public成员。
*/
/*不要重新定义继承而来的非虚函数*/
/*final,限定虚函数或类。指定派生类不能覆写基类的虚函数，或类不能被继承。*/
class ETO final: public Worker{
private:
    ETOTeam team;
    int donation;
    static map<string, int> donation_list;
    static int all_donation;
    Sophon sp;
    static int ETOCount;
public:
    //如果不调用Worker的构造函数，会自动调用Worker的默认构造函数
    //构造函数执行顺序：1.基类构造（按继承的从左向右顺序），2.初始化列表中的成员（类中定义顺序） 3.函数体
    ETO(string _name, ETOTeam _team, int _age = 27, int _salary = 2300) : Worker(_name, _age, _salary), sp(1){
        team = _team; donation = 0; donateToETO(200);
        ETOCount++;
        //cout << "ETO构造" << endl;
    };
    //复制构造函数，可以直接将参数传递给基类
    ETO(const ETO& eto) : Worker(eto), team(eto.team), donation(0){
        donateToETO(200);
        ETOCount++;
        //cout << "ETO复制构造" << endl;
    };
    //析构的顺序与构造顺序相反
    //虚析构函数，当对象以指针传入函数并delete时，可以正确调用析构函数
    virtual ~ETO(){
        ETOCount--;
        //cout << "ETO析构" << endl;
    };

    bool donateToETO(int m){
        donation += m;
        donation_list[getName()] += m;
        all_donation += m;
        return true;
    }
    int getMyDonation() const { return donation;}
    virtual int getCount() const override{
        //cout << "Getting ETO Count!" << endl;
        return ETOCount;
    }

    static int getAllDonation() { return all_donation;}
    static void printDonationList(){
        cout << "***** ETO members donation list *****" << endl;
        cout << "Name\t\tMoney\t" << endl;
        for(auto x : donation_list){
            cout << left << setw(16) << x.first << x.second << '$' << endl;   
        }
        cout << "************* End list **************" << endl;
    }

/**双目运算符重载
 * a op b 
 * op应该重载为a的成员函数，函数参数应该为b的类型
 * */
    ETO operator+ (const ETO& eto) {
        string n = eto.getName();
        random_shuffle(n.begin(), n.end());
        return ETO(n, ETOTeam::Adventists, 27, getSalary() + eto.getSalary());
    }
/**单目运算符重载
 * 无参数，返回&
 * */
    ETO& operator++ (){
        setSalary(getSalary() + 100);
        return *this;
    }
/**后置单目运算符
 * 参数为0
 * 
 * */
    ETO operator++ (int){
        ETO man = *this;
        ++(*this);
        return man;
    }
    friend int operator+ (int a, const ETO& b);
    friend ostream& operator<< (ostream&, const ETO&);
};

int ETO::all_donation = 0;
int ETO::ETOCount = 0;
map<string, int> ETO::donation_list = {};

/**类外运算符重载
 *
 * */
int operator+ (int a, const ETO& b){
    return a + b.donation;
}
ostream& operator<< (ostream& out, const ETO& a){
    out << "Name : " << a.getName() << " Team : " << teamToString(a.team) << " Donation : " << a.donation << endl;
    return out;
}

string teamToString(ETOTeam t){
    string s;
    switch(t){
        case ETOTeam::Adventists: s = "Adventists";break;
        case ETOTeam::Redemptionists : s = "Redemptionists";break;
        case ETOTeam::Survivors : s = "Survivors";break;
        default : break;
    }
    return s;
}

/*私有继承private
  继承的访问控制
   -基类的public和protected成员：都以private身份出现在派生类中
   -基类的private成员：不可直接访问
  访问权限
   -派生类中的成员函数：可以直接访问基类中的public和protected成员，
    但不能直接访问基类的private成员。
   -通过派生类的对象：不能直接访问从基类继承的任何成员。
*/
/*保护继承protected
  继承的访问控制
   -基类的public和protected成员：都以protected身份出现在派生类中
   -基类的private成员：不可直接访问
  访问权限
   -派生类中的成员函数：可以直接访问基类中的public和protected成员，
    但不能直接访问基类的private成员。
   -通过派生类的对象：不能直接访问从基类继承的任何成员。
*/
/**
 * 虚继承：virtual public/private/protected
 * 解决了二义性和冗余的问题
 * 使最远的共同基类只构造一次，构造参数由最远的派生类传递
 * 其他中间类保存着指向最远基类的指针
 * 
 */

//如果派生类ETO也定义了getSalary，传入派生类时，仍然调用基类Worker的getSalary
void getETOSalary(Worker* a){
    a->getSalary();
}
int getCount(Worker& w){
    return w.getCount();
}