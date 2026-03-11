#pragma once
// =====================================================
// Week01: 1초에 1억 번 -- 알고리즘과 시간 복잡도
// =====================================================
// 이번 회차의 핵심: 시간 복잡도 감각 익히기
// - O(n) vs O(n^2) 실행 시간 체감
// - "1초에 약 1억 번" 감각 확인
// - 값 전달 vs 참조 전달
// - 최댓값 찾기 알고리즘
// =====================================================

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// =====================================================
// 예제 1: O(n) vs O(n^2) -- 반복문 하나 vs 반복문 둘
// =====================================================
#ifdef RUN_WEEK01_EXAMPLE01
int main() {
    cout << "===== [예제 1] O(n) vs O(n^2) 시간 비교 =====" << endl;
    cout << endl;

    // 테스트할 데이터 크기들
    vector<int> sizes = { 1000, 5000, 10000, 50000 };

    for (int n : sizes) {
        // n개짜리 배열을 준비합니다
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        cout << "--- n = " << n << " ---" << endl;

        // [O(n)] 배열 전체 합 구하기 -- 반복문 1개
        // n개의 원소를 한 번씩만 봅니다
        auto start = chrono::high_resolution_clock::now();

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];  // 한 번씩 더하기 → O(n)
        }

        auto end = chrono::high_resolution_clock::now();
        auto timeOn = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "  O(n)  합계: " << sum
            << "  |  걸린 시간: " << timeOn << " us" << endl;

        // [O(n^2)] 모든 쌍(pair)의 개수 세기 -- 반복문 2개 중첩
        // 바깥 반복문 n번 x 안쪽 반복문 n번 = n*n번
        start = chrono::high_resolution_clock::now();

        long long pairCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pairCount++;  // 모든 (i, j) 쌍 → O(n^2)
            }
        }

        end = chrono::high_resolution_clock::now();
        auto timeOn2 = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "  O(n^2) 쌍 개수: " << pairCount
            << "  |  걸린 시간: " << timeOn2 << " us" << endl;

        // 몇 배 차이나는지 보여주기
        if (timeOn > 0) {
            cout << "  => O(n^2)가 O(n)보다 약 " << timeOn2 / timeOn << "배 느림" << endl;
        }
        else {
            cout << "  => O(n)이 너무 빨라 측정 불가 (거의 즉시 완료)" << endl;
        }
        cout << endl;
    }

    cout << "n이 커질수록 O(n^2)의 시간이 폭발적으로 증가합니다!" << endl;

    return 0;
}
#endif

// =====================================================
// 예제 2: "1억 번의 감각" -- CPU가 1초에 할 수 있는 일
// =====================================================
#ifdef RUN_WEEK01_EXAMPLE02
int main() {
    cout << "===== [예제 2] 1억 번의 감각 =====" << endl;
    cout << "단순 덧셈을 반복하여 CPU 속도를 체감합니다." << endl;
    cout << endl;

    // 테스트할 반복 횟수: 1천만, 1억, 10억
    vector<long long> counts = { 10'000'000LL, 100'000'000LL, 1'000'000'000LL };
    vector<string> labels = { "1천만 (10^7)", "1억 (10^8)", "10억 (10^9)" };

    for (int t = 0; t < (int)counts.size(); t++) {
        long long repeat = counts[t];

        // 단순 덧셈을 repeat번 반복합니다
        auto start = chrono::high_resolution_clock::now();

        long long sum = 0;
        for (long long i = 0; i < repeat; i++) {
            sum += i;  // 아주 단순한 연산 1번
        }

        auto end = chrono::high_resolution_clock::now();
        double ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        cout << labels[t] << " 번 반복 → " << ms << " ms ("
            << ms / 1000.0 << " 초)" << endl;

        // sum을 출력해야 컴파일러가 최적화로 루프를 없애지 않습니다
        cout << "  (검증용 합계: " << sum << ")" << endl;
    }

    cout << endl;
    cout << "결론: 대략 '1초에 수억 번' 정도의 감각을 기억하세요." << endl;
    cout << "(CPU 성능과 컴파일 설정에 따라 차이가 있습니다)" << endl;
    cout << "이 감각이 앞으로 '이 코드가 1초 안에 끝날까?'를" << endl;
    cout << "판단하는 기준이 됩니다." << endl;

    return 0;
}
#endif

// =====================================================
// 예제 3: 값 전달 vs 참조 전달 -- 30초 복습
// =====================================================
#ifdef RUN_WEEK01_EXAMPLE03

// 값에 의한 전달: x는 원본의 "복사본"
void addOneByValue(int x) {
    x = x + 1;
    cout << "  [함수 내부] x = " << x << endl;
}

// 참조에 의한 전달: x는 원본의 "별명"
void addOneByRef(int& x) {
    x = x + 1;
    cout << "  [함수 내부] x = " << x << endl;
}

int main() {
    cout << "===== [예제 3] 값 전달 vs 참조 전달 =====" << endl;
    cout << endl;

    // 값에 의한 전달 -- 원본은 그대로
    int a = 10;
    cout << "[값 전달] 호출 전: a = " << a << endl;
    addOneByValue(a);
    cout << "[값 전달] 호출 후: a = " << a << "  ← 변화 없음!" << endl;

    cout << endl;

    // 참조에 의한 전달 -- 원본이 바뀜
    int b = 10;
    cout << "[참조 전달] 호출 전: b = " << b << endl;
    addOneByRef(b);
    cout << "[참조 전달] 호출 후: b = " << b << "  ← 변화 있음!" << endl;

    cout << endl;
    cout << "값 전달은 복사본을 바꾸고, 참조 전달은 원본을 바꿉니다." << endl;

    return 0;
}
#endif

// =====================================================
// 예제 4 (선택): 최댓값 찾기 -- O(n) 알고리즘의 첫 예제
// =====================================================
#ifdef RUN_WEEK01_EXAMPLE04
int main() {
    cout << "===== [예제 4] 최댓값 찾기 -- O(n) 알고리즘 =====" << endl;
    cout << endl;

    vector<int> arr = { 3, 7, 2, 9, 1, 5, 8, 4, 6 };
    int n = (int)arr.size();

    cout << "배열: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << endl;

    // 첫 번째 원소를 "현재까지의 최댓값"으로 설정
    int maxVal = arr[0];
    cout << "초기 최댓값: " << maxVal << endl;

    // 두 번째 원소부터 끝까지 한 번씩 비교합니다
    for (int i = 1; i < n; i++) {
        cout << "  arr[" << i << "] = " << arr[i] << " 확인 → ";

        if (arr[i] > maxVal) {
            maxVal = arr[i];
            cout << "최댓값 갱신! → " << maxVal << endl;
        }
        else {
            cout << "패스 (현재 최댓값 " << maxVal << " 유지)" << endl;
        }
    }

    cout << endl;
    cout << "최댓값: " << maxVal << endl;
    cout << endl;
    cout << "모든 원소를 딱 한 번씩 확인했으므로 → O(n)" << endl;
    cout << "정렬되지 않은 배열에서 최댓값을 O(n)보다 빠르게 찾는 건 불가능합니다." << endl;

    return 0;
}
#endif
