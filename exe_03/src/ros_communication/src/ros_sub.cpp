#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void pMsgs(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("received messeges is %s", msg->data.c_str());
}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"listner");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("Greeting",10,pMsgs); //topic, 


    ros::spin();
    /* code */
    return 0;
}
