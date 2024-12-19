#include "ros/ros.h"
#include "ros_communication/Person.h"
/*
    订阅方：订阅消息
        1.包含头文件
            #include "ros_communication/Person.h"
        
*/
void doPerson(const ros_communication::Person::ConstPtr& msg)
{
    ROS_INFO("订阅人的消息：name=%s, age=%d, height=%.2f", msg->name.c_str(), msg->age, msg->height);
}
int main(int argc, char *argv[])
{
   setlocale(LC_ALL, "");
   ROS_INFO("订阅人的消息"); 
//    2.初始化ROS节点
    ros::init(argc, argv, "student");
//    3.创建节点句柄
    ros::NodeHandle nh;
//    4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("personal_data", 10, doPerson );
//    5.处理订阅的数据

//    6.调用spin()函数
    ros::spin();
    return 0;
}