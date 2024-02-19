#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; // 기초 대사량 변환 역치
    int l; // 현재 기초 대사량
    int a;//활동 대사량
    int total_energy_consumption;


    /*Before*/
    int w_before;
    int l_before;//e섭취량, 기초 대사량
    a = 0;
    cin >> w_before >> l_before >> t;
    l = l_before;

    /*After*/
    int day;
    int l_diet; //e섭취량
    int w_after = w_before;
    cin >> day >> l_diet >> a;


    /*일일 기초 대사량 변화 고려X => 다이어트 예상*/
    total_energy_consumption = l_diet - (l_before + a);
    w_after += total_energy_consumption * day;

    if(w_after <= 0){
        cout << "Danger Diet\n";
    }
    else{
        cout << w_after << " " << l_before << "\n";
    }




    /* 일일 기초 대사량 변화를 고려 => 다이어트 예상 */
    w_after = w_before;
    for(int i=0; i<day; i++){
        total_energy_consumption = l_diet - (l + a);
        w_after += total_energy_consumption;

        if(abs(total_energy_consumption) > t ){
            l += floor(total_energy_consumption/2.0);
        }
    }

    if(w_after<=0 || l<=0){
        cout << "Danger Diet\n";
    }
    else{
        cout << w_after << " " << l << " ";

        a=0;
        total_energy_consumption = l_before - (l + a);

        if(total_energy_consumption > 0){
            cout << "YOYO";
        }
        else{
            cout << "NO";
        }

    }

    return 0;
}
