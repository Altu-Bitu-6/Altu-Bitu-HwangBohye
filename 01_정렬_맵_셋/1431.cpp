#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int compare(const string a, const string b){
    int a_len = a.size();
    int b_len = b.size();

    if( a_len != b_len ){// 길이 오름차순
          return a_len < b_len;
    }
    else{
        int a_sum = 0;
        int b_sum = 0;

        for(int i=0; i<a_len; i++){
            if( isdigit(a[i]) ){
                a_sum += a[i] - 48;
            }
        }
        for(int i=0; i<b_len; i++){
            if( isdigit(b[i]) ){
                b_sum += b[i] - 48;
            }
        }

        if(a_sum != b_sum){ // 합 오름차순
            return a_sum <b_sum;
        }
        else{//사전순
            return a<b;
        }

    }

}

int main()
{
    int n;
    cin >> n;

    vector<string> arr;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}