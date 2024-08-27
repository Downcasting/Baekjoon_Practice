
# 2533번 - 사회망 서비스

# ---------- import 선언부 ----------

import sys
input = sys.stdin.read

# ---------- 전역변수 선언부 ----------

count = 0
sys.setrecursionlimit(10**6)

# ---------- 클래스 선언부 ----------
class Vertice:
    def __init__(self):
        self.neighbors = []
        self.visit = False
        self.early = False
    
# ---------- 함수 선언부 ----------

def isNodeEarly(target: Vertice):
    global count
    isEarly = False

    if target.visit == True:
        return True
    
    target.visit = True

    for i in target.neighbors:
        if isNodeEarly(vertices[i]) == False:
            if not isEarly:
                count += 1
            isEarly = True
    
    return isEarly

# 여기서부터 메인 코드가 시작됨
data = input().splitlines()
num = int(data[0])

vertices = [Vertice() for _ in range(num + 1)]

for line in data[1:]:
    a, b = map(int, line.split())
    vertices[a].neighbors.append(b)
    vertices[b].neighbors.append(a)

isNodeEarly(vertices[1])
print(count)