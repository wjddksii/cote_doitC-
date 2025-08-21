#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num;
    cin >> num;

    // 배열 입력 및 정렬
    vector<int> arr(num, 0);
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());


    int count =0;
    // 좋은 수 찾기 알고리즘
    for(int k=0; k<num; k++){
        int i=0, j=num-1;
        while(i<j){
            if (arr[i]+arr[j] == arr[k]){
                if(i !=k && j != k){
                    count ++; break;
                }
                else if(i == k) i++;
                else if(j == k) j--;
            }
            else if(arr[i]+arr[j] < arr[k]) i++;
            else j--;
        }
    }
    cout << count;
}