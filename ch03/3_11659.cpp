#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N개의 수, 구간합의 개수 M
    int N, M;
    int S[100001]= {};   // 합배열 S; for문에서 1부터 인덱싱하므로 크기 10001로 선언
    
    cin >> N >> M;

    // 합배열 S 계산
    int tmp;
    for (int i=1;i<=N;i++){
        cin >> tmp;
        S[i] = S[i-1] + tmp;
    }

    // 구간합 계산
    int start, end;
    int answer[100001];
    for(int j=0; j<M; j++){
        cin >> start >> end;
        answer[j] = S[end] - S[start-1];
    }

    // 구간합 출력
    for(int k=0; k<M; k++){
        cout << answer[k] << "\n";
    }
}