#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "trustaimerge";

// For Block trustaimerge/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_1;

// For Block trustaimerge/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_9;

// For Block trustaimerge/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_47;

// For Block trustaimerge/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Pub_trustaimerge_23;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

