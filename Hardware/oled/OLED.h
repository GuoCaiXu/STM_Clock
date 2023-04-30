#ifndef __OLED_H
#define __OLED_H

# include "stm32f10x.h"

/*��������*/
#define OLED_W_SCL(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(x))
#define OLED_W_SDA(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(x))

# define OLED_SCL_PIN       GPIO_Pin_8
# define OLED_SDA_PIN       GPIO_Pin_9

/*OLED��ʼ��*/
void OLED_Init(void);
/*OLED����*/
void OLED_Clear(void);
/*OLED��ʾһ���ַ�*/
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
/*OLED��ʾ�ַ���*/
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
/*OLED��ʾ���֣�ʮ���ƣ�������*/
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
/* OLED��ʾ���֣�ʮ���ƣ�����������*/
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
/*OLED��ʾ���֣�ʮ�����ƣ�������*/
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
/*OLED��ʾ���֣������ƣ�������*/
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
