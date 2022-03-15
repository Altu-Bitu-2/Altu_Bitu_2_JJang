//
// Created by user on 2022-03-15.
//
#include <iostream>
#include <map>

using namespace std;

/**
 * 같은 종류의 옷이 각각 몇 벌 있는지만 알면 됨
 */

int main() {
    int t, n;//정수형 변수 t와 n을 선언
    string outfit, kind; //문자열 변수 outfit과 kind를 선언

    cin >> t;//t값을 키보드로부터 입력받음
    while (t--) {//반복문 while 사용 t가 하나씩 줄어들면
        map<string, int> m;//맵을 사용하여 key(확장자)로 string을, value(확장자 파일 개수)로 int를 선언

        cin >> n;//n값을 키보드로부터 입력받음
        while (n--) {//n이 하나씩 줄어들면
            cin >> outfit >> kind;//outfit, kind값을 입력받음
            m[kind]++;//kind값에 하나씩 늘려준다
        }

        //연산
        int result = 1;// 정수형 변수 result의 초기값을 1로 설정한다
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            result *= (iter->second + 1); //해당 종류의 옷을 입기(iter->second) + 안 입기(1)
        }

        //출력
        cout << result - 1 << '\n'; //알몸인 경우 제외하고 출력한다
    }
}

