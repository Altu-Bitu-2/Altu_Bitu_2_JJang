//
// Created by user on 2022-03-11.
//

#include <iostream> //표준 입출력 스트림을 사용한다
#include <vector> //벡터가 들어있는 헤더파일
#include <algorithm> //원소들에 대해 작업할 수 있는 여러가지 함수를 정의하고 있다

using namespace std; //이름공간 클래스에 정의되어있는 함수를 사용하겠다

typedef pair<int, int> ci; //pair<int,int> 자료형을 ci 별칭으로 사용함을 정의

bool cmp(const ci &a, const ci &b) {
    if (a.second != b.second) { //1. 둘을 비교해보고
        return a.second < b.second;//y좌표가 증가하는 순서
    }
    return a.first < b.first; //2. (y좌표가 같으면) x좌표가 증가하는 순서
}

int main() {
    int n, a, b;//정수형 변수를 선언해준다

    cin >> n;//n값을 입력받는다
    vector<ci> arr(n, {0, 0});
    for (int i = 0; i < n; i++) {//for반복문을 이용한다
        cin >> arr[i].first >> arr[i].second;//
    }
    //연산
    sort(arr.begin(), arr.end(), cmp); //사용자가 정한 함수를 기준으로 정렬해주는 sort함수를 사용한다
    //출력
    for (int i = 0; i < n; i++) {//반복문을 통해 x좌표와 y좌표를 출력한다
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}


