# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        odd = []
        even = []
        for i in array:
            if i % 2 == 0:
                even.append(i)
            else:
                odd.append(i)
        return odd+even
        return False   
 
print Solution().reOrderArray([2,14,5,2,1])