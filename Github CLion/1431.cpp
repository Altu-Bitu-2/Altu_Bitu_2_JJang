//
// Created by user on 2022-03-11.
//
#include <iostream> //표준 입출력 스트림을 사용한다
#include <algorithm> // 원소들에 대해 작업할 수 있는 여러가지 함수를 정의한다
#include <vector> // 벡터가 들어있는 헤더파일을 사용한다

using namespace std; //이름공간 클래스에 정의되어있는 함수를 사용하겠다

int sumNum(string str) {//문자열의 모든 자릿수 합을 구하는 함수를 사용한다
    int sum = 0;//sum의 초기값을 0으로 설정한다
    for (int i = 0; i < str.size(); i++) {//반복문 for문을 사용한다
        if (isdigit(str[i])) { //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 , 숫자라면 1을 더해준다
        }
    }
    return sum;//sum 값을 반환한다
}

bool cmp(const string &s1, const string &s2) {//비교함수를 사용한다
    if (s1.size() != s2.size()) { //두 문자열의 길이가 다르다면
        return s1.size() < s2.size(); //짧은 문자열이 먼저 오도록
    }
    if (sumNum(s1) != sumNum(s2)) { //두 문자열의 숫자 합이 다르다면
        return sumNum(s1) < sumNum(s2);//합이 작은 문자열이 먼저 오도록
    }
    return s1 < s2; //사전순으로 배열한다
}

int main() {
    int n;//정수형 변수 n을 선언하자
    vector<string> serial_num;

    cin >> n;//n값을 입력받는다
    serial_num.assign(n, "");
    for (int i = 0; i < n; i++) {//for문을 사용하고
        cin >> serial_num[i];//serial_num[i]를 입력받는다
    }

    sort(serial_num.begin(), serial_num.end(), cmp); //정렬함수 sort를 사용한다

    for (int i = 0; i < n; i++) { //for문을 사용하고
        cout << serial_num[i] << '\n';// 결과값 serial_num[i]을 출력한다
    }
    return 0;
}

