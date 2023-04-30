# include "stm32f10x.h"
# include "./oled/OLED.h"
# include "./delay/bsp_delay.h"
# include "./tim/bsp_tim.h"
# include "./clock/bsp_clock.h"
# include "./key/bsp_key.h"
# include "./led/bsp_led.h"

extern struct Keys key[];
extern uint8_t count_flag;

/**
 *  @brief  主函数
 *  @param  无
 *  @retval 无
 */
int main(void){

    OLED_Init();
    TIMx_Init();
    CLock_Show_OLED_Init();
    LED_Init();
    
    while(1){
        if (count_flag == 0) Clock_Show_OLED();
        else Count_Show();
        Alarm_ON();
        Count_Down_ON();
        uint8_t key_flag = Key_dl();
        if (key_flag == 1){         // 开启闹钟
            Alarm_Switch_Show();
        }
        if (key_flag == 2){         // 修改时间
            Alter_Time();
        }
        if (key_flag == 3) Clock_Alarm();       // 设置闹钟时间
        if (key_flag == 4){         // 倒计时
            Count_Down();
        }
    }
}
