#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nums, mod;
    cin >> nums >> mod;

    // 합배열 구하기
    int input;
    vector<long> sum(nums+1, 0);
    for(int i=1; i<=nums; i++){
        cin >> input;
        sum[i] = sum[i-1] + input;
    }

    // 나머지 연산으로 합배열 업데이트
    // 나머지가 0인 경우
    // 나머지의 개수를 저장
    int remainder;
    long answer = 0;
    vector<long> modCount(mod, 0);
    for(int i=1; i<=nums; i++){
        remainder = sum[i] % mod;
        if(remainder == 0) {answer++;}
        modCount[remainder]++;
    }

    // 나머지가 같은 인덱스 2개를 뽑는 경우의 수 (2개 이상이어야 함)
    for(int i=0; i<mod; i++){
        if(modCount[i] > 1){
            answer += modCount[i]*(modCount[i]-1) / 2;
        }
    }
    cout << answer;
}