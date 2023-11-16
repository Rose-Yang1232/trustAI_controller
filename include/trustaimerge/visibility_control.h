#ifndef TRUSTAIMERGE__VISIBILITY_CONTROL_H_
#define TRUSTAIMERGE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TRUSTAIMERGE_EXPORT __attribute__ ((dllexport))
    #define TRUSTAIMERGE_IMPORT __attribute__ ((dllimport))
  #else
    #define TRUSTAIMERGE_EXPORT __declspec(dllexport)
    #define TRUSTAIMERGE_IMPORT __declspec(dllimport)
  #endif
  #ifdef TRUSTAIMERGE_BUILDING_LIBRARY
    #define TRUSTAIMERGE_PUBLIC TRUSTAIMERGE_EXPORT
  #else
    #define TRUSTAIMERGE_PUBLIC TRUSTAIMERGE_IMPORT
  #endif
  #define TRUSTAIMERGE_PUBLIC_TYPE TRUSTAIMERGE_PUBLIC
  #define TRUSTAIMERGE_LOCAL
#else
  #define TRUSTAIMERGE_EXPORT __attribute__ ((visibility("default")))
  #define TRUSTAIMERGE_IMPORT
  #if __GNUC__ >= 4
    #define TRUSTAIMERGE_PUBLIC __attribute__ ((visibility("default")))
    #define TRUSTAIMERGE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TRUSTAIMERGE_PUBLIC
    #define TRUSTAIMERGE_LOCAL
  #endif
  #define TRUSTAIMERGE_PUBLIC_TYPE
#endif
#endif  // TRUSTAIMERGE__VISIBILITY_CONTROL_H_
// Generated 16-Nov-2023 11:16:45
// Copyright 2019-2020 The MathWorks, Inc.
