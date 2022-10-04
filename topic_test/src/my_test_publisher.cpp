#include "ros/ros.h" // 로스의 로스헤더파일을 가져온다
#include "std_msgs/Int64.h" // std_msgs에서 Int64의 헤더파일을 가져온다.

int main (int argc, char** argv)
{
    ros::init(argc, argv, "my_test_publisher"); // 로스 초기화(init).
    ros::NodeHandle nh; // 로스와 통신하기 위해 노드핸들을 만듦.

    // 퍼블리셔 선언(Publisher pub = nh.advertise)
    // 패키지(std_msgs)의 메시지파일(Int64)을 이용해 퍼블리셔(pub)를 만든다.
    // 토픽은 (my_topic)이며, 퍼블리셔 큐 사이즈는 (100)이다.
    ros::Publisher pub = nh.advertise<std_msgs::Int64>("my_topic", 100);

    // 루프주기를 4로 설정(0.25초)
    ros::Rate loop_rate(4);

    std_msgs::Int64 msg;
    msg.data = 0; //메세지의 데이터에 0을 넣는다.


    while (ros::ok())
    {
        pub.publish(msg); // pub이 msg 퍼블리싱
        loop_rate.sleep(); // 주기에 따라 sleep한다.
        msg.data ++; // 0인 데이터에 while문을 따라 1씩 증가시킨다.
        if (msg.data == 101 )
        {
            msg.data = 0; // if문을 써서 100을 넘기면 0으로 초기화한다.
        }
    }
    return 0;
}