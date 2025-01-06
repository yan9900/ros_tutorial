#include "ros/ros.h"
/*
    需求：1 获取当前时刻 + 设置指定时刻
         2 程序执行中停顿5s
         实现：
            1 创建持续时间对象
            2 休眠
         3 已知 开始运行的时间和运行时间，求结束的时刻
         实现：
            1 获取执行时刻
            2 模拟运行时间
            3 计算结束
         注意：时刻之间只可以相减，不可以相加
         4 每隔1s，在控制台输出一段文本
         实现：
            1 ros::Rate()
            2 Timer

*/
void cb(const ros::TimerEvent& event){

    ROS_INFO("----------");
    ROS_INFO("the function was called at %.2f", event.current_real.toSec());
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "ros_apis_time");
    ros::NodeHandle nh; //必须使用句柄，否则会造成时间api调用失败

    //1获取当前时间
    //当前时刻指now被调用的那一刻
    //参考系：1970年1月1日 00:00:00
    ros::Time right_now = ros::Time::now();
    ROS_INFO("current time is:%.2f",right_now.toSec());
    ROS_INFO("current time is:%d",right_now.sec);

    //2设定指定时刻
    ros::Time t1(20, 3123);
    ros::Time t2(100.35);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t1 = %.2f",t2.toSec());

    //---------------------------------------------
    ROS_INFO("------------duration--------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("pause start:%.2f",start.toSec());
    ros::Duration du(5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("pause end:%.2f",end.toSec());
    double diff = end.toSec()-start.toSec();
    ROS_INFO("pause time = %.2f",diff);

    //---------------------------------------------
    ROS_INFO("------------time calculation-----------");
    ros::Time stop = start + du;
    ros::Duration du1 = start - end;

    //---------------------------------------------
    ROS_INFO("------------publish frequence----------");
    // 4 parameters: 时间间隔，回调函数，是否一次（bool），是否自动启动（bool）
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();
    ros::spin();

    return 0;


}