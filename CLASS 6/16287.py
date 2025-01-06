
# 16287번 - Parcel

# ---------- import 선언부 ----------

import sys

# ---------- 전역변수 선언부 ----------


# ---------- 클래스 선언부 ----------

    
# ---------- 함수 선언부 ----------


# 여기서부터 메인 코드가 시작됨

weight = int(input())
element_count = int(input())
element = [int(input()) for _ in range(element_count)]

# 첫 번째 줄 입력 처리
weight, element_count = map(int, input().split())

# 두 번째 줄 입력 처리
elements = list(map(int, input().split()))

# 출력 확인
print("weight:", weight)
print("element_count:", element_count)
print("elements:", elements)