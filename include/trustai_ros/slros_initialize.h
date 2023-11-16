#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "TrustAI_ros_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block TrustAI_ros/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_TrustAI_ros_std_msgs_Float64> Sub_TrustAI_ros_64;

// For Block TrustAI_ros/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_TrustAI_ros_std_msgs_Float64> Pub_TrustAI_ros_68;

void slros_node_init(int argc, char** argv);

#endif
