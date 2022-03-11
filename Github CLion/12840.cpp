//
// Created by user on 2022-03-11.
//
#include <iostream>//표준 입출력 스트림을 사용한다

using namespace std;// 이름공간 클래스에 정의되어있는 함수를 사용하겠다

const int MINUTE = 60; //1분을 초로 나타냄
const int HOUR = 60 * MINUTE; //1시간을 초로 나타냄
const int DAY = 24 * HOUR; //하루를 초로 나타냄

//변화하는 초 값 계산해서 보내주는 함수, 정수형 변수 t와 c를 선언하자
int changeTime(int t, int c) {
    //돌리는 초가 하루보다 크다면 하루가 넘어가므로 모듈러 연산 후 연산
    int change_value = c % DAY;
    if (t == 2) { //t값이 2일 때는 시간을 뒤로 가게 한다
        change_value = -change_value;
    }
    return change_value;//결과값을 출력한다
}

/**
 * 단순 구현 문제
 * 시계를 앞으로 돌리면 +, 뒤로 돌리면 -
 * !주의! 전날로 돌아가거나 다음날로 넘어갈 수 있으므로 항상 모듈러 연산을 하고,
 *       전날로 넘어갔을 경우 (음수값) 하루를 더해주는게 중요
 */

int main() {
    //입출력 속도를 향상시키기 위해서 다음과 같은 코드를 추가한다
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s, q, t, c, second = 0; //정수형 변수를 선언하고 모든 값들을 0으로 초기화한다
    //입력
    cin >> h >> m >> s;//시,분,초 순으로 값을 입력받는다
    cin >> q;//q의 값도 키보드로부터 입력받는다
    //시간 초기화
    second = h * HOUR + m * MINUTE + s;
    //입력 & 연산 & 출력
    while (q--) {//while함수를 사용한다
        cin >> t;//t값을 키보드로 입력받는다
        if (t == 3) { //시계가 가리키는 시간 출력, 만약 t가 3이라면
            second %= DAY; //하루가 넘어갔을 수 있으므로 모듈러 연산
            h = second / HOUR;
            m = (second % HOUR) / MINUTE;
            s = (second % HOUR) % MINUTE;
            cout << h << ' ' << m << ' ' << s << '\n';//시,분,초 순으로 값을 출력하고 한 줄을 띄어준다
        } else { //만약 t가 3이 아니라면, t=1일 땐 시계 앞으로(+) / t=2일 땐 시계 뒤로(-)
            cin >> c;//c값을 키보드로 입력받는다
            second += changeTime(t, c);
            if (second < 0) //전날로 넘어갔다면
                second += DAY; //하루 더해서 전날의 초(s) 양수로 바꿔준다
        }
    }
    return 0;
}

