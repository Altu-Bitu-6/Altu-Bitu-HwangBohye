#include <iostream>
#include <deque>

using namespace std;

int fullGround(deque<int> &sy_g, deque<int> &dd_g){
    if(!sy_g.empty() && !dd_g.empty()){//둘 다 그라운드가 채워져 있을 때
        return 1;
    }
    return 0; //둘 중 하나라도 비어있는 경우 
}


void merge(deque<int> &ground, deque<int> &de){ // 그라운드의 카드 덱으로 이동(합치기)
    while(!ground.empty()){
        de.push_front(ground.front());
        ground.pop_front();
    }
}


void checkGround(deque<int> &dd, deque<int> &sy, deque<int> &dd_g, deque<int> &sy_g){
    //양 쪽 그라운드에 모두 카드가 존재하는 상황에서 그라운드 카드 합 5인가? -> 수연 승 -> 수연이 그라운드 카드 가져가기 
    if(fullGround(sy_g, dd_g) && (dd_g.back()+sy_g.back() == 5)){
        merge(dd_g, sy);//상대 그라운드 먼저 합치고
        merge(sy_g, sy);//본인 그라운드 합치기
    }
    
    //그라운드에 5카드가 존재하는가? -> 도도 승 -> 도도가 그라운드 카드 가져가기 
    if((!dd_g.empty()&&dd_g.back()==5) || (!sy_g.empty()&&sy_g.back()==5)){
        merge(sy_g, dd);//상대 그라운드 먼저 합치고
        merge(dd_g, dd);//본인 그라운드 합치기
    }
}


void putDownCard(deque<int> &de, deque<int> &ground){ //본인 그라운드에 본인 카드 내려 놓기 
    ground.push_back(de.back()); 
    de.pop_back();
}

 
int game(int m, deque<int> &dd, deque<int> &sy){
    deque<int> sy_g;// 수연의 그라운드
    deque<int> dd_g;// 도도의 그라운드
    
    int turn = 1;//1->도도 //(-1)->수연 
    
    //m회 게임 진행 
    for(int i=0; i<m; i++){
        //순서대로 카드 내기
        if(turn==1){//도도 턴
            putDownCard(dd, dd_g);
            turn *= -1;
        }
        else if(turn==-1){//수연 턴 
            putDownCard(sy, sy_g);
            turn *= -1;
        }
            
        //중간에 카드가 먼저 다 떨어진 사람이 있다면 게임 끝
        if(dd.empty()){//도도의 카드 다 떨어진 경우
            return 1;//수연 승
        }
        if(sy.empty()){///수연의 카드 다 떨어진 경우
            return -1;//도도 승 
        }
        
        //그라운드 카드 정리
        checkGround(dd, sy, dd_g, sy_g);
    }
  
    //승패 결정
    if(dd.size() < sy.size()){
       return 1; // 수연 승
    }
    else if(dd.size() > sy.size()){
        return -1; //도도 승
    }
    return 0; // 비김
}


int main()
{
    int n; // 각각 배부 받을 카드(덱)의 개수
    int m; // 게임 진행 횟수
    cin >> n >> m;
    
    deque<int> dd;// 도도의 덱
    deque<int> sy;//수연의 덱
    
    for(int i=0; i<n; i++){
        int d_num, s_num;
        cin >> d_num >> s_num  ;
        
        dd.push_back(d_num);
        sy.push_back(s_num);
    }
    
    int winner = game(m, dd, sy);
    
    if(winner==1){
        cout << "su";
    }
    else if(winner==0){
        cout << "dosu";
    }
    else if(winner==-1){
        cout << "do";
    }
    
    return 0;
}