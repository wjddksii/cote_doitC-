#include <iostream>
#include <vector>
using namespace std;

void Add(char c);
void Remove(char c);

int strNum, pwdNum;
int check=0, answer=0;
int goal[4], nowarr[4];

// 문자열의 길이가 10^6 까지이기 때문에 배열로 받을 수 없다.
string arr;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> strNum >> pwdNum;

    // dna 문자열 입력
    cin >> arr;

    // 목표 문자열 입력
    for(int i=0; i<4; i++){
        cin >> goal[i];
        if (goal[i] == 0) check++;
    }

    // 초기 pwdNum개 문자열 저장
    for(int i=0; i<pwdNum; i++){
        Add(arr[i]);
    } 
    if (check==4) answer++;
    
    // 문자열 검사 (2번째부터~)
    for(int i=pwdNum; i<strNum; i++){
        int j=i-pwdNum;
        Add(arr[i]);
        Remove(arr[j]);
        if (check==4) answer++;
    }
    cout << answer;
}

// 문자가 들어오면, 현재 문자열 개수에 증가연산 후
// 목표 개수와 일치한지 검사하고, 종료한다.
void Add(char c){
    switch(c){
        case 'A':
            nowarr[0]++;
            if(nowarr[0] == goal[0]) check++;
            break;
        case 'C':
            nowarr[1]++;
            if(nowarr[1] == goal[1]) check++;
            break;
        case 'G':
            nowarr[2]++;
            if(nowarr[2] == goal[2]) check++;
            break;
        case 'T':
            nowarr[3]++;
            if(nowarr[3] == goal[3]) check++;
            break;
    }
}

// 문자가 들어오면, 현재개수가 목표개수와 같으면 check 플래그 감소연산 후
// 현재 개수의 수를 감소연산하고 종료한다.
void Remove(char c){
    switch(c){
        case 'A':
            if(nowarr[0] == goal[0]) check--;
            nowarr[0]--;
            break;
        case 'wwC':
            if(nowarr[1] == goal[1]) check--;
            nowarr[1]--;
            break;
        case 'G':
            if(nowarr[2] == goal[2]) check--;
            nowarr[2]--;
            break;
        case 'T':
            if(nowarr[3] == goal[3]) check--;
            nowarr[3]--;
            break;
    }
}