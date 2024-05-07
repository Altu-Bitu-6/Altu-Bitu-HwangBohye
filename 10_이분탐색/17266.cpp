#include <iostream>
#include <vector> 

using namespace std;

int n,m;
vector<int> light; // 가로등의 위치 저장해 둘 벡터 
int ans;

//굴다리 전체를 비출 수 있는지 확인하는 함수
bool check(int length){
    /*
    [굴다리 전체를 비추기 위해 만족해야할 3가지 조건]
    1. (0 ~ 첫 번쨰 가로등의 위치) <= h
    2. (두 가로등 사이의 간격) <= 2*h
    3. (마지막 가로등의 위치 ~ n) <= h
    */
    
    //첫 번째 가로등 처리 
    if(light[0] > length){ // 조건 1번 만족하지 않는 경우 
        return false; // 굴다리 전체를 비출 수 없음
    }
    
    for(int i=1; i<m; i++){
        if(light[i]-light[i-1] > 2*length){ // 조건 2번 만족하지 않는 경우
            return false; // 굴다리 전체를 비출 수 없음
        }    
    }
    
    //마지막 가로등 처리 
    if(n-light[m-1] > length){ // 조건 3번 만족하지 않는 경우 
        return false; // 굴다리 전체를 비출 수 없음 
    }
    
    return true; // length로 굴다리 전체를 비출 수 있음
}

//이분 탐색 함수
void binarySearch(){
    //초기화 
    int start = 0;
    int end = n; //굴다리의 전체 길이가 n이니까, end를 n으로 설정해두기
    int mid = (start + end) / 2;
     
    while(start <= end){
        if(check(mid)){ // mid가 조건에 부합한다면, 
            ans = mid; // 정답 처리 해두기 
            end = mid - 1; // 더 짧은 길이로 다음 탐색 
        }
        else{ // mid가 조건에 부합하지 않는다면,
            start = mid + 1; // 더 긴 길이로 다음 탐색 
        }
        
        mid = (start + end) / 2;
    }
}

int main()
{
    //입력
    cin >> n >> m;
    light.resize(m); //입력 받은 가로등 개수 m으로 light벡터 크기 설정
    for(int i=0; i<m; i++){//가로등 위치 입력 받기 
        cin >> light[i];
    }
    
    //연산
    binarySearch();
    
    //출력
    cout << ans;
    
    return 0;
}