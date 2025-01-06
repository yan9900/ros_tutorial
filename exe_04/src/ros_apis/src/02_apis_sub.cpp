#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("msg received: %s", msg->data.c_str());
}
int main(int argc, char* argv[])
{
    //初始化ROS节点
    ros::init(argc, argv, "ros_apis_sub");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("demo_topic", 10, doMsg);
    //循环等待回调函数
    ros::spin();
    return 0;
}