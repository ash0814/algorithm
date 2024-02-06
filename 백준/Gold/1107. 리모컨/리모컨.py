N = int(input())
button = set(i for i in range(10))
M = int(input())

# button에서 사용할 수 없는 remove button을 제거해준다. (set을 사용하면 - 연산자 사용 가능)
if M > 0:
    remove_button = set(map(int,input().split()))
    button -= remove_button

answer = abs(100 - N)

for i in range(1000001):
    tf = True
    for j in range(len(str(i))):
        # 1부터 100만까지 확인해가며 각 자리수를 반복문을 돌며 사용할 수 있는 버튼인지
        # 확인해준다. 사용못하는 버튼이면 tf = False로 바꿔준 뒤 break
        if int(str(i)[j]) not in button:
            tf = False
            break

    # tf가 True이면 answer값 갱신 ->
    # 현재 숫자 누르는 횟수 len(str(i)) + 그 숫자에서 N까지의 차이 abs(i - N)
    if tf:
        answer = min(answer, len(str(i)) + abs(i - N))
print(answer)