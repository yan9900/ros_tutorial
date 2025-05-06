#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
/*
    需求：发布两个坐标系的相对关系

    流程：
        1 包含头文件
        2 节点初始化
        3 创建发布对象
        4 组织被发布的消息
        5 发布数据
        6 spin();
*/
int main(int argc, char *argv[])
{
    // 2 节点初始化
    ros::init(argc, argv,"static_pub");
    ros::NodeHandle nh;
    
    // 3 创建发布对象
    tf2_ros::StaticTransformBroadcaster pub;
    
    // 4 组织被发布的消息
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link"; //相对坐标系中被参考的那个
    tfs.child_frame_id = "laser";
    //translation
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;
    //rotation in quaternion(based on euler angle)
    //先创建quaternion对象
    tf2::Quaternion qtn;
    //通过对这个对象设置欧拉角，可以将欧拉角转化为四元数
    qtn.setRPY(0, 0, 0); //欧拉角的单位为rad

    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();


    // 5 发布数据
    pub.sendTransform(tfs);
    // 6 spin();
    ros::spin();
    return 0;
}