# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        f = 0
        g = 1
        for i in range(n):
            f,g = g,f+g
        return f
		
print Solution().Fibonacci(10)