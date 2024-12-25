#include "ros/ros.h"

int main(int argc, char* argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "change_bgColor");
    // 创建节点句柄
    ros::NodeHandle nh("turtlesim");
    // 修改参数
    nh.setParam("background_r", 255);
    nh.setParam("background_b", 100);
    nh.setParam("background_g", 100);
    //ros::param::set
    //ros::param::set("/turtlesim/background_r", 255);

    return 0;
}