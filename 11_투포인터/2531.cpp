#include <iostream>
#include <vector>

using namespace std;

int n, d, k, c;//벨트에 놓은 접시 수//초밥 가짓수//연속 접시 수//쿠폰 번호
vector<int> type(3000,0);//각 유형의 개수

int findMax(vector<int> &sushi){
    //초기화
    int left = 0;
    int right = 0;
    int repeat = 0; //각 윈도우에서 최대 중복 횟수
    type[c]++;//쿠폰에 적힌 유형의 초밥 
    for(int i=0; i<k; i++){
        right = left + i;
        type[sushi[right]]++;//해당 유형 초밥 카운트 
        if(type[sushi[right]] > 1){
            repeat++;
        }
    }
    int min_repeat = repeat; //여러 경우의 수 중 최소 중복 수
 
    //슬라이딩 
    while(left < n){
        /*윈도우 계산*/
        //각 윈도우(경우)에서 중복 횟수 카운트
        
        //이번 슬라이드에서 제외된는 값
        if(type[sushi[left]] > 1){//이전에 중복이 카운트 되었을 경우
            repeat--; //해당 중복 카운트를 제거 
        }
        type[sushi[left]]--;
        left++;
        
        //이번 슬라이드에서 추가되는 값
        right = (right + 1) % (n);
        type[sushi[right]]++;
        if(type[sushi[right]] > 1){
            repeat++;
        }
        
        //min_repeat 갱신
        if(min_repeat > repeat){
            min_repeat = repeat;
        }
    }
    
    return (k+1) - min_repeat;
}

int main()
{
    //입력
    cin >> n >> d >> k >> c;
    vector<int> sushi(n,0);//벨트 위 초밥 
    for(int i=0; i<n; i++){
        cin >> sushi[i]; //n개의 각 접시에 올라온 초밥 유형
    }
    
    //최대 가짓 수 찾기
    int answer = findMax(sushi);
    
    //출력
    cout << answer;

    return 0;
}