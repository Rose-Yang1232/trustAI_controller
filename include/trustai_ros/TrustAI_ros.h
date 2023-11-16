//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TrustAI_ros.h
//
// Code generated for Simulink model 'TrustAI_ros'.
//
// Model version                  : 1.12
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 18:38:19 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TrustAI_ros_h_
#define RTW_HEADER_TrustAI_ros_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "TrustAI_ros_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_TrustAI_ros_T {
  real_T ego_vel;                      // '<Root>/ego_vel'
  real_T Saturation;                   // '<S5>/Saturation'
  real_T min_of_lead_and_tar_dist;     // '<Root>/min_of_lead_and_tar_dist'
  real_T cmd_acc;                      // '<Root>/cmd_acc'
  real_T ego_x0;                       // '<Root>/ego_x0'
  real_T TransferFcn;                  // '<S5>/Transfer Fcn'
  SL_Bus_TrustAI_ros_std_msgs_Float64 In1;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_TrustAI_ros_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S4>/SourceBlock'
  int_T Integrator_IWORK;              // '<S5>/Integrator'
  int_T Integrator1_IWORK;             // '<S5>/Integrator1'
};

// Continuous states (default storage)
struct X_TrustAI_ros_T {
  real_T Integrator_CSTATE;            // '<S5>/Integrator'
  real_T Integrator1_CSTATE;           // '<S5>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S5>/Transfer Fcn'
};

// State derivatives (default storage)
struct XDot_TrustAI_ros_T {
  real_T Integrator_CSTATE;            // '<S5>/Integrator'
  real_T Integrator1_CSTATE;           // '<S5>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S5>/Transfer Fcn'
};

// State disabled
struct XDis_TrustAI_ros_T {
  boolean_T Integrator_CSTATE;         // '<S5>/Integrator'
  boolean_T Integrator1_CSTATE;        // '<S5>/Integrator1'
  boolean_T TransferFcn_CSTATE;        // '<S5>/Transfer Fcn'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_TrustAI_ros_T_ {
  SL_Bus_TrustAI_ros_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S1>/Constant'

  SL_Bus_TrustAI_ros_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S6>/Out1'

  SL_Bus_TrustAI_ros_std_msgs_Float64 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                          //  Referenced by: '<S4>/Constant'

  real_T ego_vel_Value;                // Expression: 10
                                          //  Referenced by: '<Root>/ego_vel'

  real_T Saturation_UpperSat;          // Expression: 80
                                          //  Referenced by: '<S5>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S5>/Saturation'

  real_T target_dist_Value;            // Expression: 30
                                          //  Referenced by: '<Root>/target_dist'

  real_T cmd_acc_UpperSat;             // Expression: 3
                                          //  Referenced by: '<Root>/cmd_acc'

  real_T cmd_acc_LowerSat;             // Expression: -1.5
                                          //  Referenced by: '<Root>/cmd_acc'

  real_T ego_x0_Value;                 // Expression: 0
                                          //  Referenced by: '<Root>/ego_x0'

  real_T TransferFcn_A;                // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<S5>/Transfer Fcn'

  real_T TransferFcn_C;                // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<S5>/Transfer Fcn'

};

// Real-time Model Data Structure
struct tag_RTM_TrustAI_ros_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_TrustAI_ros_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_TrustAI_ros_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_TrustAI_ros_T TrustAI_ros_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_TrustAI_ros_T TrustAI_ros_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_TrustAI_ros_T TrustAI_ros_X;

// Disabled states (default storage)
extern XDis_TrustAI_ros_T TrustAI_ros_XDis;

// Block states (default storage)
extern struct DW_TrustAI_ros_T TrustAI_ros_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void TrustAI_ros_initialize(void);
  extern void TrustAI_ros_step(void);
  extern void TrustAI_ros_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_TrustAI_ros_T *const TrustAI_ros_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'TrustAI_ros'
//  '<S1>'   : 'TrustAI_ros/Blank Message'
//  '<S2>'   : 'TrustAI_ros/MergeControl'
//  '<S3>'   : 'TrustAI_ros/Publish'
//  '<S4>'   : 'TrustAI_ros/Subscribe2'
//  '<S5>'   : 'TrustAI_ros/ego_car'
//  '<S6>'   : 'TrustAI_ros/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_TrustAI_ros_h_

//
// File trailer for generated code.
//
// [EOF]
//
