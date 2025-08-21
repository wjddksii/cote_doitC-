#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long Nums, updates, Qnums;
    cin >> Nums >> updates >> Qnums;

    // 1번째 부터 시작이니까 배열크기는 Nums+1
    vector<long long> arr(Nums+1, 0);
    vector<long long> sum(Nums+1, 0);

    // 원본 배열 저장 및 합배열 계산
    for(int i=1; i<=Nums; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int a;
    long long b, c, idx=0;
    vector<int> answer(Qnums, 0);

    // 배열 업데이트 및 구간합 계산
    for(int i=0; i <updates+Qnums; i++){
        cin >> a >> b >> c;
        if (a==1){
            arr[b] = c;
            for(int j=a; j<=Nums; j++){
                sum[j] = sum[j-1] + arr[j];
            }
        }
        else{
            // b에서부터 c까지의 구간합 (b,c)
            answer[idx++] = sum[c] - sum[b-1];
        }
    }

    for(int i=0; i<Qnums; i++){
        cout << answer[i] << "\n";
    }

}