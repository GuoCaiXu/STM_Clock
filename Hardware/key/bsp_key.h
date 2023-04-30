# ifndef _BSP_KEY_H
# define _BSP_KEY_H

# include "stm32f10x.h"
# include "stdbool.h"

# define KEY1_GPIO_CLK          RCC_APB2Periph_GPIOB
# define KEY1_GPIO_PORT         GPIOB
# define KEY1_GPIO_PIN          GPIO_Pin_11

# define KEY2_GPIO_CLK          RCC_APB2Periph_GPIOB
# define KEY2_GPIO_PORT         GPIOB
# define KEY2_GPIO_PIN          GPIO_Pin_1

struct Keys{

    uint8_t judge_sta;      // 查看到哪一步
    bool key_sta;           // 按下为0
    bool single_flag;       // 短按键标志位 按下为1
    bool long_flag;         // 长按键标志位 按下为1
    uint32_t key_time;      // 按下时间
};

void Key_GPIO_Init(void);
uint8_t Key_dl(void);

# endif /*_BSP_KEY_H*/
