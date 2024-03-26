#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li;
vector<pair<int,int>> stack;
vector<int> visited;


void check_rotation(int current_num, int current_dir){
    //current_num바퀴의 좌측 바퀴의 회전 여부 살피기
    if(current_num - 1 >= 0 && visited[current_num - 1] == 0){ //바퀴 인덱스 제한 && 방문한 적 없는 바퀴 
        if(li[current_num][6] != li[current_num - 1][2]){//맞닿은 톱니 면이 서로 다른 극인 경우 
            stack.push_back(make_pair(current_num - 1, current_dir * -1));//회전할 바퀴 추가
            visited[current_num - 1] = 1;//방문했음을 체크
            check_rotation(current_num - 1, current_dir * -1);//재귀 함수로 다음 바퀴의 회전 여부도 체크하기 
        }
    }
    
    //current_num바퀴의 우측 바퀴의 회전 여부 살피기
    if(current_num + 1 < li.size() && visited[current_num + 1] == 0){//바퀴 인덱스 제한 && 방문한 적 없는 바퀴 
        if(li[current_num][2] != li[current_num + 1][6]){//맞닿은 톱니 면이 서로 다른 극인 경우 
            stack.push_back(make_pair(current_num + 1, current_dir * -1));//회전할 바퀴 추가
            visited[current_num + 1] = 1;//방문했음을 체크
            check_rotation(current_num + 1, current_dir * -1);//재귀 함수로 다음 바퀴의 회전 여부도 체크하기 
        }
    }
}


int main()
{
    int t, k;//바퀴 개수//회전 횟수 
    
    //톱니 바퀴 정보 입력
    cin >> t;
    li.resize(t);
    
    for(int i=0; i<t; ++i){
        cin >> li[i];//톱니바퀴 상태 입력 
    }
    
    //회전 정보 입력
    cin >> k;
    for(int i=0; i<k; ++i){
        int num, direction;//방향입력(시계 방향 1, 반시계 벙향 -1)
        cin >> num >> direction; //i번째 회전 시 바퀴 번호와 방향 정보 입력 
        
        stack.clear();
        stack.push_back(make_pair(num - 1, direction));//해당 바퀴 번호의 인덱스는 -> [바퀴 번호-1]
        
        //방문한 바퀴 번호는 visited에 1로 저장
        visited.assign(t, 0); //t개 만큼 0으로 초기화
        visited[num - 1] = 1;// 1로 방문했음을 표시 
        
        //스택에 num바퀴와 동시에 회전할 바퀴를 찾아 넣기
        check_rotation(num - 1, direction);
        
        while(!stack.empty()){
            //stack에서 한개의 바퀴 회전 정보를 꺼내기 
            pair<int, int> top = stack.back();
            stack.pop_back();
            
            int tmp_num = top.first; //회전할 바퀴 번호
            int tmp_dir = top.second; // 회전할 방향
            
            if(tmp_dir == 1){//시계 방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); // [7] + ([0]~[6])
            } 
            else{//반 시계 방향
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0]; // ([1]~[7]) + [0]
            }
        }
    }
    
    
    //12시 방향이 s극인 바퀴 수 세기 
    int cnt = 0;
    for(int i=0; i<t; ++i){
        if(li[i][0] == '1'){
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}