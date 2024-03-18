#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void addX(int *s, int x){
    *s = *s | (1<<x); // s에 x추가
}

void removeX(int *s, int x){
    *s = *s & (~(1<<x)); // s에 x제거
}

int checkX(int *s, int x){
    int exist = 0;
    if(*s & (1<<x)){//s에 x가 존재
        exist = 1;
    }

    return exist;
}

void toggleX(int *s, int x){
    if(checkX(s, x)){//s에 x가 존재
        removeX(s, x);
    }
    else{//s에 x없음
        addX(s, x);
    }
}

void allS(int *s){
    int k=20;
    while(k--){
        addX(s, k);
    }
}
void emptyS(int *s){
    *s = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int s = 0; // 비어있는 공집합 S
    int n;
    cin >> n;

    while(n--){
        int x;
        string inst;//명령어
        cin >> inst;

        if(inst=="add"){
            cin >> x;
            addX(&s, x-1);
        }
        else if(inst=="remove"){
            cin >> x;
            removeX(&s, x-1);
        }
        else if(inst=="check"){
            cin >> x;
            cout << checkX(&s, x-1) << "\n";
        }
        else if(inst=="toggle"){
            cin >> x;
            toggleX(&s, x-1);
        }
        else if(inst=="all"){
            allS(&s);
        }
        else if(inst=="empty"){
            emptyS(&s);
        }
    }

    return 0;
}