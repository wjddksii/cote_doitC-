#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num, target;
    cin >> num >> target;
    
    // 배열 입력 및 정렬
    vector<int> materials(num, 0);
    for(int i=0; i<num; i++){
        cin >> materials[i];
    }
    sort(materials.begin(), materials.end());

    // 갑옷의 조합 찾기
    // 양끝에 포인터를 두고 시작한다.
    // 합이 작으면 start를 키워야한다. (이미 끝을 가리키고 있음)
    // 합이 크면 end를 줄여야 한다. (이미 이전의 start 값은 모두 검사함)
    // 합이 tartget과 같으면 다음 start로 이동하고, end는 줄어야 한다.
    int start=0, end=num-1, count=0;
    while(start < end){
        if(materials[start]+materials[end] == target){
            start++; end--; count++;
        }
        else if(materials[start]+materials[end] > target){
            end--;
        }
        else{start++;}
    }
    cout << count;
}