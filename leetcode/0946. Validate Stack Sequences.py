class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        
          Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
          Output: false
          Explanation: 1 cannot be popped before 2.
        """
        # 아이디어: pushed 배열을 순서대로 스택에 넣고, 
        # 스택의 맨 마지막 값과 popped 배열의 j번째 값을 비교하며 연속적으로 pop하거나 
        # popped 배열의 모든 값을 처리할 수 있는지 확인한다.
        stack = []
        j = 0
        for x in pushed:
            stack.append(x)
            while stack and j < len(popped) and stack[-1] == popped[j]:
                stack.pop()
                j += 1
        return j == len(popped)