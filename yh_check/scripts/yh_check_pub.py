#!/usr/bin/python3
#! -*- coding:utf-8 -*-

import rospy
from yh_check.msg import YhCheck

class ConnectSub:
    def __init__(self):
        self.sub = rospy.Subscriber()
