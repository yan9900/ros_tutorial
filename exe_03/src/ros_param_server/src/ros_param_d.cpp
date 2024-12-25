#include "ros/ros.h"

/*
    实现参数删除
    ros::NodeHandle
        deleteParam()

    ros::param
        del()
*/
int main(int argc,char* argv[])
{
    //初始化ROS节点
    ros::init(argc, argv, "param_del");
    //创建节点句柄
    ros::NodeHandle nh;

    //参数删除 NodeHandle--------------------------------
    bool flag = nh.deleteParam("radius");
    if(flag){
        ROS_INFO("Parameter %s has been deleted", "radius");
    }else{
        ROS_INFO("delete failed");
    }

    //删除参数 ros::param--------------------------------
    bool flag2 = ros::param::del("radius_param");
    if (flag2)
    {
        ROS_INFO("Parameter %s has been deleted", "radius_param");
    }else{
        ROS_INFO("delete failed");
    }
    
    return 0;
}