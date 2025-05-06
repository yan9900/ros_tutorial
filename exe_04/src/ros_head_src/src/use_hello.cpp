#include "ros/ros.h"
#include "ros_head_src/hello.h"

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"hello_head_src");

    hello_ns::MyHello myHello;
    myHello.run();
    return 0;
}
