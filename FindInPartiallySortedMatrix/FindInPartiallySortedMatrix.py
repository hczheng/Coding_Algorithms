# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        rows = len(array)
        columns = len(array[0])
        x = rows - 1
        y = 0 
        while x >=0 and y <=columns-1:
            if array[x][y]>target:
                x -= 1
            elif array[x][y]<target:
                y += 1
            else:
                return True
            
        return False   
 
print Solution().Find(5,[[5,2,1]])