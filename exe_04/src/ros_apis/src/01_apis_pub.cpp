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
    /*
        作用：创建一个发布者对象

        模板：被发布的消息的类型

        参数：
            1. topic：发布的主题名称
            2. queue_size：消息队列的大小
            3. latch：是否开启消息保留
                作用：保留最新的消息，新的订阅者订阅时，会立即收到消息
                适用场景：消息的重要性高，且不希望丢失
                注意：消息保留会占用内存，不适用于大量消息的场景
                使用：latch设置为true的作用？
                以静态地图发布为例：
                方案1：可以使用固定频率发送地图数据，的那时效率低
                方案2：可以使用latch，并且只发布一次地图数据，每当新的订阅者订阅时，会立即收到地图数据

        
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("demo_topic",10,true);
    ros::Rate rate = 1;    // 10 Hz
    int count = 0;
    //发布消息
    //发布逻辑
    while(ros::ok()){
        // //创建信息
        std_msgs::String msg;
        // msg.data = "demostration of apis";
        count++;
        std::stringstream ss;
        ss<<"hello --->"<< count;
        msg.data = ss.str();
        //发布信息
        if(count <= 10){

        pub.publish(msg);
        ROS_INFO("Published message:%s",msg.data.c_str());

        }
        //休眠
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}