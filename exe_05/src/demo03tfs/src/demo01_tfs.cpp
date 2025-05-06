#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"
/*
    订阅方实现： 1.计算son1和son2的相对关系， 2.计算son1的某个坐标点在son2中的坐标
    1 包含头文件
    2 初始化节点，Nodehandle
    3 创建订阅对象
      listener
      buffer
    4 编写解析逻辑
    5 spinOnce()

*/
int main(int argc, char* argv[])
{
    // 2 初始化节点，Nodehandle
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;
    // 3 创建订阅对象
    //   buffer
    tf2_ros::Buffer buffer;
    //   listener
    tf2_ros::TransformListener listener(buffer);
    // 4 编写解析逻辑

    //创建坐标点
    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.frame_id = "son1";
    psAtSon1.header.stamp = ros::Time::now();

    psAtSon1.point.x = 5.0;
    psAtSon1.point.y = 1.0;
    psAtSon1.point.z = 1.0;
    
    ros::Rate rate(10);
    while(ros::ok())
    {
        try
        {
           //计算son1和son2的相对关系
           //target frame, source frame, ros::Time(0) -> search for the latest info from 2 frames, 
           //then calculate the relative pose 
           geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("son2","son1",ros::Time(0)); 
           tf2::Quaternion qtn;
           qtn.setX(son1Toson2.transform.rotation.x);
           qtn.setY(son1Toson2.transform.rotation.y);
           qtn.setZ(son1Toson2.transform.rotation.z);
           qtn.setW(son1Toson2.transform.rotation.w);

           double roll, pitch, yaw;
           tf2::Matrix3x3(qtn).getRPY(roll,pitch,yaw);

           ROS_INFO("son1 relative to son2: father:%s, son:%s translation(%.2f,%.2f,%.2f) \n rotation(%.2f,%.2f,%.2f)",
                    son1Toson2.header.frame_id.c_str(),
                    son1Toson2.child_frame_id.c_str(),
                    son1Toson2.transform.translation.x,
                    son1Toson2.transform.translation.y,
                    son1Toson2.transform.translation.z,
                    roll, pitch, yaw

                );
           //计算son1中的点在son2中的坐标值
           geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1,"son2");
           ROS_INFO("point in son2 system is (%.2f,%.2f,%.2f)",
                    psAtSon2.point.x,
                    psAtSon2.point.y,
                    psAtSon2.point.z
        
                    );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("error message: %s",e.what());
        }
        

        rate.sleep();
        ros::spinOnce();
        // 5 spinOnce()
    }

    return 0;
}