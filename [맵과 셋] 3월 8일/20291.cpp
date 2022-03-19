//
// Created by user on 2022-03-15.
//
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    int n;
    string input; //key와 value 쌍이 필요하고 중복없이 정렬해야하므로 map을 사용
    map<string, int> extension; //key(확장자)로 string을, value(확장자 파일 개수)로 int를 선언


    cin >> n; //n값을 키보드로부터 입력받음
    while (n--) { //while반복문을 사용해서 n을 줄여나감
        cin >> input; // input값을 입력받음
        //string.substr(pos, len): 첫 번째 문자의 위치(pos)부터 pos + len 까지의 부분 문자열
        //pos + len 이 문자열보다 길다면 문자열 마지막 문자까지만 리턴하도록 처리
        string ext = input.substr(input.find('.') + 1, input.length()); //.뒤의 부분 문자열 추출
        extension[ext]++; //확장자 개수 추가
    }

    for (auto iter = extension.begin(); iter != extension.end(); iter++) { //처음값부터 끝값까지 for문을 이용
        cout << iter->first << ' ' << iter->second << '\n';//출력
    }
    return 0;
}

