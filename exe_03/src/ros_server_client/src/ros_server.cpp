#include "ros/ros.h"
#include "ros_server_client/Addints.h"


/*
服务端实现：解析客户端提交的数据并运算再产生响应
    1 包含头文件

*/

//  回调函数, 需要传入一个请求和一个响应对象

bool doNums(ros_server_client::Addints::Request &request,
            ros_server_client::Addints::Response &response){
    // 1 处理请求数据
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("request: num1 = %d, num2 = %d", num1, num2);

    // 2 产生响应数据
    int sum = num1 +num2;
    response.sum = sum;
    ROS_INFO("response: sum = %d", sum);


    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    
    // 2 初始化ros节点
    ros::init(argc, argv, "ros_server"); //节点名称需要保证唯一
    // 3 创建节点句柄
    ros::NodeHandle nh;
    // 4 创建服务对象
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    ROS_INFO("Server is running");
    // 5 处理请求并产生响应

    // 6 spin()
    ros::spin();
    return 0;
}