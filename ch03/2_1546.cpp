#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int N, Max=0, sum=0;
    int scores[1000];

    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> scores[i];
        if (Max<scores[i]) Max=scores[i];
    }

    for (int i=0; i<N; i++){
        sum += scores[i];
    }

    double answer = sum*100.0/Max/N;

    cout << answer;
}