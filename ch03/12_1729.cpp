#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int size;
    cin >> size;

    vector<int> arr(size, 0);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }


    stack<int> stk;
    stk.push(0);
    vector<int> answer(size, 0);


    // 현재 idx의 수열이 stk.top()보다 크면, arr[idx]가 오큰수
    // → answer[stk.top()] = arr[idx]
    // top의 값을 삭제하고, 현재 idx를 삽입한다.
    // stk.pop(); stk.push(idx);
    for(int i=1; i<size; i++){
        while(stk.empty()==false && arr[i]>arr[stk.top()]){
            answer[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    // 더 이상 큰 수가 없을 때
    while(stk.empty()==false){
        answer[stk.top()] = -1;
        stk.pop();
    }

    for(int i=0; i<size; i++){
        cout << answer[i] << ' ';
    }
}