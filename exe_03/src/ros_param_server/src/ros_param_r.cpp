#include "ros/ros.h"
/*
演示参数查询
实现：
    ros::NodeHandle -------------------------------

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param-------------------------------------
*/
int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"");
    // 初始化ROS节点
    ros::init(argc, argv,"get_param");
    // 创建节点句柄
    ros::NodeHandle nh;

    //ros::NodeHandle--------------------------------
    //1.param
    double radius = nh.param("radius", 0.5);
    ROS_INFO("radius = %.2f", radius);
    
    //2.getParam
    double radius2 = 0.0;
    bool result = nh.getParam("radius",radius2);
    if(result){
        ROS_INFO("radius = %.2f", radius2);
    }else{
        ROS_INFO("parameter radius does not exist");
    }

    //3.getParamCached better efficiency
    double radius3 = 0.0;
    bool result2 = nh.getParamCached("radius", radius3);
    if(result2){
        ROS_INFO("radius = %.2f", radius3);
    }else{
        ROS_INFO("parameter radius does not exist");
    }

    //4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names){
        ROS_INFO("go through all the keys: %s", name.c_str());
    }

    //5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radius2");
    ROS_INFO("flag1 = %d, flag2 = %d", flag1, flag2);
   

    //6.searchParam
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("search result: %s", key.c_str());

    return 0;
}