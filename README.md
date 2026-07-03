# Coding Test Archive C++

Baekjoon, Programmers, SWEA 문제 풀이를 C++ 중심으로 정리한 알고리즘 저장소입니다. 삼성 SW 역량 테스트와 코딩 테스트 대비를 위해 구현, 시뮬레이션, 자료구조 문제를 누적했습니다.

## 프로젝트 개요

플랫폼별 문제 폴더와 자동 생성된 문제 README를 유지하면서, C++ 풀이 코드를 함께 보관합니다. Python 중심 archive와 분리해 C++ 문법과 STL 기반 풀이를 집중적으로 관리합니다.

## 구성

| 플랫폼 | 내용 |
| --- | --- |
| `백준/` | Bronze/Silver/Gold 문제 풀이 |
| `프로그래머스/` | Level 1~2 중심 문제 풀이 |
| `SWEA/` | D2 및 모의 SW 역량 테스트 문제 |

## 기술 스택

- **Language**: C++17
- **Topics**: 구현, 문자열, 정렬, 시뮬레이션, BFS/DFS, 자료구조
- **Archive Format**: Platform / level / problem directory

## 프로젝트 구조

```text
.
├── 백준/
├── 프로그래머스/
├── SWEA/
└── README.md
```

## 학습 포인트

### 1. C++ STL 기반 풀이 정리
`vector`, `queue`, `stack`, `map`, `set`, `priority_queue` 등 코딩 테스트에서 자주 사용하는 STL 패턴을 문제 풀이로 누적했습니다.

### 2. 시뮬레이션 문제 대비
SWEA 모의 SW 역량 테스트 유형처럼 조건이 많은 구현 문제를 C++로 정리해 풀이 속도와 디버깅 감각을 높였습니다.

### 3. 플랫폼별 풀이 이력 관리
문제별 README에는 플랫폼에서 제공하는 문제 정보가 함께 저장되어 있어 풀이 코드와 문제 조건을 함께 복습할 수 있습니다.

## 실행 방법

```bash
g++ -std=c++17 "백준/Silver/<문제폴더>/<풀이파일>.cc" -o solve
./solve
```

---
C++ 코딩 테스트 풀이를 플랫폼별로 정리한 저장소입니다.
