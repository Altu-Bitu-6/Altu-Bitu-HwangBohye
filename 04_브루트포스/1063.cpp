#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<char, int> p;

void move(string direction, p &king, p &stone){
    int x=0;//x축 이동 정보
    int y=0;//y축 이동 정보
    
    if(direction=="R"){         x++; }
    else if(direction=="L"){    x--; }
    else if(direction=="B"){    y--; }
    else if(direction=="T"){    y++; }
    else if(direction=="RT"){   x++; y++; }
    else if(direction=="LT"){   x--; y++; }
    else if(direction=="RB"){   x++; y--; }
    else if(direction=="LB"){   x--; y--; }
    
    //king 이동 시, king이 체스판 안에 있는지 확인
    if('A'<=(king.first+x) && (king.first+x)<='H' && 1<=(king.second+y) && (king.second+y)<=8){
        //king 이동
        king.first += x;
        king.second += y;
    }
    
    //king 이동 후, stone의 위치 확인
    if(king.first==stone.first && king.second==stone.second){//동일 위치시 stone도 이동
        //stone 이동 시, stone이 체스판 위에 있는지 확인
        if('A'<=(stone.first+x) && (stone.first+x)<='H' &&  1<=(stone.second+y) && (stone.second+y)<=8){ 
            //체스판 위에 있을 경우 -> stone도 이동
            stone.first += x;
            stone.second += y;
        }
        
        else{
            //체스판 밖으로 나갈 경우 -> king 이동 취소
            king.first -= x;
            king.second -= y;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    p king;
    cin >> king.first >> king.second;
    
    p stone;
    cin >> stone.first >> stone.second;
    
    int n;
    cin >> n;
    
    string direction;
    while(n--){
        cin >> direction;
        //연산
        move(direction, king, stone);
    }
    
    //출력
    cout << king.first << king.second << "\n";
    cout << stone.first << stone.second;

    return 0;
}