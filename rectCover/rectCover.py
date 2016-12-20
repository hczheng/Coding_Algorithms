# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        if number<1:
            return 0
        f = 1
        g = 1
        for i in range(number):
            f,g = g,f+g
        return f
		
print Solution().rectCover(10)


