#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

const int MAX = 10000000;
/*
4자리수 ex) 1666, 6661 => 약 (10*1)*2 = 20 개
5자리수 ex) 10666, 66601 => 약 (10*10*1)*3 = 300개
...
7자리 수 ex) 1000666, 6660001 => 약 (10*10*10*10*1)*5 = 50000개

=> (n <= 10000) 이므로, 10000번째 종말 수는 7자리 숫자일 것 
=> MAX는 대략 10^7
*/

int findEndNum(int n){
    int ans;
    vector<int> v;
    int k=1;
    
    while(k<MAX){
        int tmp = k;
        int cnt = 0;//6의 연속 횟수
        int flag = 0;//이전 자릿수가 6이면, flag는 1로
        int jari = 0;//각 자리의 숫자
        
        while(tmp){
            if(cnt==3){// 종말 수 증명됨 
                break;
            }
            
            jari = tmp % 10;
            tmp /= 10;
            
            if(flag){//이전 자릿수 6
                if(jari==6){//현재 자릿수 6(연속)
                    cnt++;
                }
                else{ // 현재 자릿수 6아님 
                    flag = 0;
                    cnt = 0;
                }
            }
            
            else{//이전 자릿수 6아님
                if(jari==6){//현재 자릿수 6
                    cnt++;
                    flag = 1;
                }
            }
        }
        
        if(cnt==3){
            v.push_back(k); //k는 종말수로, v에 넣기 
        }
        
        k++;
    }
    
    // v정렬하기 
    sort(v.begin(), v.end());
    //n번째 종말 수 구하기 
    ans = v[n-1];
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    int n_endnum = findEndNum(n);
    
    cout << n_endnum;

    return 0;
}