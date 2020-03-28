/*
 * CombinedModel.h
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

#ifndef RTW_HEADER_CombinedModel_h_
#define RTW_HEADER_CombinedModel_h_
#include <cfloat>
#include <cstring>
#include <stddef.h>
#ifndef CombinedModel_COMMON_INCLUDES_
# define CombinedModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* CombinedModel_COMMON_INCLUDES_ */

#include "CombinedModel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T FirstIntegrator;              /* '<Root>/First Integrator' */
  real_T SecondIntegrator;             /* '<Root>/Second Integrator' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Error;                        /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S36>/Proportional Gain' */
  real_T Integrator;                   /* '<S31>/Integrator' */
  real_T DerivativeGain;               /* '<S25>/Derivative Gain' */
  real_T Filter;                       /* '<S26>/Filter' */
  real_T SumD;                         /* '<S26>/SumD' */
  real_T FilterCoefficient;            /* '<S34>/Filter Coefficient' */
  real_T Sum;                          /* '<S40>/Sum' */
  real_T MagnetLimitation055N;         /* '<Root>/Magnet Limitation 0 - 55 N' */
  real_T MagnetAcceleration;           /* '<Root>/Magnet Acceleration' */
  real_T IntegralGain;                 /* '<S28>/Integral Gain' */
  real_T NetAcceleration;              /* '<Root>/Sum1' */
} B_CombinedModel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T FirstIntegrator_CSTATE;       /* '<Root>/First Integrator' */
  real_T SecondIntegrator_CSTATE;      /* '<Root>/Second Integrator' */
  real_T Integrator_CSTATE;            /* '<S31>/Integrator' */
  real_T Filter_CSTATE;                /* '<S26>/Filter' */
} X_CombinedModel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T FirstIntegrator_CSTATE;       /* '<Root>/First Integrator' */
  real_T SecondIntegrator_CSTATE;      /* '<Root>/Second Integrator' */
  real_T Integrator_CSTATE;            /* '<S31>/Integrator' */
  real_T Filter_CSTATE;                /* '<S26>/Filter' */
} XDot_CombinedModel_T;

/* State disabled  */
typedef struct {
  boolean_T FirstIntegrator_CSTATE;    /* '<Root>/First Integrator' */
  boolean_T SecondIntegrator_CSTATE;   /* '<Root>/Second Integrator' */
  boolean_T Integrator_CSTATE;         /* '<S31>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S26>/Filter' */
} XDis_CombinedModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_CombinedModel_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S25>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S28>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S26>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S31>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S34>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S36>/Proportional Gain'
                                        */
  real_T FirstIntegrator_IC;           /* Expression: 0
                                        * Referenced by: '<Root>/First Integrator'
                                        */
  real_T Gravity_Value;                /* Expression: 9.8
                                        * Referenced by: '<Root>/Gravity'
                                        */
  real_T InitialHeight_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/Initial Height'
                                        */
  real_T SetPoint_Value;               /* Expression: 0.005
                                        * Referenced by: '<Root>/Set Point'
                                        */
  real_T SecondIntegrator_IC;          /* Expression: 0
                                        * Referenced by: '<Root>/Second Integrator'
                                        */
  real_T MagnetLimitation055N_UpperSat;/* Expression: 55
                                        * Referenced by: '<Root>/Magnet Limitation 0 - 55 N'
                                        */
  real_T MagnetLimitation055N_LowerSat;/* Expression: 0
                                        * Referenced by: '<Root>/Magnet Limitation 0 - 55 N'
                                        */
  real_T PodMass_Value;                /* Expression: 5
                                        * Referenced by: '<Root>/Pod Mass'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CombinedModel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_CombinedModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model CombinedModel */
class CombinedModelModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  CombinedModelModelClass();

  /* Destructor */
  ~CombinedModelModelClass();

  /* Real-Time Model get method */
  RT_MODEL_CombinedModel_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_CombinedModel_T CombinedModel_P;

  /* Block signals */
  B_CombinedModel_T CombinedModel_B;
  X_CombinedModel_T CombinedModel_X;   /* Block continuous states */

  /* Real-Time Model */
  RT_MODEL_CombinedModel_T CombinedModel_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void CombinedModel_derivatives();
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CombinedModel'
 * '<S1>'   : 'CombinedModel/PID Controller'
 * '<S2>'   : 'CombinedModel/PID Controller/Anti-windup'
 * '<S3>'   : 'CombinedModel/PID Controller/D Gain'
 * '<S4>'   : 'CombinedModel/PID Controller/Filter'
 * '<S5>'   : 'CombinedModel/PID Controller/Filter ICs'
 * '<S6>'   : 'CombinedModel/PID Controller/I Gain'
 * '<S7>'   : 'CombinedModel/PID Controller/Ideal P Gain'
 * '<S8>'   : 'CombinedModel/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'CombinedModel/PID Controller/Integrator'
 * '<S10>'  : 'CombinedModel/PID Controller/Integrator ICs'
 * '<S11>'  : 'CombinedModel/PID Controller/N Copy'
 * '<S12>'  : 'CombinedModel/PID Controller/N Gain'
 * '<S13>'  : 'CombinedModel/PID Controller/P Copy'
 * '<S14>'  : 'CombinedModel/PID Controller/Parallel P Gain'
 * '<S15>'  : 'CombinedModel/PID Controller/Reset Signal'
 * '<S16>'  : 'CombinedModel/PID Controller/Saturation'
 * '<S17>'  : 'CombinedModel/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'CombinedModel/PID Controller/Sum'
 * '<S19>'  : 'CombinedModel/PID Controller/Sum Fdbk'
 * '<S20>'  : 'CombinedModel/PID Controller/Tracking Mode'
 * '<S21>'  : 'CombinedModel/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'CombinedModel/PID Controller/postSat Signal'
 * '<S23>'  : 'CombinedModel/PID Controller/preSat Signal'
 * '<S24>'  : 'CombinedModel/PID Controller/Anti-windup/Passthrough'
 * '<S25>'  : 'CombinedModel/PID Controller/D Gain/Internal Parameters'
 * '<S26>'  : 'CombinedModel/PID Controller/Filter/Cont. Filter'
 * '<S27>'  : 'CombinedModel/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S28>'  : 'CombinedModel/PID Controller/I Gain/Internal Parameters'
 * '<S29>'  : 'CombinedModel/PID Controller/Ideal P Gain/Passthrough'
 * '<S30>'  : 'CombinedModel/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S31>'  : 'CombinedModel/PID Controller/Integrator/Continuous'
 * '<S32>'  : 'CombinedModel/PID Controller/Integrator ICs/Internal IC'
 * '<S33>'  : 'CombinedModel/PID Controller/N Copy/Disabled'
 * '<S34>'  : 'CombinedModel/PID Controller/N Gain/Internal Parameters'
 * '<S35>'  : 'CombinedModel/PID Controller/P Copy/Disabled'
 * '<S36>'  : 'CombinedModel/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S37>'  : 'CombinedModel/PID Controller/Reset Signal/Disabled'
 * '<S38>'  : 'CombinedModel/PID Controller/Saturation/Passthrough'
 * '<S39>'  : 'CombinedModel/PID Controller/Saturation Fdbk/Disabled'
 * '<S40>'  : 'CombinedModel/PID Controller/Sum/Sum_PID'
 * '<S41>'  : 'CombinedModel/PID Controller/Sum Fdbk/Disabled'
 * '<S42>'  : 'CombinedModel/PID Controller/Tracking Mode/Disabled'
 * '<S43>'  : 'CombinedModel/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S44>'  : 'CombinedModel/PID Controller/postSat Signal/Forward_Path'
 * '<S45>'  : 'CombinedModel/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_CombinedModel_h_ */
