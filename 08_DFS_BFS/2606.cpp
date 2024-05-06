#include <iostream>
#include <vector> 

using namespace std;

int n; // 컴퓨터 수
int m; // 관계 쌍 수 
vector<vector<int>> li; // 각 컴퓨터들의 연결 관계 
vector<bool> visited; // 각 컴퓨터에 대한 방문 체크 

int cnt = 0; //1으로 인해 감염된 컴퓨터의 수

void dfs(int index){
    visited[index] = true;
    
    
    for(int i=1; i<=n; i++){
        if(li[index][i]==1 && !visited[i]){//연결된 컴퓨터중 방문하지 않은 컴퓨터인 경우 
            cnt++;//감염된(연결된) 컴퓨터 카운드하기
            dfs(i);
        }
    }
}

int main()
{
    
    cin >> n;
    li.assign(n+1, vector<int> (n+1, 0));
    visited.assign(n+1, false);
    
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        //양방향 그래프
        li[a][b] = 1;
        li[b][a] = 1;
    }
    
    dfs(1); // 1번 컴퓨터 감염으로 시작 
    
    cout << cnt; 

    return 0;
}