#include <iostream>
#include <vector>
using namespace std;

int getGcd(int a, int b){
    if(a<b){
        swap(a, b);
    }
    while(b){//b가 0이 아닌 동안
        a = a%b;
        swap(a, b);
    }
    return a;
}

pair<int, int> sumOfAB(pair<int, int> &a, pair<int,int> &b){
    pair<int, int> s;
    
    int a_b_lcm = a.second * b.second / getGcd(a.second, b.second); //a분모와 b분모의 lcm
    
    s.first = (a_b_lcm / a.second)*a.first + (a_b_lcm / b.second)*b.first; // 합의 분자
    s.second = a_b_lcm; // 합의 분모
    
    //기약 분수 처리
    int s_gcd = getGcd(s.first, s.second); // s의 분자와 분모의 Gcd
    s.first = s.first / s_gcd;
    s.second = s.second / s_gcd;
    
    return s;
}

int main()
{
    //입력
    pair<int, int> a; //a의 분자, 분모
    cin >> a.first >> a.second;
    
    pair<int, int> b; //b의 분자, 분모
    cin >> b.first >> b.second;
    
    
    //연산
    pair <int, int>  sum = sumOfAB(a, b);
    
    
    //출력
    cout << sum.first << " " << sum.second;
   
    return 0;
}