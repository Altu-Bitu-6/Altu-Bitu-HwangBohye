#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_num;//dp에 저장된 값 중 현재 제일 큰 값
int max_idx;//dp에 있는 max_num의 인덱스

void findPartOfA(int n, vector<int> &a, vector<int> &dp, vector<int> &arr){
    for(int  i=0; i<n; i++){
        dp[i] = 1;
        
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        if(max_num < dp[i]){
            max_num = dp[i];//max_num은 dp[i]로 갱신
            max_idx = i;//max_idx도 i로 갱신 
        }
    }

    for(int i=max_idx; 0<=i; i--){
        //가장 큰 수 부터 arr에 넣기 
        if(max_num == dp[i]){
            arr.push_back(a[i]);
            max_num--;//다음 가장 큰 수 넣기
        }
    }
}

int main()
{
    //수열 a의 크기 입력
    int n;
    cin >> n;
    
    vector<int> a(n,0);
    vector<int> dp(n,0);
    
    //수열 a의 요소 입력 
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    //a의 가장 긴 부분 수열 구하기
    vector<int> arr;//a의가장 긴 부분 수열 
    findPartOfA(n, a, dp, arr); 
    
    //a의 가장 긴 부분 수열의 길이 구하기 
    int size = arr.size();
    
    //출력
    cout << size;
    
    return 0;
}