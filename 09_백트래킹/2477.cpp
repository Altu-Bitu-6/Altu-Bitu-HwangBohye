#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
vector<pi> field(6);//밭 넓이 정보 // <방향, 길이>
int max_x, max_y; // field에서 해당하는 인덱스를 저장해두기!

//밭의 가로, 세로 최대 길이 찾기 
void findMax(){
    //max_x & max_y 초기값 설정
    if(field[0].first==1 || field[0].first==2){
        max_x = 0;
        max_y = 1;
    }
    else{
        max_x = 1;
        max_y = 0;
    }
    
    for(int i=0; i<6; i++){
        if(field[i].first==1 || field[i].first==2 ){ //가로 방향
            if(field[max_x].second < field[i].second){//max_x 갱신
                max_x = i;
            }
        } 
        else if(field[i].first==3 || field[i].first==4 ){ //세로 방향
            if(field[max_y].second < field[i].second){//max_y 갱신
                max_y = i;
            }
        } 
    }
}


//밭 넓이 구하기기
int fieldArea(){
    int remove_rect_x = (max_x + 3) % 6; //삭제할 부분 사각형의 가로 길이 인덱스 
    int remove_rect_y = (max_y + 3) % 6; //삭제할 부분 사각형의 세로 길이 인덱스 
    int remove_rect_area = field[remove_rect_x].second * field[remove_rect_y].second; //삭제할 부분 사각형의 넓이 
    
    int area = (field[max_x].second * field[max_y].second) - remove_rect_area; // (큰 사각형 - 삭제할 부분 사각형)
    
    return area;
}

int main()
{
    int k; //1(m^2)에서 자라는 참외 개수 
    cin >> k;
    
    for(int i=0; i<6; i++){
        cin >> field[i].first;  //방향 
        cin >> field[i].second; //길이
    }
    
    //밭의 최대 가로, 세로 길이 구하기 
    findMax();
    
    //밭 넓이 구하기 
    int field_area = fieldArea(); 
    
    //밭에서 자라는 참외 수 출력
    cout << field_area*k ;

    return 0;
}