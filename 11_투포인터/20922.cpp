#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;//원소의 중복 가능한 최대 개수
const int MAX_NUM = 200001;
vector<int> cnt_of_num(MAX_NUM, 0);

int findLongest(int n, vector<int> &e){
    //초기화
    int left=0;
    int right=0;
    cnt_of_num[e[right]]++; //첫 번째 원소 카운팅
    int len = 1; //현재 탐색 중인 연속 수열의 길이 
    int max_len = len;// 연속수열의 최대 길이
    
    while(left<n-1 && right<n-1){
        
        if(cnt_of_num[e[right]] > k){//동일 원소 중복이 k회를 초과한다면
            //left 원소 개수 1개 감소
            cnt_of_num[e[left]]--;
            //left 오른쪽으로 한칸 이동
            left++;
            //현재 길이 감소
            len--;
        }
        else{//k회 초과하지 않았다면
            //right 오른쪽으로 한칸 이동
            right++;
            //right 원소 개수 1개 증가가
            cnt_of_num[e[right]]++;
            //연속 길이 증가
            len++;
            
            //동일 원소 중복이 k회를 초과한다면
            if(cnt_of_num[e[right]] > k){
                //left 원소 개수 1개 감소
                cnt_of_num[e[left]]--;
                //left 오른쪽으로 한칸 이동
                left++;
                //현재 길이 감소
                len--;
            }
        }
      
        //max_len업데이트
        if(len > max_len){
            max_len = len;
        }
        
    }
    
    return max_len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력 
    int n; //원소의 총 개수 
    cin >> n >> k;
    vector<int> element(n,0);
    for(int i=0; i<n; i++){
        cin >> element[i];
    }
    
    //연산 
    int ans = findLongest(n,element);
 
    //출력 
    cout << ans;

    return 0;
}