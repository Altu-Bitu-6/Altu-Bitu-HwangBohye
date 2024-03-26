#include <iostream>
#include <queue>

using namespace std;

int delivery(priority_queue<int> &pq){
    int gift;
    if(pq.empty()){
        return -1;
    }
    else{
        gift = pq.top();
        pq.pop();
    }
    
    return gift;
}



int main()
{
    priority_queue<int> pq;
    int n;
    cin >> n;
    
    while(n--){
        int a;
        cin >> a;
        
        if(a == 0){
           cout << delivery(pq) << "\n";
        }
        else{
            int gift_value;
            while(a--){
                cin >> gift_value;
                pq.push(gift_value);
            }
        }
    }

    return 0;
}