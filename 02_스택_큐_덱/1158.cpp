#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void makeJosep(vector<int> &josep, deque<int> &dp, int k){
    int idx = -1;//제거 위치 인덱스

    while(dp.size() > 1){
        idx = (idx + k) % dp.size();// 삭제 위치 설정

        josep.push_back(dp[idx]); // 삭제할 요소 순열에 저장

        dp.erase(dp.begin()+idx); // 큐에서 삭제

        idx = (idx - 1 + dp.size()) % dp.size();

    }
    josep.push_back(dp[0]);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> josep; // 요세푸스 순열 저장용
    deque<int> dp;

    for(int i=1; i<=n; i++){
        dp.push_back(i);
    }

    makeJosep(josep, dp, k);

    cout << "<";
    for(int i=0; i<(int)josep.size()-1; i++){
        cout << josep[i] << ", ";
    }
    cout << josep[josep.size()-1];
    cout << ">\n";

    return 0;
}