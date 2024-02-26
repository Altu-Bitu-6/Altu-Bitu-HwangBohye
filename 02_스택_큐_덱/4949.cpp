#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;//스택

    char c;

    while(1){
        // "cin >>"는 공백을 기준으로 입력을 받아서, 공백 문자를 입력으로 못 받음
        cin.get(c);

        if(c=='.'){//중단
            break;
        }

        else if(c!='.' &&  c!='\n'){//문장 입력

            do{
                if(c=='(' || c=='['){
                    s.push(c);
                }

                else if((c==')' || c==']') && !s.empty()){
                    if(c==')' && s.top()=='('){
                        s.pop();
                    }
                    else if(c==']' && s.top()=='['){
                        s.pop();
                    }
                    else{//균형 안맞는 경우 ex)  (]
                        s.push(c);// -> empty불가능
                    }
                }

                else if((c==')' || c==']') && s.empty()){//균형 안맞는 경우 ex)  ()]
                    s.push(c);// -> empty불가능
                }

                cin >> c;

            }while(c!='.');


            //균형 검사
            if(s.empty()){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
                while(!s.empty()){ // 다음 문장을 위해 스택 비우기
                    s.pop();
                }
            }

        }


    }

    return 0;
}
