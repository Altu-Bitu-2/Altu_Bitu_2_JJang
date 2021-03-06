//
// Created by user on 2022-03-15.
//
#include <iostream>
#include <map>

using namespace std;

/**
 * 개강총회가 시작하기 전에 입장한 학회원을 먼저 map 에 삽입
 * 개강총회를 끝내고 나서부터 스트리밍을 끝낼 때까지의 시간대의 채팅 기록을 보고 퇴장 여부 확인
 * -> 이때, 한 사람이 채팅 여러개 남겼을 수 있으므로 이미 확인한 사람 체크하는 게 중요 (map 의 value 값 활용해서 체크)
 * 시간은 문자열로 받아서 처리 (대소관계 숫자와 동일)
 */

int main() {

    string s, e, q, t, name; //문자열 변수 s,e,q,t,name을 선언
    map<string, bool> m; // key값을 string, value값을 bool로 하는 맵을 선언
    int ans = 0; //출석 확인된 학회원 인원 수

    //입력 & 연산
    cin >> s >> e >> q; //s,e,q값을 키보드로 입력받는다
    while (cin >> t >> name) { //입력이 있을 때 동안 반복
        if (t <= s) { //개강총회 시작하기 전 입장 시간대
            m[name] = true; //우선 저장
        } else if (t >= e && t <= q) { //개강총회 끝 ~ 스트리밍 끝 시간대
            if (m[name]) { //출석 확인
                ans++;
                m[name] = false; //같은 사람 여러번 출석 되면 안되므로 체크
            }
        }
    }

    cout << ans << '\n'; //출력받는다
    return 0;
}
