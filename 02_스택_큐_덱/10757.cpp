#include <iostream>
#include <vector>

using namespace std;

void sumOfAB(vector<int> &sum, string a, string b){

    int a_indx = a.size()-1; // 낮은 자리수 부터 연산 시작
    int b_indx = b.size()-1; // ..
    int carry = 0;
    int k;// 각 자릿수 간의 합

    while(a_indx>=0 || b_indx>=0){

        if(a_indx<0 && b_indx>=0){//ex)  a:5  b:1234
            k = b[b_indx--] + carry - '0';

        }
        else if(a_indx>=0 && b_indx<0 ){//ex)  a:1234  b:5
            k = a[a_indx--] + carry - '0';
        }

        else{
            k = a[a_indx--] + b[b_indx--] + carry - '0' - '0';
        }

        sum.push_back(k%10);
        carry = k / 10;

    }

    if(carry > 0){
        sum.push_back(carry);
    }

}


int main()
{
    vector<int> sum;
    string a;
    string b;

    //입력
    cin >> a;
    cin >> b;

    //A+B
    sumOfAB(sum, a, b);

    //출력
    for(int i=sum.size()-1; 0<=i; i--){
        cout << sum[i];
    }

    return 0;
}