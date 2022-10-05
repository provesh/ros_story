#!/usr/bin/python3
#! -*- coding:utf-8 -*-

from operator import truediv
import rospy
from yh_check.msg import YhCheck

class MyCheck:
    def __init__(self):
        self.sub_distance = rospy.Subscriber("check_distance", YhCheck, self.distanceCallback)
        self.sub_camera = rospy.Subscriber("check_camera", YhCheck, self.cameraCallback)
        self.distance = True
        self.camera = True

    def distanceCallback(self, msg):
        self.distance = msg.data
        if self.distance and self.camera:
            rospy.loginfo("ok")

    def cameraCallback(self, msg):
        self.camera = msg.data
        if self.distance and self.camera:
            rospy.loginfo("ok")

if __name__ == "__main__":
    rospy.init_node("yh_check_sub")
    my_chek = MyCheck()
    rospy.spin()

# class Calculator:
#     def __init__(self):
#         self.result = 0
    
#     def add(self, num):
#         self.result += num
#         return self.result

#     def sub(self, num):
#         self.result -= num
#         return self.result

#     def mul(self, num):
#         self.result *= num
#         return self.result

#     def div(self, num):
#         self.result /= num
#         return self.result

#     def div(self, num):
#         return self.result / num

# cal = Calculator() #Calculator는 class, cal은 instance
# print(cal.add(10))
# print(cal.sub(4))
# print(cal.mul(2))
# print(cal.div(3)) => 4
# print(cal.result) => 12 #나누기에서 값을 반환하지 않았기떄문에 여전히 12이다.