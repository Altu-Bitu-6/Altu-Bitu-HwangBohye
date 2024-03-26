#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> checkAlpha(string str){
    vector <int> alpha;
    alpha.assign(26, 0);
    
    for(int i=0; i<str.size(); i++){
        alpha[str[i] - 'A']++;
    }
    
    return alpha;
}

string palindrom(string str){
    vector<int> alpha = checkAlpha(str);
    
    string front_part = "";
    string mid_part = "";
    string back_part = "";
    
    int mid_cnt = 0;
    for(int i=0; i<alpha.size(); i++){
        if(alpha[i]==0){
            continue;
        }
        else if(alpha[i]%2 == 0){//해당 문자의 개수가 짝수일 경우
            //앞부분 배치 
            for(int j=0; j<(alpha[i]/2); j++){
                front_part += (char)(i+'A');
            }
            //뒷 부분 배치
            for(int j=0; j<(alpha[i]/2); j++){
                back_part += (char)(i+'A');
            }
            
        }
        else{//해당 문자의 개수가 홀수인 경우  
            if(mid_cnt == 1){//mid_cnt가 1개 이상이되면 팬린드롬 불가
                return "I'm Sorry Hansoo";
            }
            mid_cnt++;
            
            //중간 배치 
            mid_part =  (char)(i+'A');
            alpha[i] -= 1;//짝수로 만들어줌
        
            //앞부분 배치
            for(int j=0; j<(alpha[i]/2); j++){
                front_part +=  (char)(i+'A');
            }
            
            //뒷 부분 배치 
            for(int j=0; j<(alpha[i]/2); j++){
                back_part +=  (char)(i+'A');
            }
            
        }
    }
    
    reverse(back_part.begin(), back_part.end());// back_part역순
    
    string ans;
    ans = front_part + mid_part + back_part;//파트 연결
    
    return ans;
}

int main()
{
    string str;
    cin >> str;
    
    string ans;
    ans = palindrom(str);
    
    cout << ans;

    return 0;
}