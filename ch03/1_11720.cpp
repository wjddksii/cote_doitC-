#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int N, sum=0;
    string numbers;

    cin >> N;
    cin >> numbers;

    for(int i=0; i<N; i++){
        sum += numbers[i] - 48;
    }
    
    cout << sum;
}