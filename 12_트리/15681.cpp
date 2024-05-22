#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans; //각 정점을 루트로 설정시, 해당 트리의 노드 개수 저장 

int findNodeCnt(vector<vector<int>>& graph, int root, vector<bool>& visited){
    visited[root] = true;//현재 정점 방문 체크 
    int cnt = 1; //현재 root에 대한 트리의 정점 개수 초기화
    
    //현재  root와 연결된 노드들 방문하기 
    for(int i = 0; i < graph[root].size(); i++) {
        int next = graph[root][i];
        
        if(!visited[next]){//방문한 적 없음
            cnt += findNodeCnt(graph, next, visited);
        }
    }
    
    ans[root] = cnt;
    
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, r, q; //트리의 정점 수/ 루트 번호/ 쿼리 수
    cin >> n >> r >> q;

    //그래프 입력 
    vector<vector<int>> graph(n+1, vector<int>(0)); //연결 관계 저장 
    for(int i=0; i<n-1; i++){
        int v, u;
        cin >> v >> u; //서로 연결된 두 노드
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    ans.resize(n+1);
    vector<bool> visited(n+1, false);//방문 표시 
    findNodeCnt(graph, r, visited);
    
    
    //출력
    for(int i=0; i<q; i++){//쿼리의 답
        //루트가 u일 경우, 해당 트리의 정점 수 
        int u;
        cin >> u;
        cout << ans[u] << "\n";
    }
    
    return 0;
}