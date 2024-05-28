#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100; // 평면의 크기 (100x100)

// [0]우 [1]상 [2]좌 [3]하
int dy[4] = { 0, -1, 0, 1 }; // y 이동 방향 배열
int dx[4] = { 1, 0, -1, 0 }; // x 이동 방향 배열


// 1x1 정사각형 개수 계산 
int cntSquares(vector<vector<bool>>& plane) {
    int ans = 0; // 정사각형 개수 초기화
    for (int i = 0; i < SIZE; i++) { // palne 탐색
        for (int j = 0; j < SIZE; j++) {
            if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1]) {// 정사각형 존재하는 경우
                ans++; // 정사각형 개수 증가
            }
        }
    }
    
    return ans; // 총 정사각형 개수
}


//평면에 드래곤 커브를 표시
void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) {
    vector<int> direct; // 드래곤 커브의 방향
    plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // 초기 위치와 첫 이동 위치를 true로 설정
    x += dx[d]; y += dy[d];//해당 방향으로 이동 
    direct.push_back(d); // 초기 방향 저장
    
    while (g--) { // 세대 만큼 반복
        int size_d = direct.size(); 
        for (int j = size_d - 1; j >= 0; j--) { // 선분의 개수 만큼 & 거꾸로 방향으로 반복
            int next_d = (direct[j] + 1) % 4; // 새로운 방향 계산 (90도 회전)
            x += dx[next_d]; // 새로운 방향으로 x 갱신
            y += dy[next_d]; // 새로운 방향으로 y갱신
            plane[y][x] = true; // 이동한 위치를 true로 설정
            direct.push_back(next_d); // 새로운 방향 저장
        }
    }
}

/*
* 규칙
* 0 세대: 0
* 1 세대: 0 1
* 2 세대: 0 1 2 1
* 3 세대: 0 1 2 1 2 3 2 1
* ...
* N 세대: concat((N-1세대), ((N-1세대 거꾸로) + 1)%4)
* 평면(좌측 상단이 (0, 0))에 드래곤 커브를 그린 후 정사각형의 개수를 계산
* 드래곤 커브는 평면 밖으로 나가지 않음으로 범위를 확인할 필요 없음
* 1. 0 세대의 드래곤 커브를 먼저 저장 (초기 조건)
* 2. 세대를 거듭하면서 드래곤 커브를 그림 (규칙을 파악하는 것이 중요)
* 3. 드래곤 커브가 그려진 평면 상의 정사각형의 개수 계산 (네 꼭짓점 확인)
*/

int main()
{
    int n, x, y, d, g; //드래곤 커브 개수 // 시작 점 좌표 // 시작 방향 // 세대 정보 
    vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); // 평면
    
    //입력
    cin >> n; 
    
    //연산
    while (n--) { 
        cin >> x >> y >> d >> g; // 각 드래곤 커브의 정보 입력
        drawDragonCurve(plane, x, y, d, g); // 드래곤 커브를 평면에 그림
    }
    
    //출력
    cout << cntSquares(plane) << '\n'; 
    
    return 0;
}
