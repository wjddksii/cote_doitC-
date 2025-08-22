#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int size;
    cin >> size;

    queue<int> cards;
    for(int i=1; i<=size; i++){
        cards.push(i);
    }
    
    while(cards.size()>1){
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    cout << cards.front();
}