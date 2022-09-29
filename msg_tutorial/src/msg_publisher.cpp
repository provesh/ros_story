#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" // Mymsg 헤더파일. 빌드 시 자동생성

int main(int argc, char** argv)
{
    ros::init(argc,argv, "msg_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("chicken", 20);

    ros::Rate loop_rate(2);

    msg_tutorial::Mymsg msg;
    int cnt = 0;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); // 현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; // cnt 변수의 값을 msg의 data에 담는다.
        ROS_INFO("send msg : %d", msg.stamp.sec); // stamp.sec 출력.
        ROS_INFO("send msg : %d", msg.stamp.nsec); // stamp.nsec 출력.(nsec = 나노 세컨드)
        ROS_INFO("send msg : %d", msg.data); // data 출력.
        pub.publish(msg); // 메시지 전송
        cnt++; // 카운트 수 증가
        loop_rate.sleep(); // 주기에 맞게 시간을 돌려주는것
    }

    return 0;
}