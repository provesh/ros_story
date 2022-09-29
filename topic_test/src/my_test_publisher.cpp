#include "ros/ros.h" // 로스의 로스헤더파일을 가져온다
#include "std_msgs/Int64.h" // std_msgs에서 Int64의 헤더파일을 가져온다.

int main (int argc, char** argv)
{
    ros::init(argc, argv, "my_test_publisher"); // 로스 초기화(init). 
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int64>("my_topic", 100);

    ros::Rate loop_rate(4);

    std_msgs::Int64 msg;
    msg.data = 0;

    while (ros::ok())
    {
        pub.publish(msg);
        loop_rate,(sleep);
        msg.data ++;
        if (msg.data == 101 )
        {
            msg.data = 0;
        }
    }
    return 0;
}