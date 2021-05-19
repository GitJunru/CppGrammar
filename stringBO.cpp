#include <cstring>
#include <iostream>

using namespace std;

//等于在函数内定义了一个只有这个函数能用的全局变量
int output(void){
    static int n = 0;
    n++;
    cout << "n = " << n << endl;
}

int main(){
    string s8;
    //getline(cin, s8);
    cout << "s8是否为空 : " << s8.empty() << endl;
    string s1;  // si = ""
    string s2("Hello");  // s2 = "Hello"
    string s3(4, 'K');  // s3 = "KKKK"
    string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
    //.size和.length输出字符串长度，sizeof输出string类型占的字节数
    s2[2] = 'k';//替换string中的一个字符
    cout << s1.size() << ' ' << s1.length() << ' ' << s2 << ' ' << sizeof s1 << endl;

    //增加
    s3 = s1 + s2;
    s1.append(s2);   //不能用a1.append("def")
    s1.append(3,'K');
    s1.append(s2,1,2);//增加s2从1位开始的两位字符
    cout << "s1 = " << s1 << endl;

    //交换
    swap(s1, s2);
    cout << "交换后 s1 = " << s1 << endl;
    s1.assign(s4);
    cout << "赋值后 s1 = " << s1 << endl;
    
    //比较，s1<s2返回-1，s1=s2返回0，s1>s2返回1
    cout << "比较 = " << s1.compare(s2) << endl;

    //找子串
    s1.find("34");//返回字符串 ab 在 str 的位置

    //int转string
    int a=123;
    string b=to_string(a);

    //截取字符串
    string s="abcdefgdddddd";
    string s6=s.substr(1,6);   //bcdefg
    string s7=s.substr(4);     //efg

    //删除
    s6.erase(1,2); //从1位开始的两个字符,  s6=befg
    s6.erase(3); //删除4位及后面的所有字符,  s6=bef
    s6.erase(s6.begin()+1); //只删除1位的字符,  s6=bf
    s6 += '\n';
    cout << "s6 = " << s6 << "size = " << s6.size() << endl;

    char &c = s6[1];
    cout << "c = " << c << endl;
    c = 'a';
    cout << "c = " << c << " s6 = " << s6 << endl;

    return 0;
}
