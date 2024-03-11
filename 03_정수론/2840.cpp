#include <iostream>
#include <vector>
using namespace std;

void luckyWheel(int n, int k){
    vector<char> str(n,'?');
    vector<bool> used(26,false);// 문자 중복 체크

    bool exist = true; //행운의 바퀴가 없다면 false
    int i=0;//화살표가 가리키는 인덱스

    while(k--){
        int change;//이동 칸 횟수
        char c;//화살표가 가리키는 문자
        cin >> change >> c;
        

        //화살표 이동
        change %= n;
        i = (i - change + n)%n;
        

        if(str[i]==c){//해당 위치 같은 문자
            continue;
        }
        else if(str[i]!=c && str[i]!='?'){//해당 위치에 이미 다른 문자
            exist = false;
        }
        else if(str[i]!=c && str[i]=='?'){//해당 위치 새로운 문자
            if(used[c-'A']){//문자 중복 사용일 경우
                exist = false;
            }
            else{
                str[i] = c;
                used[c-'A'] = true;
            }
        }
    }
    
    
    //출력
    if(exist){//존재하는 바퀴일 경우
        while(n--){
            cout << str[i];
            i = (i+1) % ((int)str.size());
        }
    }
    else{//존재하지 않은 바퀴일 경우
        cout << "!";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    luckyWheel(n, k);

    return 0;
}