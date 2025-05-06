#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
int main(int argc, char * argv[])
{
    //初始化，Nodehandle
    ros::init(argc, argv, "dyanamic_sub");
    ros::NodeHandle nh;

    //创建订阅对象 --> 订阅坐标系间相对关系
    //创建 buffer
    tf2_ros::Buffer buffer;
    //创建 监听对象 //不同于static broadcaster，只有一种listener
    tf2_ros::TransformListener listener(buffer);
    //组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    //reference coordinate system
    ps.header.frame_id = "turtle1";
    //time stamp 不同于 static
    ps.header.stamp = ros::Time(0.0);
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    //转换算法
    ros::Rate rate(10);
    while(ros::ok())
    {
        geometry_msgs::PointStamped ps_out;
        //将ps转化为相对于world的坐标点
        try
        {
            //transform依赖于tf2_geometry_msgs
            ps_out = buffer.transform(ps,"world");
            ROS_INFO("coordinates after transformation:(%.2f,%.2f,%.2f),reference cs is:%s",
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