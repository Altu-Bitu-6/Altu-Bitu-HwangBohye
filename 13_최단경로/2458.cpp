#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; // 최대 n-1개의 간선을 지나므로 (n * 가중치 최대값)

void floyWarshall(int n, vector<vector<int>>& graph){
    for(int k=0; k<=n; k++){ //중간간 정점 
        for(int j=0; j<=n; j++){ //출발 정점 
            for(int i=0; i<=n; i++){ // 도착 정점
                //중간에 k를 거쳐서 i에서 j러 갈 때의 비용 
                int cost =  graph[i][k] + graph[k][j];
                
                //더 짧은 경로 선택 
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //입력
    int n, m;//학생 수//비교 횟수 
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++){//모든 노드가 본인과 본인의 키를 비교하면 동일 => 0으로 초기화
        graph[i][i]= 0;
    }
    int a, b;
    while(m--){//m번 비교를 통해 얻은, a가 b보다 작다는 정보를 1로 저장
        cin >> a >> b;
        graph[a][b] = 1;
    }
    
    //연산
    floyWarshall(n, graph);

    int cnt = 0;//자신의 키가 몇번째인지 알 수 있는 학생의 수
    for(int i=1; i<=n; i++){
        bool flag = true; //i번째 학생이 자신의 순서를 알수 있는지
        for(int j=1; j<=n; j++){
            if(graph[i][j]==INF && graph[j][i]==INF){ //i와j가 서로 비교된 적이 없다면 
                flag = false; //i학생은 본인의 순서를 알 수 없음
                break;
            }
        }
        if(flag){// i번 학생이 본인 순서 알 수 있다면
            cnt++;
        }
    }
    
    //출력
    cout << cnt;
    
    return 0;
}