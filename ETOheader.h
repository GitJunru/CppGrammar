#include <iostream>

using namespace std;

enum class ETOTeam;
class ETO;
class Worker;

class Sophon{
private:
    int index;
public:
    Sophon(int _index = 1) : index(_index){};
};

void getETOSalary(Worker* a);
int operator+ (int a, const ETO& b);
ostream& operator<< (ostream& out, const ETO& a);
string teamToString(ETOTeam t);