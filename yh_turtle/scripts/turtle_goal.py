#!/usr/bin/python3
#! -*- coding:utf-8 -*-

from socket import MsgFlag
import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class TurtleGoal:
    def __init__(self):
        self.sub = rospy.Subscriber("turtle1/pose", Pose, self.update_pose)
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size = 34)
        self.pose = Pose()
        self.goal_pose = Pose()
        self.loop_rate = rospy.Rate(10)

    def update_pose(self, msg):
        self.pose = msg
        self.pose.x = round(self.pose.x, 4)
        self.pose.y = round(self.pose.y, 4)

    def eucldean_distance(self):
        diff_x = self.goal_pose.x - self.pose.x
        diff_y = self.goal_pose.y - self.pose.y
        return math.sqrt((diff_x * diff_x) + (diff_y * diff_y))

    def linear_vel(self,constant=1.5):
        return constant * self.eucldean_distance()
    
    def steering_angle(self):
        return math.atan2((self.goal_pose.y - self.pose.y), (self.goal_pose.x - self.pose.x))

    def angular_vel(self, constant=6):
        return constant * (self.steering_angle() - self.pose.theta)
        # self.pose --------> self.goal_pose ## 우리가 원하는 거리를 얻는 법
        # self.goal_x = float(input("x : "))
        # self.goal_y = float(input("y : "))
        # self.goal_z= float(input("z : "))

    def run(self):
        self.goal_pose.x = float(input("x 좌표 : "))
        self.goal_pose.y = float(input("y 좌표 : "))

        tolerance = float(input("오차 : "))

        msg = Twist()

        while self.eucldean_distance() >= tolerance:
            msg.linear.x = self.linear_vel()
            msg.angular.z = self.angular_vel()
            
            self.pub.publish(msg)
            self.loop_rate.sleep()

        msg.linear.x = 0
        msg.angular.z = 0
        self.pub.publish(msg)
        rospy.loginfo("Done!")

if __name__ == "__main__":
    rospy.init_node("turtle_goal")
    turtle_goal = TurtleGoal()
    turtle_goal.run()