#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "TrustAI_ros";

// For Block TrustAI_ros/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_TrustAI_ros_std_msgs_Float64> Sub_TrustAI_ros_64;

// For Block TrustAI_ros/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_TrustAI_ros_std_msgs_Float64> Pub_TrustAI_ros_68;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

