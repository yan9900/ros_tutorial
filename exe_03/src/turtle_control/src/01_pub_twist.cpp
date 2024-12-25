#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/*
    需求：发布速度消息
        topic: /turtle1/cmd_vel
        type: geometry_msgs/Twist
    1 包含头文件
    2 初始化ROS节点
    3 创建节点句柄
    4 创建发布者对象
    5 编写发布逻辑
    6 发布消息
*/

int main(int argc, char* argv [])
{
    ros::init(argc, argv, "pub_twist");

    ros::NodeHandle nh;

    ros::Publisher turtle_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate rate(10); //发布频率
    // 创建发布消息
    geometry_msgs::Twist twist;
    twist.linear.x = 0.5;
    twist.angular.z = 0.5;

    while(ros::ok()){
        turtle_pub.publish(twist);
        // 按照指定频率休眠
        rate.sleep();
        ros::spinOnce();    //处理回调函数
    }
    return 0;
}