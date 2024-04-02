#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minVelocityAtEarth(vector<int> &v){
    long long min_v_earth = v[v.size()-1];// 최소 속도
    
    for(int i=v.size()-2; 0<=i; i--){
        if(v[i] >= min_v_earth){
            min_v_earth = v[i]; // 더 빠른 속도로 갱신
        }
        else{
            // 200/200 = 1...0 -> 200의 (1)배로 갱신 
            // 1000/300 = 3...100  ->  300의 (3+1)배로 갱신
            long long j = min_v_earth / v[i];
            if(min_v_earth%v[i] > 0){ 
                j++;
            }
            
            min_v_earth = v[i] * j; // 더 빠른 정수 배로 갱신
        }
    }
    
    return min_v_earth;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    long long ans;
    ans = minVelocityAtEarth(v);
    
    cout << ans;

    return 0;
}