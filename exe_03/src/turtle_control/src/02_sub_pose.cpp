#include "ros/ros.h"
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr &pose){
    ROS_INFO("turtle pose info: loaction(%.2f, %.2f), orientation(%.2f), lin velo(%.2f), angular velo(%.2f)"
    ,pose->x, pose->y, pose->theta, pose->linear_velocity,pose->angular_velocity);
}
int main(int argc, char* argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "sub_pose");
    // 创建节点句柄
    ros::NodeHandle nh;
    // 创建订阅者对象
    ros::Subscriber turtle_sub = nh.subscribe("/turtle1/pose", 100, doPose);
    
    ros::spin();
    return 0;
}