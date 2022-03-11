//
// Created by user on 2022-03-11.
//
#include <iostream> //표준 입출력 스트림을 사용한다
#include <algorithm> // 원소들에 대해 작업할 수 있는 여러가지 함수를 정의한다
#include <vector> // 벡터가 들어있는 헤더파일을 사용한다

using namespace std; //이름공간 클래스에 정의되어있는 함수를 사용하겠다

typedef pair<int, int> ci; //pair<int,int> 자료형을 ci 별칭으로 사용함을 정의

/**
 * 서류심사 혹은 면접심사 순위 기준으로 정렬해서 나머지 심사 순위 비교하며 푸는 문제
 * 본 풀이는 서류심사 순위를 기준으로 정렬한 풀이
 */

int cntEmploy(int n, vector<ci> rank) {
    /**
     * 서류심사가 1등인 0번 인덱스 사람은 무조건 합격이므로 1번 인덱스부터 검사
     * 현재 인덱스 사람은 서류심사 순위가 그 다음 인덱스 사람들보다 무조건 위
     * 따라서 그 전 사람들(서류심사가 현재 사람보다 높은)보다 면접심사가 높으면 합격
     */
    int ans = 1, first_rank = rank[0].second;  // 서류심사에서 1등인 사람은 무조건 합격
    for (int i = 1; i < n; i++) {
        //전 사람들 모두의 면접심사 순위보다 더 높은 경우
        if (first_rank > rank[i].second) {//다음 사람이 현재값보다 낮은 숫자의 순위를 가지면 합격이므로
            //가장 높은 면접심사 순위 계속 갱신해서 O(n) 으로 풀이
            first_rank = rank[i].second;//first값을 갱신해준다
            ans++;//합격자 명수를 증가시켜준다
        }
    }
    return ans;
}

int main() {
    int t, n, ans;//정수형 변수 t,n,ans를 선언해준다
    vector<ci> rank;

    cin >> t;//t값을 입력받는다
    while (t--) {
        cin >> n;
        rank.assign(n, ci(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> rank[i].first >> rank[i].second; //first: 서류심사 순위, second: 면접심사 순위
        }

        //연산
        //first값인 서류심사 순위가 높은 순서대로 정렬 (오름차순 정렬)
        //왼쪽값 기준 오름차순 정렬이 기본 정렬이므로 cmp함수 필요 없음
        sort(rank.begin(), rank.end());//sort함수를 사용한다
        ans = cntEmploy(n, rank);

        cout << ans << '\n';//답을 출력한다
    }
    return 0;
}

