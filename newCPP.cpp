#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;

double Min = pow(10.0, -15);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_map(unordered_map<char, int> hash){
    for(auto x : hash) {
        cout << x.first << ' ' << x.second << endl;
    }
}

class Solution {
public:
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};

double arctan(double x){
    double res = 0;
    double addon = 0;
    double under = 1;
    int r = 1;
    int sw = 1;
    addon = sw * pow(x, r) / under;
    while(abs(addon) > Min){
        res += addon;
        sw = -sw;
        r += 2;
        under += 2;
        addon = sw * pow(x, r) / under;
    }
    return res;
}

int main()
{
    int n;
    unordered_map<char, int> hash = {{'a', 1}, {'b', 2}};
    vector<int> array;

    //hash.erase('b');
    cout << hash.size() << endl;
    print_map(hash);

    auto s = new Solution();
    int res = s->clumsy(10000);
    cout << res << endl;
    
    double a = 1.0/5;
    double b = 1.0/239;
    double pi = 16 * arctan(a) - 4 * arctan(b);
    cout << "pi = " << pi << endl;

    return 0;
}