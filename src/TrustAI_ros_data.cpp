//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TrustAI_ros_data.cpp
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
#include "TrustAI_ros.h"

// Block parameters (default storage)
P_TrustAI_ros_T TrustAI_ros_P = {
  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S6>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 10
  //  Referenced by: '<Root>/ego_vel'

  10.0,

  // Expression: 80
  //  Referenced by: '<S5>/Saturation'

  80.0,

  // Expression: 0
  //  Referenced by: '<S5>/Saturation'

  0.0,

  // Expression: 30
  //  Referenced by: '<Root>/target_dist'

  30.0,

  // Expression: 3
  //  Referenced by: '<Root>/cmd_acc'

  3.0,

  // Expression: -1.5
  //  Referenced by: '<Root>/cmd_acc'

  -1.5,

  // Expression: 0
  //  Referenced by: '<Root>/ego_x0'

  0.0,

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<S5>/Transfer Fcn'

  -0.5,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<S5>/Transfer Fcn'

  0.5
};

//
// File trailer for generated code.
//
// [EOF]
//
