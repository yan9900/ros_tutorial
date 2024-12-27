#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char* argv[])
{
    //初始化ROS节点
    /*
        作用：初始化ROS节点
        参数：共有4个
            argc：封装实参个数（n+1）
            argv：封装参数的数组
                rosrun ros_pkg ros_node arg1 arg2 arg3
                argc 和 argv 会分别接收 ros_node arg1 arg2 arg3
            name：节点名称，需要保证唯一性
            options：节点启动选项
            
            返回值 void
        使用：
            1. argc与argv的使用
                如果按照ros的特定格式传入实参，那么ros可以加以使用
                比如可以用来设置全局参数，给节点重命名
            2. options的使用
                节点名称需要保证统一，会导致一个问题：同一个节点不能启动多次
                结果：ROS中当有重名的节点启动时，之前的节点会被关闭
                需求：特定场景需要一个节点多次启动且能正常运行
                解决：设置启动项 ros::init_options::AnonymousName

    */
    ros::init(argc, argv, "ros_apis_pub",ros::init_options::AnonymousName);
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("demo_topic",10);
    ros::Rate rate = 1;    // 10 Hz
    //发布消息
    //发布逻辑
    while(ros::ok()){
        //创建信息
        std_msgs::String msg;
        msg.data = "demostration of apis";
        //发布信息
        pub.publish(msg);
        ROS_INFO("Published message:%s",msg.data.c_str());
        //休眠
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}