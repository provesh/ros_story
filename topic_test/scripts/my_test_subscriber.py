#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Int64

def msgCallback(msg):
    rospy.loginfo("msg : %d", msg.data)

def my_listener():
    rospy.init_node("my_test_subscriber")
    rospy.Subscriber("my_count", Int64, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    my_listener()