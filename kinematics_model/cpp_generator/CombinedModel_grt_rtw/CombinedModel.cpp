/*
 * CombinedModel.cpp
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void CombinedModelModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CombinedModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  CombinedModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  CombinedModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void CombinedModelModelClass::step()
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep((&CombinedModel_M))) {
    /* set solver stop time */
    if (!((&CombinedModel_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&CombinedModel_M)->solverInfo, (((&CombinedModel_M)
        ->Timing.clockTickH0 + 1) * (&CombinedModel_M)->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&CombinedModel_M)->solverInfo, (((&CombinedModel_M)
        ->Timing.clockTick0 + 1) * (&CombinedModel_M)->Timing.stepSize0 +
        (&CombinedModel_M)->Timing.clockTickH0 * (&CombinedModel_M)
        ->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&CombinedModel_M))) {
    (&CombinedModel_M)->Timing.t[0] = rtsiGetT(&(&CombinedModel_M)->solverInfo);
  }

  /* Integrator: '<Root>/First Integrator' */
  CombinedModel_B.FirstIntegrator = CombinedModel_X.FirstIntegrator_CSTATE;

  /* Integrator: '<Root>/Second Integrator' */
  CombinedModel_B.SecondIntegrator = CombinedModel_X.SecondIntegrator_CSTATE;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Initial Height'
   */
  CombinedModel_B.Sum2 = CombinedModel_B.SecondIntegrator +
    CombinedModel_P.InitialHeight_Value;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Set Point'
   */
  CombinedModel_B.Error = CombinedModel_P.SetPoint_Value - CombinedModel_B.Sum2;

  /* Gain: '<S36>/Proportional Gain' */
  CombinedModel_B.ProportionalGain = CombinedModel_P.PIDController_P *
    CombinedModel_B.Error;

  /* Integrator: '<S31>/Integrator' */
  CombinedModel_B.Integrator = CombinedModel_X.Integrator_CSTATE;

  /* Gain: '<S25>/Derivative Gain' */
  CombinedModel_B.DerivativeGain = CombinedModel_P.PIDController_D *
    CombinedModel_B.Error;

  /* Integrator: '<S26>/Filter' */
  CombinedModel_B.Filter = CombinedModel_X.Filter_CSTATE;

  /* Sum: '<S26>/SumD' */
  CombinedModel_B.SumD = CombinedModel_B.DerivativeGain - CombinedModel_B.Filter;

  /* Gain: '<S34>/Filter Coefficient' */
  CombinedModel_B.FilterCoefficient = CombinedModel_P.PIDController_N *
    CombinedModel_B.SumD;

  /* Sum: '<S40>/Sum' */
  CombinedModel_B.Sum = (CombinedModel_B.ProportionalGain +
    CombinedModel_B.Integrator) + CombinedModel_B.FilterCoefficient;

  /* Saturate: '<Root>/Magnet Limitation 0 - 55 N' */
  u0 = CombinedModel_B.Sum;
  u1 = CombinedModel_P.MagnetLimitation055N_LowerSat;
  u2 = CombinedModel_P.MagnetLimitation055N_UpperSat;
  if (u0 > u2) {
    CombinedModel_B.MagnetLimitation055N = u2;
  } else if (u0 < u1) {
    CombinedModel_B.MagnetLimitation055N = u1;
  } else {
    CombinedModel_B.MagnetLimitation055N = u0;
  }

  /* End of Saturate: '<Root>/Magnet Limitation 0 - 55 N' */

  /* Product: '<Root>/Magnet Acceleration' incorporates:
   *  Constant: '<Root>/Pod Mass'
   */
  CombinedModel_B.MagnetAcceleration = CombinedModel_B.MagnetLimitation055N /
    CombinedModel_P.PodMass_Value;

  /* Gain: '<S28>/Integral Gain' */
  CombinedModel_B.IntegralGain = CombinedModel_P.PIDController_I *
    CombinedModel_B.Error;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Gravity'
   */
  CombinedModel_B.NetAcceleration = CombinedModel_B.MagnetAcceleration -
    CombinedModel_P.Gravity_Value;
  if (rtmIsMajorTimeStep((&CombinedModel_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&CombinedModel_M)->rtwLogInfo, ((&CombinedModel_M)
      ->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&CombinedModel_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&CombinedModel_M))!=-1) &&
          !((rtmGetTFinal((&CombinedModel_M))-((((&CombinedModel_M)
               ->Timing.clockTick1+(&CombinedModel_M)->Timing.clockTickH1*
               4294967296.0)) * 0.4)) > ((((&CombinedModel_M)->Timing.clockTick1
              +(&CombinedModel_M)->Timing.clockTickH1* 4294967296.0)) * 0.4) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus((&CombinedModel_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&CombinedModel_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&CombinedModel_M)->Timing.clockTick0)) {
      ++(&CombinedModel_M)->Timing.clockTickH0;
    }

    (&CombinedModel_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&CombinedModel_M
      )->solverInfo);

    {
      /* Update absolute timer for sample time: [0.4s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.4, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&CombinedModel_M)->Timing.clockTick1++;
      if (!(&CombinedModel_M)->Timing.clockTick1) {
        (&CombinedModel_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void CombinedModelModelClass::CombinedModel_derivatives()
{
  XDot_CombinedModel_T *_rtXdot;
  _rtXdot = ((XDot_CombinedModel_T *) (&CombinedModel_M)->derivs);

  /* Derivatives for Integrator: '<Root>/First Integrator' */
  _rtXdot->FirstIntegrator_CSTATE = CombinedModel_B.NetAcceleration;

  /* Derivatives for Integrator: '<Root>/Second Integrator' */
  _rtXdot->SecondIntegrator_CSTATE = CombinedModel_B.FirstIntegrator;

  /* Derivatives for Integrator: '<S31>/Integrator' */
  _rtXdot->Integrator_CSTATE = CombinedModel_B.IntegralGain;

  /* Derivatives for Integrator: '<S26>/Filter' */
  _rtXdot->Filter_CSTATE = CombinedModel_B.FilterCoefficient;
}

