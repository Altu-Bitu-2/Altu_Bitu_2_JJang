//
// Created by user on 2022-03-11.
//
#include <iostream> //표준 입출력 스트림을 사용한다
#include <vector> //벡터가 들어있는 헤더파일
#include <algorithm> //원소들에 대해 작업할 수 있는 여러가지 함수를 정의하고 있다

using namespace std; //함수나 클래스 작성 시 소속된 네임스페이스를 일일이 기술하는 작업이 번거로우므로 네임스페이스를 생략하기 위해 using문 사용
const int SIZE = 20; //SIZE를 상수이면서 정수로 정의하고 그 크기는 20으로 정하자

vector<int> arr(SIZE + 1); //정수형 타입 벡터 선언, 1번 인덱스부터 시작하기 위해 크기를 (SIZE + 1)로 선언

//a ~ b를 역순으로 배치하는 함수, reverse 함수 직접 구현
void reverseAtoB(int a, int b) {
    //더하고 빼는 변화값을 증가변수로 줘서 사용, 절반까지만
    for (int i = 0; i <= (b - a) / 2; i++) {//i를 0부터 중간원소까지 하나씩 더해준다
        swap(arr[a + i], arr[b - i]);//배열 a+1번째부터 b-i-1번째 항 까지 원소를 뒤집어준다
    }
}

/**
 * 단순 구현 문제.
 * 1. 직접 구현: 카드를 역순으로 두기 = 수열을 반으로 접었다 생각할 때, 마주보는 원소끼리 swap!
 * 2. 함수 활용: <algorithm> 헤더에 있는 "reverse" 함수 사용 -> reverse(시작 반복자, 종료 반복자): 시작 ~ 종료전까지 원소들을 뒤집음
 */

int main() {//정수형 main함수를 써준다
    int a, b;//정수형 변수 a와 b를 선언

    //카드 초기화
    for (int i = 1; i <= SIZE; i++) {//i가 1부터 전체크기의 개수만큼까지 1씩 계속 더해준다
        arr[i] = i;
    }
    //입력 & 연산
    //입력이 10개로 한정되므로 for문으로 10번 입력받는 것도 가능!
    while (cin >> a >> b) { //입력이 있을 때까지만 받음 (입력이 끝나면 ctrl+D 를 눌러서 종료!)
        //헤더 함수 사용
        reverse(arr.begin() + a, arr.begin() + b + 1);//배열 begin()+a부터 배열 begin()+b까지 원소들을 뒤집어준다

        //직접 구현
        //reverseAtoB(a, b);
    }
    //출력
    for (int i = 1; i <= SIZE; i++) {
        cout << arr[i] << ' ';//위에서 진행한 for문을 화면에 출력한다
    }
    return 0;
}

