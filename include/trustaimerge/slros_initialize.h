#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "trustaimerge_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block trustaimerge/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_1;

// For Block trustaimerge/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_9;

// For Block trustaimerge/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Sub_trustaimerge_47;

// For Block trustaimerge/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_trustaimerge_std_msgs_Float64> Pub_trustaimerge_23;

void slros_node_init(int argc, char** argv);

#endif
