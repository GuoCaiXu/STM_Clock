# ifndef _BSP_DELAY_H
# define _BSP_DELAY_H

# include "stm32f10x.h"

/*----------------------��������----------------------*/
void Delay_us(uint32_t xus);                    //΢����ʱ
void Delay_ms(uint32_t xms);                    //������ʱ
void Delay_s(uint32_t xs);                      //����ʱ

# endif /*_BSP_DELAY*/
