#include "ros/ros.h"
#include "std_msgs/Int64.h"

// 메시지를 받을 콜백함수 추가
void msgCallback(const std_msgs::Int64::ConstPtr& msg)
{
    ROS_INFO("msg : %d",msg->data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_test_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("my_topic", 100, msgCallback);

    ros::spin();

    return 0;
}