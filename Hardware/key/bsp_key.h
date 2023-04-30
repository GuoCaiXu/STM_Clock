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

    uint8_t judge_sta;      // �鿴����һ��
    bool key_sta;           // ����Ϊ0
    bool single_flag;       // �̰�����־λ ����Ϊ1
    bool long_flag;         // ��������־λ ����Ϊ1
    uint32_t key_time;      // ����ʱ��
};

void Key_GPIO_Init(void);
uint8_t Key_dl(void);

# endif /*_BSP_KEY_H*/
