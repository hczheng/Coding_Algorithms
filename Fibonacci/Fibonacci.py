# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        a=[0,1,1]
        if(n<3):
            return a[n]
        for i in range(3,n+1):
            a.append(a[i-2]+a[i-1])
        return a[n]
		
print Solution().Fibonacci(10)


