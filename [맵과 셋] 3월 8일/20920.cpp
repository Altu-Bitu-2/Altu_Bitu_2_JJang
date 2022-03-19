//
// Created by user on 2022-03-15.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * [영단어 우선순위]
 * 1. 자주 나오는 단어일수록 앞에 배치
 * 2. 해당 단어의 길이가 길수록 앞에 배치
 * 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
 */

map<string, int> word_cnt; //맵을 사용하자

bool cmp(const string &a, const string &b) {//compare함수를 쓰자
    if (word_cnt[a] != word_cnt[b]) { //두 단어의 빈도수가 다르다면
        return word_cnt[a] > word_cnt[b];//자주 나오는 단어일수록 앞에 배치
    }
    if (a.length() != b.length()) { //두 단어의 길이가 다르다면
        return a.length() > b.length();//해당 단어의 길이가 길수록 앞에 배치
    }
    return a < b; //알파벳 사전 순서로 배치
}

int main() {
    //입출력 속도 향상을 위해 써줌
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words;
    string word;//문자열 변수 word
    int n, m;//정수형 변수 n과 m

    cin >> n >> m;  //n과 m값을 키보드로부터 입력받음

    //입력 + 영단어 횟수 저장
    while (n--) {
        cin >> word;//word값을 입력받음
        if (word.length() < m) { //길이가 m 미만이면 영단어장에 들어가지 않음
            continue;
        }
        if (!word_cnt[word]) { //중복 영단어 들어가는 것 방지
            words.push_back(word);
        }
        word_cnt[word]++; //word 단어 횟수 증가
    }

    //조건에 맞게 정렬하기 위해 sort함수 사용
    sort(words.begin(), words.end(), cmp);

    //출력
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }
    return 0;
}
