# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        # write code here
		return 2 ** (number - 1)
		
print Solution().jumpFloorII(10)


