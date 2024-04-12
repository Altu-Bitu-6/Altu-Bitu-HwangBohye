#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,m;
set<int> nums;// 주어진 n개의 수
vector<int> sequeence; // 주어진 n개의 수를 사용해 만든 수열 

void print(){
    for(int i=0; i<m; i++){
        cout << sequeence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int idx){
    //탈출 조건 -> m개의 숫자 다 뽑은 경우 
    if(idx == m){
        print();
        return ;
    }
    
    for(auto iter = nums.begin(); iter!=nums.end(); iter++){ //set 사용 -> 오름차순
        //선택한 숫자 저장 
        sequeence[idx] = *iter;
        
        //다음 숫자 고르기 
        backtrack(idx+1); 
    }
    
}

int main()
{
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        nums.insert(num);
    }
    
    sequeence.assign(m, 0);
    
    backtrack(0);

    return 0;
}