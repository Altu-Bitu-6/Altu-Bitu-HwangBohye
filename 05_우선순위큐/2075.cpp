#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void store(int n, int e, priority_queue<int, vector<int>, greater<int>> &pq){
    // pq.size() <= n //
    
    if(pq.size() < n){
        pq.push(e);
    }
    else{//pq.size() == n으로 유지
        if(pq.top() < e){
            pq.pop(); //pq에 있는 가장 작은 수 버리기 
            pq.push(e); //pq에 e삽입
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int>> pq;// Max heap으로 구현
    
    int n;
    cin >> n;
    
    // pq에 가장 큰 n개의 수만 오름차순으로 저장
    for(int i=0; i<n*n; i++){
        int e;
        cin >> e;
        
        store(n, e, pq);
    }
    
    cout << pq.top(); 

    return 0;
}