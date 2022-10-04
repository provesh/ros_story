#include "ros/ros.h"
#include "yh_difference/Yh_Differnce.h"

bool abcd(yh_differnce::yh_method::Request& req, yh_differnce::yh_method::Response& res)
{
    res.result = req.a - req.b;
    
    if (req.b > req.a)
    {
        res.result = req.b - req.a;
    }
    else
    {
        res.result = req.a - req.b;
    }

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_difference_service");
    ros::NodeHandle nh;

    // 서비스 서버()를 선언
    // 서비스 이름은 ()이고, 요청이 왔을 때 콜백함수()를 실행한다.
    // ()패키지의 ()서비스 파일을 이용한다. // 패키지와 서비스파일은 위쪽 bool함수 쪽에 정의했다.
    ros::ServiceServer yh_difference_server = nh.advertiseService("yh_difference_service", abcd);

    ROS_INFO("---Service Server Ready---");

    ros::spin();

    return 0;
}