#!/usr/bin/python3
#! -*- coding:utf-8 -*-

import rospy
import math
from geometry_msgs.msg import Twist

rospy.init_node("yh_turtle_circle")
pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=50)

msg = Twist()
msg.linear.x = 2.5
msg.angular.z = 1
loop_rate = rospy.Rate(1)

while not rospy.is_shutdown():
    pub.publish(msg)
    msg.linear.x += 0.000001
    msg.angular.z += 0.000001
    loop_rate.sleep()
