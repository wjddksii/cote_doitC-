#include <iostream>
using namespace std;

int main(){
    int start_idx=1, end_idx=1, count=1, sum=1;
    int num;
    cin >> num;

    // 포인터를 이용해서, start-end 까지의 구간합을 구한다.
    // 구간의 처음과 끝을 큰 숫자로 이동시킨다.
    // 처음 숫자가 구간합에서 제외되면 끝 숫자는 더 커야하기 때문에 end는 계속 커진다.

    while(end_idx != num){
        if(sum == num){
            count++; end_idx++; sum += end_idx;
        }
        else if(sum > num){
            sum -= start_idx; start_idx++;
        }
        else if(sum < num){
            end_idx++; sum += end_idx;
        }
    }
    cout << count;
}