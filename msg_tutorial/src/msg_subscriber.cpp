#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" // Mymsg 헤더파일. 빌드 시 자동생성

// void msgCallback(const std_msgs::Int64::ConstPtr& msg)
void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)
{
    ROS_INFO("receive msg : %d", msg->stamp.sec); // msg의 stamp의 sec출력
    ROS_INFO("receive msg : %d", msg->stamp.nsec); // msg의 stamp의 nsec출력
    ROS_INFO("receive msg : %d", msg->data); // msg의 data출력
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "msg_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chicken", 20, msgCallback);

    ros::spin();

    return 0;
}