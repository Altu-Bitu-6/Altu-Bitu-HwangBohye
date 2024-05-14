#include <iostream>
#include <vector>

using namespace std;
const int CLEAN = 2; //청소 진행한 상태를 상수로 설정

//동 서 남 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board){
    int cnt = 0; //로봇 청소기가 작동을 시작한 후 작동을 멈출 때까지 청소하는 칸의 개수
    
    while(true){
        if(board[r][c] == 0){ //현재 칸이 아직 청소되지 않은 경우 
            board[r][c] = CLEAN;//현재 칸을 청소함
            cnt++;//청소를 수행한 카의 개수를 카운트함
        }
        
        //현재 칸의 주변 4칸 중 청소되지 않은 칸 탐색
        bool find = false;//현재 칸의 주변 4칸 중 청소되지 않은 칸이 있는지 체크
        for(int i=0; i<4; i++){//반시계 방향으로 현재 칸의 주변 4칸 탐색할 것
            int nd = (d - i +3) % 4; //new direction
            int nr = r + dy[nd];//new row
            int nc = c + dx[nd];//new column
            
            if(board[nr][nc] == 0){ // 청소되지 않은 곳 존재한다면
                find =true; // 주변에 청소되지 않은 곳 있음을 체크
                
                //청소되지 않은 곳으로 현재 상태 갱신
                r = nr; 
                c = nc;
                d = nd;
        
                break;
            }
        }
        
        if(find){ //find가 true인 경우 
            continue;
        }
        
        //find가 flase일 경우//후진 여부 판단
        int bd = (d+2) % 4; //back direction
        int br = r + dy[bd]; //back row
        int bc = c + dx[bd]; //back column
        
        if(board[br][bc] == 1){ //후진할 수 없는 경우
            break; //작동 종료
        }
        
        //현재 상태를 업데이트
        r = br;
        c = bc;
    }
    
    return cnt;
}

int main()
{
    //입력
    int n, m, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    
    vector<vector<int>> board; //방의 상태 저장 
    board.assign(n, vector<int> (m,0)); //입력 받은 방의 크기로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j]; //해당 위치의 방 상태
        }
    }
    
    //연산 & 출력 
    cout << clean(n, m, r, c, d, board);
    
    return 0;
}