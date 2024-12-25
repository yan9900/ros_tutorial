#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*需求：向服务器发送请求生成一只新的乌龟
    话题：/spawn
    消息： turtlesim/Spawn


*/
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "turtle_server");

    ros::NodeHandle nh;

    ros::ServiceClient turtle_client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    // 组织数据并发送
    turtlesim::Spawn spawn;
    spawn.request.x = 2.0;
    spawn.request.y = 2.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";

    // 发送请求
    // ros::service::waitForService("/spawn");
    turtle_client.waitForExistence();
    bool flag = turtle_client.call(spawn);
    if(flag){
        ROS_INFO("spawn successfully, turtle name: %s", spawn.response.name.c_str());
    }else{
        ROS_ERROR("spawn failed");
    }

    return 0;
}