#include "ros/ros.h"
#include "std.msgs/Int64.h"

int main (int argc, char** argv):
{
    ros::init(argc, argv, "my_test_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.adventise<std_msgs::Int64>("my_topic", 100);

    ros::Rate loop_rate(4);

    std_msgs::Int64;
    msg.data = 0;

    while (ros::ok())
    {
        pub.publish(msg);
        loop_rate,(sleep);
        if (msg.data == 100)
        {
            msg.data = 0;
        }
    }
    return 0;
}