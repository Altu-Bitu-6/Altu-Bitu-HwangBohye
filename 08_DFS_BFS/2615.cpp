#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
const int SIZE = 20; //바둑판 크기 19
const int EMPTY = 0; //빈칸

//방향의 따른 좌표 증가량
//맨 왼쪽 위 돌을 기준으로 검사 -> 오른쪽&아래쪽으로 향하는 방향만 정의 
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};
/* (dx,dy) 4가지 탐색 방향 
 [(-1,1) 대각 상승 방향] 
 [(0,1)  가로 좌측 방향] 
 [(1,1)  대각 하강 방향] 
 [(1,0)  세로 하강 방향] 
*/


//범위와 돌의 종류가 유효한지 확인
bool isValid(matrix &board, int x, int y, int color){
    return (x>0 && x<SIZE && y>0 && y<SIZE && board[x][y]==color);
}

//해당 좌표(x, y)부터 연속적으로 5알이 놓였는지 확인 
bool checkWin(matrix &board, int x, int y){
    int color = board[x][y]; //기준 색 
    
    //4방향에 대해 검사 
    for(int idx=0; idx<4; idx++){
        int cnt = 1; // 같은 방향에 놓인 같은 색 돌의 수 
       
        int prev_x = x - dx[idx];
        int prev_y = y - dy[idx];
       
        int next_x = x + dx[idx];
        int next_y = y + dy[idx];
       
        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스
        //(-> 6알 이상 놓이는 경우를 제외하기 위함)
        if(isValid(board, prev_x, prev_y, color)){
           continue;
        }
       
        //연속적으로 놓인 5알이 같은 색인지 확인 
        while(isValid(board, next_x, next_y, color) && cnt<6){
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++;
        }
        
        //cnt가 5일 때만 true 리턴 
        //(-> 5알 보다 적거나, 5알 보다 많이 놓인 경우를 제외 )
        if(cnt == 5){
            return true;
        }
    }
    
    return false;
}


int main()
{
    //입력
    matrix board(SIZE, vector<int> (SIZE, 0)); //바둑판 초기화 
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++){
            cin >> board[i][j];
        }
    }
    
    //연산 & 출력 
    for(int y=1; y<SIZE; y++){
        for(int x=1; x<SIZE; x++){
            //빈칸이면 패스
            if(board[x][y] == EMPTY){ 
                continue;
            }
            
            //승부가 결정된 경우 
            if(checkWin(board, x, y)){
                //해당 좌표(x,y)부터 연속된 다섯 개의 바둑알이 놓였다면, 
                //가장 왼쪽에 있는 바둑알인 해당 좌표 출력
                
                cout << board[x][y] << "\n"; //승리한 바둑알 색(1 or 2) 출력 
                cout << x << " " << y; //(승리)좌표 출력
                
                return 0;
            }
        }
    }
    
    //승부가 결정되지 않았을 경우 
    cout << 0;

    return 0;
}