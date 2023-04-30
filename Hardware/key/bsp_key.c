# include "./key/bsp_key.h"

void Key_GPIO_Init(void){

    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);

    GPIO_InitTypeDef    GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN | KEY2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
}

extern struct Keys key[];

uint8_t Key_dl(void){

    uint8_t key_flag = 0;

    if (key[0].single_flag == 1) {

        key_flag = 1;
        key[0].single_flag = 0;
    }
    if (key[0].long_flag == 1) {
        key_flag = 2;
        key[0].long_flag = 0;
    }
    if (key[1].single_flag == 1) {
        key_flag = 3;
        key[1].single_flag = 0;
    }
    if (key[1].long_flag == 1) {
        key_flag = 4;
        key[1].long_flag = 0;
    }

    return key_flag;
}
