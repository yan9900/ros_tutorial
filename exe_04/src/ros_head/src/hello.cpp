#include "ros/ros.h"
#include "ros_head/hello.h"

namespace hello_ns {

    void MyHello::run(){
        ROS_INFO("run function being carried out");
    }
}
int main(int argc, char* argv[]){
    ros::init(argc, argv, "hello_head");
    hello_ns::MyHello myHello;
    myHello.run();
    return 0;
}