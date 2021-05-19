#include "ETO.cpp"
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNode(ListNode* p, int val){
    ListNode* node = new ListNode(val);
    cout << (void*)&p << endl;
    p->next = node;
}

int main(){
    ETO wallBreaker_1("WB_1", ETOTeam::Adventists);
    ETO ywj("Ye WenJie", ETOTeam::Redemptionists);
    ETO syf("Shen YuFei", ETOTeam::Redemptionists);
    
    
    ETO::printDonationList();
    cout << "new Donation:" << 888+ywj << endl;
    cout << ywj;

    Worker a;
    cout << "Worker count = " << getCount(a) << endl;
    cout << "ETO count = " << getCount(ywj) << endl;

    ListNode* p = new ListNode(1);
    cout << (void*)&p << endl;
    addNode(p,2);
    cout << bool(p->next == nullptr) << endl;

    Worker* temp = new Worker;

    return 0;
}