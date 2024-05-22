#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

//사과가 존재하면 board의 해당 위치를 APPLE(1), 뱀이 존재하면 SNAKE(2), 아무것도 없으면 EMPTY(0)로 설정
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;


/*게임이 몇 초에 끝나는지 계산*/
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    // 동(→), 남(↓), 서(←), 북(↑)
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    // 초기화
    // 뱀의 머리와 꼬리 좌표에 대한 접근 필요 -> deque 사용!
    deque<ci> snake; // 뱀의 위치 정보
    snake.push_front({1, 1}); //뱀의 첫 시작 좌표 {1,1}로 초기화
    board[1][1] = SNAKE; //뱀의 첫 시작 좌표 {1,1}로 초기화

    int time = 0; // 현재 시간
    int dir = 0;  // 현재 방향
    while (true) {
        // 방향 변환 정보가 있다면 // 방향 업데이트
        if (cmd[time] == 'L') { // 왼쪽 회전
            dir = (dir + 1) % 4;
        } else if (cmd[time] == 'D') { // 오른쪽 회전
            dir = (dir + 3) % 4;
        }

        // 시간 증가 // 시간 업데이트 
        time++;

        // 다음에 뱀의 머리가 위치하게 될 칸 -> 새로운 뱀의 머리 좌표를 {nx, ny}로 설정
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 게임 종료 조건: 벽에 부딪히거나, 자기자신의 몸에 부딪힘
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break;
        }
        

        // 이동
        snake.push_front({nx, ny}); // 머리를 다음 칸에 위치시킴 // 새로 이동한 좌표를 deque 앞부분에 추가
        if (board[nx][ny] != APPLE) { // 이동한 칸에 사과가 없다면(몸길이가 그대로라면) 꼬리를 다음 칸에 위치시킴
            ci tail = snake.back();
            board[tail.first][tail.second] = EMPTY; //기존 꼬리 좌표 값을 EMPTY(0)로 바꾸고
            snake.pop_back(); // deque에서 pop
        }
        board[nx][ny] = SNAKE; //머리를 다음칸에 위치시킴에 따라, 보드 상태도 변화(갱신)
    }
    return time;
}

int main() {
    int n, k, x, y, l, time;
    char command; 

    //입력
    cin >> n >> k; //보드 크기// 사과 개수
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY));
    while (k--) { //보드에 사과가 있는 위치 표시
        cin >> x >> y; //사과가 존재한는 위치의 좌표 
        board[x][y] = APPLE; // 해당 위치에 사과가 존재함을 표시
    }

    cin >> l; //뱀의 방향 변환 횟수
    map<int, char> cmd; // 정수 정보가 증가하는 순으로 저장됨
    while (l--) {
        cin >> time >> command; // 뱀의 방향 변환 정보
        cmd[time] = command;
    }

    // 게임이 몇 초에 끝나는지 연산 및 출력
    cout << playGame(n, board, cmd);
    return 0;
}