/* Model initialize function */
void CombinedModelModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&CombinedModel_M)->solverInfo, &(&CombinedModel_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&CombinedModel_M)->solverInfo, &rtmGetTPtr((&CombinedModel_M)));
    rtsiSetStepSizePtr(&(&CombinedModel_M)->solverInfo, &(&CombinedModel_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&CombinedModel_M)->solverInfo, &(&CombinedModel_M)->derivs);
    rtsiSetContStatesPtr(&(&CombinedModel_M)->solverInfo, (real_T **)
                         &(&CombinedModel_M)->contStates);
    rtsiSetNumContStatesPtr(&(&CombinedModel_M)->solverInfo, &(&CombinedModel_M
      )->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&CombinedModel_M)->solverInfo,
      &(&CombinedModel_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&CombinedModel_M)->solverInfo,
      &(&CombinedModel_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&CombinedModel_M)->solverInfo,
      &(&CombinedModel_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&CombinedModel_M)->solverInfo, (&rtmGetErrorStatus((
      &CombinedModel_M))));
    rtsiSetRTModelPtr(&(&CombinedModel_M)->solverInfo, (&CombinedModel_M));
  }

  rtsiSetSimTimeStep(&(&CombinedModel_M)->solverInfo, MAJOR_TIME_STEP);
  (&CombinedModel_M)->intgData.y = (&CombinedModel_M)->odeY;
  (&CombinedModel_M)->intgData.f[0] = (&CombinedModel_M)->odeF[0];
  (&CombinedModel_M)->intgData.f[1] = (&CombinedModel_M)->odeF[1];
  (&CombinedModel_M)->intgData.f[2] = (&CombinedModel_M)->odeF[2];
  (&CombinedModel_M)->contStates = ((X_CombinedModel_T *) &CombinedModel_X);
  rtsiSetSolverData(&(&CombinedModel_M)->solverInfo, static_cast<void *>
                    (&(&CombinedModel_M)->intgData));
  rtsiSetSolverName(&(&CombinedModel_M)->solverInfo,"ode3");
  rtmSetTPtr((&CombinedModel_M), &(&CombinedModel_M)->Timing.tArray[0]);
  rtmSetTFinal((&CombinedModel_M), 20.0);
  (&CombinedModel_M)->Timing.stepSize0 = 0.4;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&CombinedModel_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&CombinedModel_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&CombinedModel_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&CombinedModel_M)->rtwLogInfo, "tout");
    rtliSetLogX((&CombinedModel_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&CombinedModel_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&CombinedModel_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&CombinedModel_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&CombinedModel_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&CombinedModel_M)->rtwLogInfo, 1);
    rtliSetLogY((&CombinedModel_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&CombinedModel_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&CombinedModel_M)->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) std::memset((static_cast<void *>(&CombinedModel_B)), 0,
                     sizeof(B_CombinedModel_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&CombinedModel_X), 0,
                       sizeof(X_CombinedModel_T));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&CombinedModel_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&CombinedModel_M)), (&CombinedModel_M)->Timing.stepSize0,
    (&rtmGetErrorStatus((&CombinedModel_M))));

  /* InitializeConditions for Integrator: '<Root>/First Integrator' */
  CombinedModel_X.FirstIntegrator_CSTATE = CombinedModel_P.FirstIntegrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Second Integrator' */
  CombinedModel_X.SecondIntegrator_CSTATE = CombinedModel_P.SecondIntegrator_IC;

  /* InitializeConditions for Integrator: '<S31>/Integrator' */
  CombinedModel_X.Integrator_CSTATE =
    CombinedModel_P.PIDController_InitialConditio_l;

  /* InitializeConditions for Integrator: '<S26>/Filter' */
  CombinedModel_X.Filter_CSTATE =
    CombinedModel_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void CombinedModelModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
CombinedModelModelClass::CombinedModelModelClass() : CombinedModel_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
CombinedModelModelClass::~CombinedModelModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_CombinedModel_T * CombinedModelModelClass::getRTM()
{
  return (&CombinedModel_M);
}
