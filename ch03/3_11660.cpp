#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size, QNums;
    cin >> size >> QNums;

    // 배열 입력 및 합배열 D[X][Y] 연산
    /* 배열로 선언하면 segmentation fault 발생
    int array[1025][1025] ={};
    int D[1025][1025] = {};
    */

    vector<vector<int>> array(size+1, vector<int>(size+1, 0));
    vector<vector<int>> D(size+1, vector<int>(size+1, 0));
    for (int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            cin >> array[i][j];
            D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + array[i][j];
        }
    }

    int X1, Y1, X2, Y2;
    int answer[100000];
    // 질의 입력 및 2차원 구간합 계산
    for (int i=0; i<QNums; i++){
        cin >> X1 >> Y1 >> X2 >> Y2;
        answer[i] = D[X2][Y2] - D[X1-1][Y2] - D[X2][Y1-1] + D[X1-1][Y1-1];
    }

    // 2차원 구간합 계산 결과 출력
    for (int i=0; i<QNums; i++){
        cout << answer[i] << "\n";
    }
}