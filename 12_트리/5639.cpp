#include <iostream>
#include <vector>

using namespace std;

vector<int> order;

void PrintPostOrder(int start, int end) {
    if (start > end){
        return;
    }
    
    // 현재 구간의 첫 요소는 서브 트리의 루트에 해당함
    int root = order[start];
    int rightStart = start + 1;
    
    // (이진트리 특성을 이용해 )오른쪽 서브트리의 시작 인덱스 찾기 
    while (rightStart <= end && order[rightStart] < root) {
        rightStart++;
    }
    
    /*후위 순회*/
    
    // 왼쪽 서브트리 출력
    PrintPostOrder(start + 1, rightStart - 1);
    
    // 오른쪽 서브트리 출력
    PrintPostOrder(rightStart, end);
    
    // 루트 노드를 출력
    cout << root << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n;
    while (cin >> n) {
        order.push_back(n);
    }
    
    PrintPostOrder(0, order.size() - 1);
    
    return 0;
}
