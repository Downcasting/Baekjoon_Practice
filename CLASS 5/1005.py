
# 1005번 - ACM Craft

# ---------- import 선언부 ----------

import sys

# ---------- 전역변수 선언부 ----------

input = sys.stdin.readline

# ---------- 클래스 선언부 ----------
    


# ---------- 함수 선언부 ----------

def getTime(buildnum):

    global building
    global building_time
    global building_check

    totalTime = 0

    if building_check[buildnum] == True:
        return 0
    building_check[buildnum] = True

    for i in building_time[building_num]:
        totalTime += getTime(i)

    return totalTime
# 여기서부터 메인 코드가 시작됨

testcase = int(input())

global building
global building_time
global building_check

for _ in range(testcase):
    building_num, laws = map(int, input().split())
    building = [[] for _ in range(building_num+1)]
    building_time = list(map(int, input().split()))
    building_check = [False] * (building_num+1)
    for _ in range(laws):
        a,b = map(int, input().split())
        building[b].append(a)
    building_dest = int(input())
    getTime(building_dest)
