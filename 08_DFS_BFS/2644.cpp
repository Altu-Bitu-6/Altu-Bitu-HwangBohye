#include <iostream>
#include <vector>

using namespace std;

int n; // 입력 인원(정점의 개수)
int m; // 부모 자식 관계 표현 횟수
int x, y; //관계 조사하려는 두 사람
vector<vector<int>> li; //사람들의 관계를 저장해 둔 2차원 벡터
vector<bool> visited; //방문 노드 체크용 벡터

int cnt = 0; // 촌수 계산용 변수
int relation = -1; //x와 y의촌수 //친적 관계 아니면 -1// 친적 관계면 촌수로 갱신

void dfs(int index){ 
    visited[index] = true;
    
    if(index == y){//x->y 까지 도달 했을 경우(친적 관계임)
        relation = cnt; // 이때까지의 cnt 값이 relation임 
    }

    for(int i=1; i<=n; i++){
        if(li[index][i]==1 && !visited[i]){ // 방문하지 않았다면
            cnt++; // 촌수 증가
            dfs(i);
            cnt--; // 촌수 감소
        }
    }
}

int main()
{
    //입력
    cin >> n;
    cin >> x >> y;
    cin >> m;
    
    // 초기화
    li.assign(n+1, vector<int>(n+1, 0));
    visited.assign(n+1, false);
    
    //입력
    for(int j=0; j<m; j++){
        int a, b;//부모 번호, 자식 번호
        cin >> a;
        cin >> b;
        
        //양 방향 그래프//
        li[a][b] = 1;
        li[b][a] = 1;
    }
    
    dfs(x); // 시작 정점 x로 탐색 시작
    
    cout << relation; 

    return 0;
}