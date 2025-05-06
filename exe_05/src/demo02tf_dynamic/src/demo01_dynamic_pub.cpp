#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
/*
    发布方：需要订阅乌龟的位姿信息，转换成相对于窗体的坐标关系，并发布
    准备：
        乌龟的，
        话题：/turtle1/pose
        消息：/turtlesim/Pose
             float32 x
             float32 y
             float32 theta
             float32 linear_velocity
             float32 angular_velocity
    流程：
        1 包含头文件
        2 初始化 Nodehandle
        3 创建订阅对象
        4 回调函数处理订阅消息，将位姿信息转化成坐标相对关系并发布
        5 spin()
    
*/

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    // 4 回调函数处理订阅消息，将位姿信息转化成坐标相对关系并发布
    // a 创建发布对象
    //   发布对象属于tf2_ros
    static tf2_ros::TransformBroadcaster pub; //避免每次调用回调函数都创建新的发布对象

    // b 组织发布数据
    //   发布信息属于 geometry_msgs
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.child_frame_id = "turtle1";
    ts.header.stamp = ros::Time::now();

    //translation //input pose is a pointer
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    //rotation
    //convertion euler angle to quaternion based on tf2/LinearMath/quaternion
    //a create a quaternion instance
    tf2::Quaternion qtn;
    auto yaw = pose->theta; //yaw, turtle runs in 2d no pitch and row
    qtn.setRPY(0,0,yaw);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // c 发布
    pub.sendTransform(ts);
}
int main(int argc, char * argv[])
{
    // 2 初始化 Nodehandle
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;

    // 3 创建订阅对象 订阅/turtle1/pose
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100, doPose); //topic, list, callback function
    
    // 5 spin()
    ros::spin();
    return 0;

}