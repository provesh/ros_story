#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from yh_star.msg import YhStarMsg

def msgCallback(msg):
    n = msg.data
    
    for i in range(1, n//2+1):
        for j in range(i):
            print("*", end='')
        print()
    for i in range(n//2+1, n+1):
        for j in range(n-i+1):
            print("*", end='')
        print()

def star_printer():
    rospy.init_node("yh_star_sub")
    rospy.Subscriber("yh-star_topic", YhStarMsg, msgCallback)
    rospy.spin()

if __name__ == "__main__":
    star_printer