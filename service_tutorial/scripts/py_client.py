#!/usr/bin/python
#! -*- coding:utf-8 -*-
 
import rospy
from service_tutorial.srv import AddTwoints # 패키지이름(service_tutorial.srv)에서 AddTwoint를 쓰겠다.
import sys

def add_two_ints_client(a,b):
    rospy.wait_for_service("add_two_ints")
    try:
        my_client = rospy.ServiceProxy("add_two_ints", AddTwoints) # 서비스 이름(add_two_ints), 서비스 타입(AddTwoints)을 줘야함
        res = my_client(a,b) # C에서는 Call을 써줘야 했지만 파이썬은 알아서 a,b값을 서버에 넘겨준다.
        return res.result # res에서 더한 후 return해준다.
    except rospy.ServiceException as e:
        rospy.logerr("Service call failed: %s", e) # 서버가 열려있지 않다면 오류 메시지를 보내고 나간다.

if __name__ == "__main__": # 이름이 메인이라면
    rospy.init_node("py_client") # py_client라고 노드를 정의해준다.
    
    if len(sys.argv) != 3: # 값이 3개가 모이지 않았을 경우
        rospy.loginfo("rosrun service_tutorial py_client.py a b") #loginfo로 실행창을 보여준다(1)
        rospy.loginfo("a, b : int32 number") # loginfo로 실행창을 보여준다(2)
        sys.exit(1) # 이후 노드를 종료한다.
    
    a = int(sys.argv[1]) # a를 [1]배열에 넣는다
    b = int(sys.argv[2]) # b를 [2]배열에 넣는다
    result = add_two_ints_client(a,b) # return해준 값을 result라고 한다.
    rospy.loginfo("request : a = %d, b = %d", a, b) # loginfo로 a와 b의 값을 보여준다.
    rospy.loginfo("response : result = %d", result) # loginfo로 return된 result 값을 보여준다.