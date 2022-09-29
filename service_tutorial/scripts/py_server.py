#!/usr/bin/python
#! -*- coding:utf-8 -*-
 
import rospy
from service_tutorial.srv import AddTwoints, AddTwointsResponse

def add(req): #콜백함수와 같은 역할
    result = req.a + req.b
    rospy.loginfo("a = %d , b = %d", req.a, req.b)
    rospy.loginfo("respones : result = %d", result)
    return AddTwointsResponse(result)

def add_two_ints_server():
    rospy.init_node("py_server")

    my_server = rospy.Service("add_two_ints", AddTwoints, add)

    rospy.loginfo("---Service Server already---")

    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
