#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int MAX = 1000000;

void getPrime(vector<bool> &is_prime){
    for(int i=2; i<=sqrt(MAX); i++){
        if(is_prime[i]){//소수라면
            for(int j=i*i; j<=MAX; j+=i){//배수 제거
                is_prime[j] = false;// 소수 아님이 증명됨
            }
        }
    }
}


pair<int, int> getSumElements(int n, vector<bool> &prime){
    pair<int, int> ans;
    int front=3, back= n-1; // 홀수인 소수 가리킬 인덱스

    
    while(back>-1 && front<n){
        if(front+back==n && prime[back] && prime[front]){//합이 n이고, 두 피연산자 모두 소수일 경우!
            break;
        }
        else if(front+back>n || !prime[back]){
            back -= 2;
        }
        else if(front+back<n || !prime[front]){
            front += 2;
        }

    }

    ans.first = front;
    ans.second = back;

    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //소수 저장
    vector<bool> is_prime(MAX+1, true);
    getPrime(is_prime);

    int n;
    cin >> n;
    
    while(n){ //n==0이면 중단
        //연산
        pair<int, int> ans = getSumElements(n, is_prime);

        //출력
        cout << n << " = " << ans.first << " + " << ans.second << "\n";
        
        //입력
        cin >> n;
    }
    
    return 0;
}