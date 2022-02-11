#ifndef ODOM_TF_HPP
#define ODOM_TF_HPP

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

class odomTF {
    
public:
    ~odomTF() = default;
    odomTF(ros::NodeHandle& nh);

    void transformCallback(const nav_msgs::Odometry& odom);

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub;
    tf::TransformBroadcaster odom_broadcaster;
};

#endif