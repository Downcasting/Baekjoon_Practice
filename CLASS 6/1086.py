# 1086번 - 박성원

# ---------- import 선언부 ----------


# ---------- 전역변수 선언부 ----------


# ---------- 클래스 선언부 ----------

    
# ---------- 함수 선언부 ----------

def get_remainder(length, digit, divisor, dp):
    if dp[length][digit] != -1:
        return dp[length][digit]
    if length == 0:
        return digit
    dp[length][digit] = get_remainder(length - 1, (digit * 10) % divisor, divisor, dp)
    return dp[length][digit]


# 여기서부터 메인 코드가 시작됨

N = int(input())
divisor = int(input())  # divisor를 입력받음
dp = [[-1] * 10 for _ in range(50)]  # DP 테이블 초기화 (길이 50, 숫자 0-9)

divisors = [0] * N
lengths = [0] * N

for i in range(N):
    arr = input().strip()
    dig = len(arr) - 1
    for j in range(len(arr)):
        divisors[i] += get_remainder(dig, int(arr[j]), divisor, dp)
        dig -= 1