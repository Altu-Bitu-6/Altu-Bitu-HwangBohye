#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; 
const int INF = 2e5; //초대 v-1개 간선을 지나게 됨 -> (v * max가중치)


//다익스트라
vector<int> dijkstra(int start, int n, vector<vector<ci>>& graph){
    vector<int> dist(n+1 , INF); //각 정점까지의 최단 경로 저장// 모두 INF로 초기화
    
    //현재 탐색한는 중간 정점까지의 최단 경로 
        //first는 시작점으로부터의 거리 
        // second는 정점 
    priority_queue<ci, vector<ci>,  greater<ci>> pq; 
    
    //시작 정점 초기화 
    dist[start] = 0;
    pq.push({0, start});//큐에 {시작 정점 가중치, 시작 정점}넣어두기
    
    while(!pq.empty()){
        int weight = pq.top().first; //현재 정점까지의 경로 값(가중치)
        int node = pq.top().second; //현재 탐색하려는 정점 
        pq.pop();//탐색한 노드 큐에서 제거 
        
        if(weight > dist[node]){ //이미 더 작은 값으로 기록된 정점(갱신 필요 없음) 
            continue;
        }
        
        //else: 갱신 여부 판단할 필요가 있음
        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first; //node와 연결된 정점 
            //시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값(가중치)
            int next_weight = weight + graph[node][i].second;
            
            if(next_weight < dist[next_node]){//갱신할 필요가 있는 경우
                dist[next_node] = next_weight; //갱신
                pq.push({next_weight, next_node});//큐에 {가중치,정점}으로 삽입
            }
        }
    }
    
    return dist;
}


//모두 최단 경로로 오는데, 그중 젤 오래 걸리는 사람을 찾아라 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, m, x; //n개 마을&학생 // m개의 단방향 도로//  x번 마을(도착 마을)
    cin >> n >> m >> x;
    
    int s, e, t;//시작점//끝점//소요시간
    vector<vector<ci>> road(n+1,  vector<ci>(0));//인접 리스트 
    for(int i=0; i<m; i++){
        cin >> s >> e >> t;
        road[s].push_back({e, t});
    }

    //연산 
    vector<int> students(n+1, 0);
    int longest_student = 0;
    
    vector<int> come = dijkstra(x, n, road); //파티장으로 가는 최단경로 
    for(int i=1; i<=n; i++){
        vector<int> dist = dijkstra(i, n, road); //각자 집으로 돌아가는 최단경로
        int goback = dist[x]; // (x->본인 집)
      
        students[i] = goback+come[i]; //오고 가는 최단 경로 시간 학생별로 저장 
        if(students[i] > longest_student){ //가장 오래걸리는 학생 찾기
            longest_student = students[i];
        }
    }
    
    
    //출력 
    cout << longest_student;
    
    return 0;
}