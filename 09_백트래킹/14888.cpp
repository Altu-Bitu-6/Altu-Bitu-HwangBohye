#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; //주어진 숫자 개수
vector<int> nums;// n개의 요소로 주어진 수열 
vector<bool> is_used;//
vector<int> operators; // +==0 , -==1, *==2, /==3  //사용할 연산자 저장
vector<int> operator_order;
int max_result = -1000000000, min_result = 1000000000;

void updateMaxMin(){
    int result = nums[0];
    for(int i=0; i<n-1; i++){
        if(operator_order[i]==0){// +연산자
            result = result + nums[i+1];
        }
        else if(operator_order[i]==1){// -연산자
            result = result - nums[i+1];
        }
        else if(operator_order[i]==2){// *연산자
            result = result * nums[i+1];
        }
        else if(operator_order[i]==3){// /연산자
            result = result / nums[i+1];
        }
    }
    
    max_result = max(max_result, result);
    min_result = min(min_result, result);
}

void backtrack(int idx){
    //탈출 조건 -> n-1개 연산자 다 사용하면 종료
    if(idx == n-1){ // 총 연산 횟수 n-1회
        updateMaxMin();//Max와 Min 갱신 
        return ;
    }
    
    for(int i=0; i<n-1; i++){
        // 이미 operators[i]의 연산자 사용했다면, 사용 불가(skip)
        if(is_used[i] == true){
            continue;
        }
        
        //선택한 연산자 기록
        operator_order[idx] = operators[i];
        is_used[i] = true;
        
        //다음 연산자 고르기 
        backtrack(idx+1);
        
        //위의 백트래킹 재귀 호출 종료 시, opertaor[i]연산자 사용 완료 반납
        is_used[i] = false;
        
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n; 
    
    is_used.assign(n-1, false);
    operators.assign(n-1, -1);
    operator_order.assign(n-1, -1);
    nums.assign(n, 0);
    
    //n개의 수열 요소 입력(피연산자 입력)
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    // 각 연산자 사용 횟수 입력 
    int k = 0; //operators의 인덱스
    for(int i=0; i<4; i++){ // 입력 순서 (+ -> - -> * -> /)
        int cnt;
        cin >> cnt;
        
        for(int j=0; j<cnt; j++){
            operators[k] = i;
            k++;
        }
    }
    
    backtrack(0);

    cout << max_result << "\n";
    cout << min_result;
    
    return 0;
}