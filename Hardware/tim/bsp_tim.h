# ifndef _BSP_TIM_H
# define _BSP_TIM_H

# include "stm32f10x.h"

# define Clock_TIM                      TIM2
# define Clock_APBxPeriph_FUN           RCC_APB1PeriphClockCmd
# define Clock_CLK                      RCC_APB1Periph_TIM2

/*1 s*/
# define Clock_ARR_Period               (10000-1)
# define Clock_PSC_Prescaler            (7200-1)   

# define Clock_IRQn                     TIM2_IRQn
# define Clock_IRQHandler               TIM2_IRQHandler

# define KEY_TIM                        TIM3
# define KEY_APBxPeriph_FUN             RCC_APB1PeriphClockCmd
# define KEY_CLK                        RCC_APB1Periph_TIM3

/*10 ms*/
# define KEY_ARR_Period                 (10000-1)
# define KEY_PSC_Prescaler              (72-1)   

# define KEY_IRQn                       TIM3_IRQn
# define KEY_IRQHandler                 TIM3_IRQHandler

void TIMx_Init(void);

# endif /*_BSP_TIM_H*/
