#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntSnack(vector<int> snack, int n, int length){
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        cnt += snack[i]/length;
    }
    
    return cnt; 
}

int binarySearch(vector<int> &snack, int n, int m){
    int left = 0;
    int right = snack[n-1]; //맨 마지막 과자의 길이 
    
    while(left <= right){
        int mid = (left + right)/2;
        
        if(mid<=0){
            left = snack[0];
            continue;
        }
        
        //과자 길이를 mid로 나눌 경우, 나눌 수 있는 과자 개수
        int snack_cnt = cntSnack(snack, n, mid);
        
        if(snack_cnt >= m){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    return left - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> m >> n;
    
    vector<int> snack(n,0);
    for(int i=0; i<n; i++){
        cin >> snack[i];
    }
    
    sort(snack.begin(), snack.end());
    
    cout << binarySearch(snack, n, m);

    return 0;
}