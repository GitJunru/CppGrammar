#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void Swap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}

//快速排序
void QuickSort(vector<int>& array, int start, int end){
    if(array.empty() || start < 0 || end >= array.size() || start >= end) return;
    int mid = start;
    for(int index = start; index < end; index++){//以end位置的值做基准
        if(array[index] < array[end]){
            if(index != mid) {
                Swap(array[mid], array[index]);
            }
            mid++;
        }
    }
    Swap(array[mid], array[end]);
    if(mid > start) QuickSort(array, start, mid - 1);
    if(mid < end) QuickSort(array, mid + 1, end);
}
void qs(vector<int>& array, int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = array[l + r >> 1];
    while(i < j){
        do{++i;} while (array[i] < x);
        do{--j;} while (array[j] > x);
        if(i < j) Swap(array[i], array[j]);
    }
    qs(array, l, j);
    qs(array, j + 1, r);
}

//冒泡排序
void BbSort(vector<int>& array){
    if(array.empty()) return;
    for(int i = 1; i < array.size(); i++){
        for(int j = 0; j < array.size() - i; j++){
            if(array[j] > array[j + 1]) Swap(array[j], array[j + 1]);
        }
    }
}

//归并排序
void mergeSort(vector<int>& array, int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    mergeSort(array, l, mid);
    mergeSort(array, mid + 1, r);

    int i = l, j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= r){
        if(array[i] < array[j]) temp.push_back(array[i++]);
        else temp.push_back(array[j++]);
    }
    while(i <= mid) temp.push_back(array[i++]);
    while(j <= r) temp.push_back(array[j++]);

    for(i = l, j = 0; i <= r; i++, j++) array[i] = temp[j];
}

template<typename T>
void outPut(const T a){
    for(auto x : a) cout << x << ' ';
    cout << endl;
}

int main(){
    srand(time(0));
    vector<int> array;
    int t = 0;
    for(int i = 1; i < 100; i++){
        array.push_back(i);
        if(t == 0) *(array.end() - 1) -= 1;
        t = (t + 1) % 3;
    }
    random_shuffle(array.begin(), array.end());
    int n = array.size();
    cout << "Origin array : ";
    outPut(array);

    /*快速排序*/
    clock_t begin, end;
    begin = clock();
    qs(array, 0, n - 1);
    end = clock();
    cout << "\n快速排序 : ";
    outPut(array);
    cout << "Time : " << double(end - begin) / CLOCKS_PER_SEC << endl;

    //冒泡排序
    begin = clock();
    BbSort(array);
    end = clock();
    cout << "\n冒泡排序 : ";
    outPut(array);
    cout << "Time : " << double(end - begin) / CLOCKS_PER_SEC << endl;

    /*归并排序*/
    begin = clock();
    mergeSort(array, 0, n - 1);
    end = clock();
    cout << "\n归并排序 : ";
    outPut(array);
    cout << "Time : " << double(end - begin) / CLOCKS_PER_SEC << endl;    


    return 0;
}