#include "odom_tf.hpp"

odomTF::odomTF(ros::NodeHandle& nh) {
    ros::init(argc, argv, "odometry_tf_publisher");
    nh_ = nh;
    sub = nh_.subscribe("odom_data_euler", 1000, transformCallback);  
}

void odomTF::transformCallback(const nav_msgs::Odometry& odom) {
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = odom.header.stamp;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = odom.pose.pose.position.x;
    odom_trans.transform.translation.y = odom.pose.pose.position.y;
    odom_trans.transform.translation.z = odom.pose.pose.position.z;
    odom_trans.transform.rotation.z = odom.pose.pose.orientation.z;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

}