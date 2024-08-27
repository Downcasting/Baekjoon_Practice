
# 1005번 - ACM Craft

# ---------- import 선언부 ----------

import sys

# ---------- 전역변수 선언부 ----------

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

# ---------- 클래스 선언부 ----------
    


# ---------- 함수 선언부 ----------

def getTime(buildnum):

    global building_order
    global building_time
    global building_check
    global building_time_dp

    maxTime = 0

    if building_check[buildnum] == True:
        return building_time_dp[buildnum]
    building_check[buildnum] = True

    for i in building_order[buildnum]:
        maxTime = max(getTime(i), maxTime)

    building_time_dp[buildnum] = maxTime + building_time[buildnum-1]
    return building_time_dp[buildnum]
# 여기서부터 메인 코드가 시작됨

testcase = int(input())

global building_order
global building_time
global building_check
global building_time_dp

for _ in range(testcase):
    building_num, laws = map(int, input().split())
    building_order = [[] for _ in range(building_num+1)]
    building_time = list(map(int, input().split()))
    building_check = [False] * (building_num+1)
    building_time_dp = [0] * (building_num+1)
    for _ in range(laws):
        a,b = map(int, input().split())
        building_order[b].append(a)
    building_dest = int(input())
    time = getTime(building_dest)
    print(time)
