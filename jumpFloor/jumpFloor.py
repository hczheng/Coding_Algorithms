# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        f = 1
        g = 1
        for i in range(number):
            f,g = g,f+g
        return f
		
print Solution().jumpFloor(10)


