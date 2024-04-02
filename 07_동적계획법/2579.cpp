#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void score(int n, vector<int> &s, vector<int> &dp){
    dp[1] = s[1];
    if(n>=2){
        dp[2] = s[1]+s[2];
        if(n>=3){
            for(int i=3; i<n+1; i++){
                dp[i] = max(s[i]+dp[i-2], s[i]+s[i-1]+dp[i-3]);
            }
        }
    }
}

int main()
{
    int n; //계단 수
    cin >> n;
    
    vector<int> s(n+1, 0); //각 계단에 할당된 점수 저장
    vector<int> dp(n+1, 0);//i번 째 계단 도착하는데 얻을 수 있는 최대 점수를 저장[i]에 저장
    
    for(int i=1; i<n+1; i++){
        cin >> s[i];
    }
    
    score(n, s, dp);
    
    //n번째 계단까지 도착하는데 얻는 최대 score 출력 
    cout << dp[n]; 

    return 0;
}