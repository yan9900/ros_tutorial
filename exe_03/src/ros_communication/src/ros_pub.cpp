#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "talker");
    
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("Greeting",10);

    std_msgs::String msg;
    ros::Rate pub_rate(0.5); //10 Hz
    ros::Duration(3).sleep(); //为了防止先运行listener，talker和ros master的连接还未建好导致发布信息丢失，添加缓冲
    int count = 0;
    while (ros::ok())
    {
        count++;
        std::stringstream ss;
        ss<<"Hello ---->"<< count;
        msg.data = ss.str();
        pub.publish(msg);
        
        ROS_INFO("published messege is %s",msg.data.c_str());
        pub_rate.sleep();
        
    }


    
    /* code */

    return 0;
}
