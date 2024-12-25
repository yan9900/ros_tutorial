#include "ros/ros.h"
/*
    需要实现参数的新增和修改
    需求：首先设置机器人的共享参数，类型，半径(0.15)
         再修改半径(0.2)
    实现：
        1 ros::Nodehandle
          setParam("key", value)
        2 ros::param
          set("key", value)
    修改，只需要继续调用nh.setParam()或ros::param::set()即可,确保key已经存在
        

*/
int main(int argc, char* argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "set_param");
    // 创建节点句柄
    ros::NodeHandle nh;
    // 参数增 --------------------------------
    //method 1
    nh.setParam("type", "Turtlebot1");
    nh.setParam("radius", 0.15);
    //method 2
    ros::param::set("type_param", "Turtlebot2");
    ros::param::set("radius_param", 0.15);
    // 参数改 --------------------------------
    //method 1
    nh.setParam("radius", 0.2);
    //method 2
    ros::param::set("radius_param", 0.2);
    return 0;
}