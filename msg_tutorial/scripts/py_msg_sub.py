#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
from msg_tutorial.msg import Mymsg

def msg_Callback(msg):
    rospy.loginfo("receive msg : %d", msg.stamp.secs)
    rospy.loginfo("receive msg : %d", msg.stamp.nsecs)
    rospy.loginfo("receive msg : %d", msg.data)

def msg_listener():
    rospy.init_node("py_msg_sub")
    rospy.Subscriber("chicken", Mymsg, msg_Callback)

    rospy.spin()

if __name__ == "__main__":
        msg_listener()