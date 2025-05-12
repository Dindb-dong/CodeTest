class Solution(object):
    def longestMountain(self, arr):
        n = len(arr)
        if n < 3: return 0 # 조기종료 조건 
        # 변수 초기화 
        left = 0
        ans = 0
        i = 1

        while i < n - 1:
            # 증가 시작점 감지
            if arr[i - 1] >= arr[i] and arr[i] < arr[i + 1]:
                left = i

            # 피크 발견
            if arr[i - 1] < arr[i] > arr[i + 1]:
                temp_l = left
                right = i # 산 끝 찾기 시작
                while right < n - 1 and arr[right] > arr[right + 1]:
                    right += 1
                temp_r = right # 끝 찾으면 갱신 
                ans = max(ans, temp_r - temp_l + 1) # ans 갱신 
                i = right # 런타임 줄이기 위해 i를 바로 right 위치로 점프 
            else: # 증가 시작점도 아니고 피크도 아닌 일반적인 경우 
                i += 1
        return ans