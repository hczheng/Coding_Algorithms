# -*- coding:utf-8 -*-

# class Solution:
    # # s 源字符串
    # def replaceSpace(self, s):
        # # write code here    
        # return s.replace(' ','%20')
		
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        r = []
        for c in s:
            if c == ' ':
                r.append('%20')
            else:
                r.append(c)
        return ''.join(r)

print Solution().replaceSpace('str cpy')

