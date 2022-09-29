#include "ros/ros.h"
#include "service_tutorial/AddTwoints.h" // 서비스 헤더파일
                                        // 빌드시 자동생성

// 서비스 요청이 있을 경우 실행되는 콜백함수
// 서비스 요청은 req, 서비스 응답은 res로 설정. 
bool add(service_tutorial::AddTwoints::Request& req, service_tutorial::AddTwoints::Response& res)
{
    res.result = req.a + req.b;
    ROS_INFO("request : a=%d,b=%d", req.a, req.b);
    ROS_INFO("response : result=%d", res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_server");
    ros::NodeHandle nh;

    // 서비스 서버(my_server)를 선언
    // 서비스 이름은 (add_two_ints)이고, 요청이 왔을 때 콜백함수(add)를 실행한다.
    // (service_tutorial)패키지의 (AddTwoints)서비스 파일을 이용한다. // 패키지와 서비스파일은 위쪽 bool함수 쪽에 정의했다.
    ros::ServiceServer my_server = nh.advertiseService("add_two_ints", add);

    ROS_INFO("---Service Server Ready---");

    ros::spin();

    return 0;
}
