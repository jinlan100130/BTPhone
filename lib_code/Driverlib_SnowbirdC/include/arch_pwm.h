/*******************************************************************************
 * @file arch_pwm.h
 * @brief list pwm interface operations
 * PWM is a square wave whose duty cycle and frequency can be adjusted.
 * In AK system, it is generated by a defined gpio 
 *    and commonly used to adjust backlight of lcd
 * Copyright (C) 2012 Anyka (GuangZhou) Software Technology Co., Ltd.
 * @author  zhanggaoxin
 * @date 2012-12-18
*******************************************************************************/
#ifndef __ARCH_PWM_H__
#define __ARCH_PWM_H__


#include "anyka_types.h"


/** @defgroup PWM PWM group
 * ingroup Drv_Lib
 */
/*@{*/

typedef enum
{
    uiPWM0 = 0,
    uiPWM1,
    MAX_PWM_NUM /* PWM number */
} T_ePWM_ID;


/*******************************************************************************
 * @brief  set duty cycle of pwm
 * @author zhanggaoxin
 * @date   2012-12-18
 * @param  [in] pwm_id pwm id, can be uiPWM0, uiPWM1.
 * @param  [in] pwm_freq frequency of pwm, must in [92HZ--6MHZ]
 * @param  [in] duty_cycle duty_cycle of pwm
 * @return T_BOOL
 * @retval AK_TRUE set successfully
 * @retval AK_FALSE set unsuccessfully
*******************************************************************************/
T_BOOL pwm_set_duty_cycle(T_ePWM_ID pwm_id, T_U32 pwm_freq, T_U16 duty_cycle);


/*@}*/
#endif //__ARCH_PWM_H__

