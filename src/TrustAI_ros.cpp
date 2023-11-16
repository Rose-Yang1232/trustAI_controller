//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TrustAI_ros.cpp
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

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "TrustAI_ros_types.h"
#include "TrustAI_ros_private.h"

// Block signals (default storage)
B_TrustAI_ros_T TrustAI_ros_B;

// Continuous states
X_TrustAI_ros_T TrustAI_ros_X;

// Disabled State Vector
XDis_TrustAI_ros_T TrustAI_ros_XDis;

// Block states (default storage)
DW_TrustAI_ros_T TrustAI_ros_DW;

// Real-time model
RT_MODEL_TrustAI_ros_T TrustAI_ros_M_ = RT_MODEL_TrustAI_ros_T();
RT_MODEL_TrustAI_ros_T *const TrustAI_ros_M = &TrustAI_ros_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  TrustAI_ros_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TrustAI_ros_step();
  TrustAI_ros_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TrustAI_ros_step();
  TrustAI_ros_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void TrustAI_ros_step(void)
{
  SL_Bus_TrustAI_ros_std_msgs_Float64 b_varargout_2;
  SL_Bus_TrustAI_ros_std_msgs_Float64 rtb_BusAssignment;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&TrustAI_ros_M->solverInfo,
                          ((TrustAI_ros_M->Timing.clockTick0+1)*
      TrustAI_ros_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(TrustAI_ros_M)) {
    TrustAI_ros_M->Timing.t[0] = rtsiGetT(&TrustAI_ros_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    // Constant: '<Root>/ego_vel'
    TrustAI_ros_B.ego_vel = TrustAI_ros_P.ego_vel_Value;
  }

  // Integrator: '<S5>/Integrator'
  if (TrustAI_ros_DW.Integrator_IWORK != 0) {
    TrustAI_ros_X.Integrator_CSTATE = TrustAI_ros_B.ego_vel;
  }

  // Saturate: '<S5>/Saturation' incorporates:
  //   Integrator: '<S5>/Integrator'

  if (TrustAI_ros_X.Integrator_CSTATE > TrustAI_ros_P.Saturation_UpperSat) {
    // Saturate: '<S5>/Saturation'
    TrustAI_ros_B.Saturation = TrustAI_ros_P.Saturation_UpperSat;
  } else if (TrustAI_ros_X.Integrator_CSTATE < TrustAI_ros_P.Saturation_LowerSat)
  {
    // Saturate: '<S5>/Saturation'
    TrustAI_ros_B.Saturation = TrustAI_ros_P.Saturation_LowerSat;
  } else {
    // Saturate: '<S5>/Saturation'
    TrustAI_ros_B.Saturation = TrustAI_ros_X.Integrator_CSTATE;
  }

  // End of Saturate: '<S5>/Saturation'
  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_TrustAI_ros_64.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S6>/Enable'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S6>/In1'
      TrustAI_ros_B.In1 = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // MinMax: '<Root>/min_of_lead_and_tar_dist' incorporates:
    //   Constant: '<Root>/target_dist'
    //   SignalConversion generated from: '<Root>/Bus Selector1'

    if ((TrustAI_ros_B.In1.Data <= TrustAI_ros_P.target_dist_Value) || rtIsNaN
        (TrustAI_ros_P.target_dist_Value)) {
      // MinMax: '<Root>/min_of_lead_and_tar_dist'
      TrustAI_ros_B.min_of_lead_and_tar_dist = TrustAI_ros_B.In1.Data;
    } else {
      // MinMax: '<Root>/min_of_lead_and_tar_dist'
      TrustAI_ros_B.min_of_lead_and_tar_dist = TrustAI_ros_P.target_dist_Value;
    }

    // End of MinMax: '<Root>/min_of_lead_and_tar_dist'
  }

  // MATLAB Function: '<Root>/MergeControl'
  TrustAI_ros_B.cmd_acc = (TrustAI_ros_B.min_of_lead_and_tar_dist - 5.0 *
    TrustAI_ros_B.Saturation) * 0.5 + (10.0 - TrustAI_ros_B.Saturation) * 0.1;

  // Saturate: '<Root>/cmd_acc'
  if (TrustAI_ros_B.cmd_acc > TrustAI_ros_P.cmd_acc_UpperSat) {
    // MATLAB Function: '<Root>/MergeControl' incorporates:
    //   Saturate: '<Root>/cmd_acc'

    TrustAI_ros_B.cmd_acc = TrustAI_ros_P.cmd_acc_UpperSat;
  } else if (TrustAI_ros_B.cmd_acc < TrustAI_ros_P.cmd_acc_LowerSat) {
    // MATLAB Function: '<Root>/MergeControl' incorporates:
    //   Saturate: '<Root>/cmd_acc'

    TrustAI_ros_B.cmd_acc = TrustAI_ros_P.cmd_acc_LowerSat;
  }

  // End of Saturate: '<Root>/cmd_acc'

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment.Data = TrustAI_ros_B.cmd_acc;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_TrustAI_ros_68.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    // Constant: '<Root>/ego_x0'
    TrustAI_ros_B.ego_x0 = TrustAI_ros_P.ego_x0_Value;
  }

  // Integrator: '<S5>/Integrator1'
  if (TrustAI_ros_DW.Integrator1_IWORK != 0) {
    TrustAI_ros_X.Integrator1_CSTATE = TrustAI_ros_B.ego_x0;
  }

  // End of Integrator: '<S5>/Integrator1'

  // TransferFcn: '<S5>/Transfer Fcn'
  TrustAI_ros_B.TransferFcn = TrustAI_ros_P.TransferFcn_C *
    TrustAI_ros_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    // Update for Integrator: '<S5>/Integrator'
    TrustAI_ros_DW.Integrator_IWORK = 0;

    // Update for Integrator: '<S5>/Integrator1'
    TrustAI_ros_DW.Integrator1_IWORK = 0;
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(TrustAI_ros_M)) {
    rt_ertODEUpdateContinuousStates(&TrustAI_ros_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++TrustAI_ros_M->Timing.clockTick0;
    TrustAI_ros_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TrustAI_ros_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.2s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.2, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      TrustAI_ros_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void TrustAI_ros_derivatives(void)
{
  XDot_TrustAI_ros_T *_rtXdot;
  _rtXdot = ((XDot_TrustAI_ros_T *) TrustAI_ros_M->derivs);

  // Derivatives for Integrator: '<S5>/Integrator'
  _rtXdot->Integrator_CSTATE = TrustAI_ros_B.TransferFcn;

  // Derivatives for Integrator: '<S5>/Integrator1'
  _rtXdot->Integrator1_CSTATE = TrustAI_ros_B.Saturation;

  // Derivatives for TransferFcn: '<S5>/Transfer Fcn'
  _rtXdot->TransferFcn_CSTATE = TrustAI_ros_P.TransferFcn_A *
    TrustAI_ros_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += TrustAI_ros_B.cmd_acc;
}

// Model initialize function
void TrustAI_ros_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&TrustAI_ros_M->solverInfo,
                          &TrustAI_ros_M->Timing.simTimeStep);
    rtsiSetTPtr(&TrustAI_ros_M->solverInfo, &rtmGetTPtr(TrustAI_ros_M));
    rtsiSetStepSizePtr(&TrustAI_ros_M->solverInfo,
                       &TrustAI_ros_M->Timing.stepSize0);
    rtsiSetdXPtr(&TrustAI_ros_M->solverInfo, &TrustAI_ros_M->derivs);
    rtsiSetContStatesPtr(&TrustAI_ros_M->solverInfo, (real_T **)
                         &TrustAI_ros_M->contStates);
    rtsiSetNumContStatesPtr(&TrustAI_ros_M->solverInfo,
      &TrustAI_ros_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TrustAI_ros_M->solverInfo,
      &TrustAI_ros_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TrustAI_ros_M->solverInfo,
      &TrustAI_ros_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TrustAI_ros_M->solverInfo,
      &TrustAI_ros_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TrustAI_ros_M->solverInfo, (boolean_T**)
      &TrustAI_ros_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TrustAI_ros_M->solverInfo, (&rtmGetErrorStatus
      (TrustAI_ros_M)));
    rtsiSetRTModelPtr(&TrustAI_ros_M->solverInfo, TrustAI_ros_M);
  }

  rtsiSetSimTimeStep(&TrustAI_ros_M->solverInfo, MAJOR_TIME_STEP);
  TrustAI_ros_M->intgData.y = TrustAI_ros_M->odeY;
  TrustAI_ros_M->intgData.f[0] = TrustAI_ros_M->odeF[0];
  TrustAI_ros_M->intgData.f[1] = TrustAI_ros_M->odeF[1];
  TrustAI_ros_M->intgData.f[2] = TrustAI_ros_M->odeF[2];
  TrustAI_ros_M->contStates = ((X_TrustAI_ros_T *) &TrustAI_ros_X);
  TrustAI_ros_M->contStateDisabled = ((XDis_TrustAI_ros_T *) &TrustAI_ros_XDis);
  TrustAI_ros_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TrustAI_ros_M->solverInfo, static_cast<void *>
                    (&TrustAI_ros_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&TrustAI_ros_M->solverInfo, false);
  rtsiSetSolverName(&TrustAI_ros_M->solverInfo,"ode3");
  rtmSetTPtr(TrustAI_ros_M, &TrustAI_ros_M->Timing.tArray[0]);
  TrustAI_ros_M->Timing.stepSize0 = 0.2;
  rtmSetFirstInitCond(TrustAI_ros_M, 1);

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[19];
    char_T b_zeroDelimTopic[10];
    static const char_T b_zeroDelimTopic_1[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_2[19] = "/car/state/sim_acc";

    // Start for Constant: '<Root>/ego_vel'
    TrustAI_ros_B.ego_vel = TrustAI_ros_P.ego_vel_Value;

    // Start for Constant: '<Root>/ego_x0'
    TrustAI_ros_B.ego_x0 = TrustAI_ros_P.ego_x0_Value;

    // InitializeConditions for Integrator: '<S5>/Integrator' incorporates:
    //   Integrator: '<S5>/Integrator1'

    if (rtmIsFirstInitCond(TrustAI_ros_M)) {
      TrustAI_ros_X.Integrator_CSTATE = 10.0;
      TrustAI_ros_X.Integrator1_CSTATE = 0.0;
    }

    TrustAI_ros_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S5>/Integrator'

    // InitializeConditions for Integrator: '<S5>/Integrator1'
    TrustAI_ros_DW.Integrator1_IWORK = 1;

    // InitializeConditions for TransferFcn: '<S5>/Transfer Fcn'
    TrustAI_ros_X.TransferFcn_CSTATE = 0.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    TrustAI_ros_B.In1 = TrustAI_ros_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    TrustAI_ros_DW.obj_g.matlabCodegenIsDeleted = false;
    TrustAI_ros_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_TrustAI_ros_64.createSubscriber(&b_zeroDelimTopic[0], 1);
    TrustAI_ros_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    TrustAI_ros_DW.obj.matlabCodegenIsDeleted = false;
    TrustAI_ros_DW.obj.isInitialized = 1;
    for (i = 0; i < 19; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_TrustAI_ros_68.createPublisher(&b_zeroDelimTopic_0[0], 1);
    TrustAI_ros_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(TrustAI_ros_M)) {
    rtmSetFirstInitCond(TrustAI_ros_M, 0);
  }
}

// Model terminate function
void TrustAI_ros_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!TrustAI_ros_DW.obj_g.matlabCodegenIsDeleted) {
    TrustAI_ros_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!TrustAI_ros_DW.obj.matlabCodegenIsDeleted) {
    TrustAI_ros_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
