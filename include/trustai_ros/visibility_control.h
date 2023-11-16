#ifndef TRUSTAI_ROS__VISIBILITY_CONTROL_H_
#define TRUSTAI_ROS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TRUSTAI_ROS_EXPORT __attribute__ ((dllexport))
    #define TRUSTAI_ROS_IMPORT __attribute__ ((dllimport))
  #else
    #define TRUSTAI_ROS_EXPORT __declspec(dllexport)
    #define TRUSTAI_ROS_IMPORT __declspec(dllimport)
  #endif
  #ifdef TRUSTAI_ROS_BUILDING_LIBRARY
    #define TRUSTAI_ROS_PUBLIC TRUSTAI_ROS_EXPORT
  #else
    #define TRUSTAI_ROS_PUBLIC TRUSTAI_ROS_IMPORT
  #endif
  #define TRUSTAI_ROS_PUBLIC_TYPE TRUSTAI_ROS_PUBLIC
  #define TRUSTAI_ROS_LOCAL
#else
  #define TRUSTAI_ROS_EXPORT __attribute__ ((visibility("default")))
  #define TRUSTAI_ROS_IMPORT
  #if __GNUC__ >= 4
    #define TRUSTAI_ROS_PUBLIC __attribute__ ((visibility("default")))
    #define TRUSTAI_ROS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TRUSTAI_ROS_PUBLIC
    #define TRUSTAI_ROS_LOCAL
  #endif
  #define TRUSTAI_ROS_PUBLIC_TYPE
#endif
#endif  // TRUSTAI_ROS__VISIBILITY_CONTROL_H_
// Generated 15-Nov-2023 18:38:27
// Copyright 2019-2020 The MathWorks, Inc.
