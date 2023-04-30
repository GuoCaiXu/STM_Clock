# ifndef _BSP_CLOCK_H
# define _BSP_CLOCK_H

# include "stm32f10x.h"

# define sint8_t    signed char

void CLock_Show_OLED_Init(void);
void Clock_Show_OLED(void);
void Alter_Time(void);
void Clock_Alarm(void);
void Alarm_Switch_Show(void);
void Alarm_ON(void);
void Count_Down(void);
void Count_Down_ON(void);
void Count_Show(void);

# endif /*_BSP_CLOCK*/
