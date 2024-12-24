#include "ros/ros.h"
#include "ros_server_client/Addints.h"
/*
    客户端需要提交两个整数
    1 包含头文件
    
    实现参数的动态提交
        1 格式：rosrun 包名 节点名 参数1 参数2
        2 节点在执行时，需要获取命令中的参数，并组织进request

    问题：
        如果先启动client，会请求异常
    需求：
        如果先启动client，不要直接抛出一场，而是等待server启动后再请求
    解决：
        在ROS中内置了相关函数，这些函数可以让客户端启动后挂起，等待server启动
*/


    

int main(int argc, char* argv[])
{
    //优化实现，获取命令中的参数
    setlocale(LC_ALL, "");
    if(argc != 3){ //检测参数数量是否为3个，第一个参数为节点名，第二个参数为num1，第三个参数为num2
        ROS_INFO("wrong number of parameters, please input two integers");
        return 1;
    }

    // 2 初始化ros节点
    ros::init(argc, argv, "ros_client");
    // 3 创建节点句柄
    ros::NodeHandle nh;
    // 4 创建一个客户端对象
    ros::ServiceClient client = nh.serviceClient<ros_server_client::Addints>("addInts");
    // 5 提交请求并处理响应
    // 创建Addints对象(即创建service对象)
    ros_server_client::Addints ai;
    // 5.1 组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    // 5.2 处理响应
    //调用判断服务器状态的函数
    //client.waitForExistence();
    ros::service::waitForService("addInts");

    bool flag = client.call(ai); //call函数返回值为bool类型，表示是否成功调用服务
    //sum会被封装到ai.response中
    if(flag){
        ROS_INFO("successfully responded! the sum is %d",ai.response.sum);
    }else{
        ROS_INFO("failed to respond....");
    }
    //6 spin() 由于客户端没有回调函数，不需要spin()
    return 0;
}