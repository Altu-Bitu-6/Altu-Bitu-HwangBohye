#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt = 0;

    int n,m;
    cin >> n >> m;

    map<string,int> s;
    for(int i=0; i<n; i++){
        string set_str;
        cin >> set_str;

        s[set_str] = 1;
    }

    for(int i=0; i<m; i++){
        string str;
        cin >> str;

        if(s[str]==1){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}