#include "ros/ros.h"
#include "ros_communication/Person.h"
/*
    发布方：发布人的消息
         1.包含头文件
            #include "ros_communication/Person.h"


*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ROS_INFO("发布人的消息");
    // 2.初始化ROS节点
    ros::init(argc, argv, "teacher");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<ros_communication::Person>("personal_data",10);
    // 5.编写发布逻辑，发布消息
    //5.1 创建被发布的数据
    ros_communication::Person person;
    person.name = "Leo";
    person.age = 18;
    person.height = 1.75;
    //5.2 设置发布频率
    ros::Rate rate(1); //1Hz
    //5.3 循环发布数据
    while(ros::ok()){
        //修改被发布的数据
        person.age += 1;
        //核心：发布数据
        pub.publish(person);
        ROS_INFO("发布人的消息：name=%s, age=%d, height=%.2f", person.name.c_str(), person.age, person.height);
        rate.sleep(); //按照设置的发布频率休眠
        ros::spinOnce();    //处理回调函数

    }
    return 0;
}