#include "ros/ros.h"
#include "param_tutorial/Calculate.h"

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operater = PLUS;

bool calculation(param_tutorial::Calculate::Request& req, param_tutorial::Calculate::Response& res)
{
    switch (my_operater)
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            res.result = req.a / req.b;
            break;
        default:
            res.result = req.a + req.b;
            break;
    }
    ROS_INFO("a = %d, b = %d, result = %d", req.a, req.b, res.result);
    return true;
}

int main (int argc, char** argv)
{
    ros::init(argc, argv, "calculate_server");
    ros::NodeHandle nh;

    nh.setParam("calculation_method", PLUS); // 파라미터 초기 설정. 이미 값이 설정되어있다면 값을 바꾸어준다.

    ros::ServiceServer calculation_server = nh.advertiseService("calculate", calculation);

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        nh.getParam("calculation_method", my_operater); // 설정된 파라미터의 값을 가져온다.
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}