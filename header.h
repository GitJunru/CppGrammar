#include <cmath>
//宏定义
#define DEBUG
#define PI acos(-1)

//起别名
typedef int INT;
using DOU = double;

inline void swap(int& a, int& b);
class Worker;
class Workers;
void salaryExchange(Worker& a, Worker& b);
void coutInfo(const Worker& b);

int compu(int, int, int (*func)(int ,int));
int add(int, int);
