/*
 * CombinedModel_data.cpp
 *
 * Primary and Secondary School License - for use in teaching and meeting
 * course requirements at primary and secondary schools only.  Not for
 * government, commercial, university, or other organizational use.
 *
 * Code generation for model "CombinedModel".
 *
 * Model version              : 1.64
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Sat Mar 28 00:12:30 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "CombinedModel.h"
#include "CombinedModel_private.h"

/* Block parameters (default storage) */
P_CombinedModel_T CombinedModelModelClass::CombinedModel_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S25>/Derivative Gain'
   */
  1217.40122699774,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S28>/Integral Gain'
   */
  679104.182905479,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S26>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S31>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S34>/Filter Coefficient'
   */
  1363.49256355405,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S36>/Proportional Gain'
   */
  58024.7697722311,

  /* Expression: 0
   * Referenced by: '<Root>/First Integrator'
   */
  0.0,

  /* Expression: 9.8
   * Referenced by: '<Root>/Gravity'
   */
  9.8,

  /* Expression: 0
   * Referenced by: '<Root>/Initial Height'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/Set Point'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Second Integrator'
   */
  0.0,

  /* Expression: 55
   * Referenced by: '<Root>/Magnet Limitation 0 - 55 N'
   */
  55.0,

  /* Expression: 0
   * Referenced by: '<Root>/Magnet Limitation 0 - 55 N'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Pod Mass'
   */
  5.0
};
