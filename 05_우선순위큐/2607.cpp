#include <iostream>
#include <vector>
using namespace std;

typedef pair<string, vector<int>> pi; // <단어, 알파벳 구성>

void alphaData(pi &word){
    for(int i=0; i<(int)word.first.size(); i++){
        word.second[word.first[i] - 'A']++;
    }
}

int compare(pi &first_word, pi &word){
    int diff = 0;
    
    for(int i=0; i<26; i++){
        diff += abs(first_word.second[i] - word.second[i]);
    }
    
    return diff;
}

bool similar(pi &first_word, pi &word){
    int fw_size = first_word.first.size();
    int w_size = word.first.size();
    int diff_c = 0; //알파벳 구성 차이
    
    if(fw_size == w_size){
        diff_c = compare(first_word, word);
        
        if(diff_c<=2){ // 같은 구성 || 하나 다른 문자 치환
            return true;
        }
    }
    else if((fw_size-w_size)==1 || (fw_size-w_size)==-1){ // 한 문자만을 더한거나 뺀 경우
        diff_c = compare(first_word, word);
        
        if(diff_c==1){ 
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n;
    cin >> n;
    
    pi first_word;
    first_word.second.assign(26, 0);
    
    cin >> first_word.first;
    alphaData(first_word);
    
    
    int ans = 0; //비슷한 단어 개수 저장
    
    while(--n){
        pi word;
        word.second.assign(26, 0);
    
        cin >> word.first;
        alphaData(word);
        
        if(similar(first_word, word)){// 비슷한 단어일 경우 
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}