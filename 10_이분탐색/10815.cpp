#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(vector<int> &card, int n, int k){
    int left = 0;
    int right = n-1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(card[mid] == k){ //카드 더미에 k가 존재
            return 1;
        }
        else if(k < card[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    
    cin >> n;
    vector<int> card(n,0);
    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    
    sort(card.begin(), card.end());
    
    cin >> m;
    while(m--){
        int k;
        cin >> k;
        cout << binarySearch(card, n, k) << " ";
    }

    return 0;
}