#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// compare함수: operator()(int a, int b)
// true -> 우선순위 a>b
// false -> 우선순위 a<b
struct compare{
    bool operator()(int x, int y){
    int x_abs = abs(x);
    int y_abs = abs(y);
    if(x_abs == y_abs) return x > y;  // x가 음수이면 우선순위 x>y
    else return x_abs > y_abs;  // abs(x)가 더 크면 우선순위 x>y
    }
};

int main(){
    int size;
    cin >> size;

    priority_queue<int, vector<int>, compare> pq;
    vector<int> answer(size, 0);

    for(int i=0; i<size; i++){
        int request;
        cin >> request;
        if(request==0){
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(request);
        }
    }

}