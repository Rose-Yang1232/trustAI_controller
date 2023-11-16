//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trustaimerge.h
//
// Code generated for Simulink model 'trustaimerge'.
//
// Model version                  : 1.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 16 11:16:38 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_trustaimerge_h_
#define RTW_HEADER_trustaimerge_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "trustaimerge_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_trustaimerge_T {
  SL_Bus_trustaimerge_std_msgs_Float64 In1;// '<S9>/In1'
  SL_Bus_trustaimerge_std_msgs_Float64 In1_o;// '<S8>/In1'
  SL_Bus_trustaimerge_std_msgs_Float64 In1_m;// '<S7>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_trustaimerge_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_k;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_d;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S3>/SourceBlock'
};

// Parameters (default storage)
struct P_trustaimerge_T_ {
  SL_Bus_trustaimerge_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_trustaimerge_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                  //  Referenced by: '<S7>/Out1'

  SL_Bus_trustaimerge_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                           //  Referenced by: '<S3>/Constant'

  SL_Bus_trustaimerge_std_msgs_Float64 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                    //  Referenced by: '<S8>/Out1'

  SL_Bus_trustaimerge_std_msgs_Float64 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                           //  Referenced by: '<S4>/Constant'

  SL_Bus_trustaimerge_std_msgs_Float64 Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                    //  Referenced by: '<S9>/Out1'

  SL_Bus_trustaimerge_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                           //  Referenced by: '<S5>/Constant'

  real_T Constant_Value_b;             // Expression: 105
                                          //  Referenced by: '<S6>/Constant'

  real_T Saturation_UpperSat;          // Expression: 0.5
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.5
                                          //  Referenced by: '<S6>/Saturation'

};

// Real-time Model Data Structure
struct tag_RTM_trustaimerge_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_trustaimerge_T trustaimerge_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_trustaimerge_T trustaimerge_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_trustaimerge_T trustaimerge_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void trustaimerge_initialize(void);
  extern void trustaimerge_step(void);
  extern void trustaimerge_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_trustaimerge_T *const trustaimerge_M;

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
//  '<Root>' : 'trustaimerge'
//  '<S1>'   : 'trustaimerge/Blank Message'
//  '<S2>'   : 'trustaimerge/Publish'
//  '<S3>'   : 'trustaimerge/Subscribe'
//  '<S4>'   : 'trustaimerge/Subscribe1'
//  '<S5>'   : 'trustaimerge/Subscribe2'
//  '<S6>'   : 'trustaimerge/trustaicontroller'
//  '<S7>'   : 'trustaimerge/Subscribe/Enabled Subsystem'
//  '<S8>'   : 'trustaimerge/Subscribe1/Enabled Subsystem'
//  '<S9>'   : 'trustaimerge/Subscribe2/Enabled Subsystem'
//  '<S10>'  : 'trustaimerge/trustaicontroller/MATLAB Function'

#endif                                 // RTW_HEADER_trustaimerge_h_

//
// File trailer for generated code.
//
// [EOF]
//
