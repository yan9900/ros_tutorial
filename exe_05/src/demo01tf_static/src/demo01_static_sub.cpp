#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
/*
    订阅方：订阅发布的坐标系相对关系，传入一个坐标点，调用tf实现转换

    流程：
    1 包含头文件
    2 初始化 Nodehandle()
    3 创建订阅对象 ---> 订阅坐标系相对关系
    4 组织一个坐标点
    5 转化算法，需要调用TF内置实现
    6 最或输出
*/
int main(int argc, char * argv[])
{
    // 2 初始化 Nodehandle()
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    
    // 3 创建订阅对象 ---> 订阅坐标系相对关系
    // listener和buffer一般结合使用，buffer用来储存listener订阅到的数据
    // 3-1 创建一个buffer缓存
    tf2_ros::Buffer buffer;
    // 3-2 创建监听对象，将订阅数据存入buffer
    tf2_ros::TransformListener Listener(buffer);
    
    // 4 组织一个坐标点
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();

    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    // 添加休眠
    ros::Duration(2).sleep(); //必须先订阅到才能发布，所以需要休眠
    // 5 转化算法，需要调用TF内置实现
    ros::Rate rate(10);
    while(ros::ok)
    {
        //核心：将ps转化为相对base_link的坐标点
        geometry_msgs::PointStamped ps_out;
        //需要包含tf2_geometry_msgs的头文件
        try
        {
            ps_out = buffer.transform(ps,"base_link");
            /*
                参数1 被转换的坐标点
                参数2 目标坐标点
                返回值： 输出的坐标点
            */
            // 6 最或输出
            ROS_INFO("Coordinates after transformation:(%.2f,%.2f,%.2f), reference coordinates system: %s",
                        ps_out.point.x, 
                        ps_out.point.y, 
                        ps_out.point.z,
                        ps_out.header.frame_id.c_str()
                    );

        }
        catch(const std::exception& e)
        {
            ROS_INFO("error message:%s", e.what());
        }
        rate.sleep();
        ros::spinOnce();
        
    }

    return 0;
}