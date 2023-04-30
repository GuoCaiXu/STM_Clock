# include "./tim/bsp_tim.h"

static void Clock_Init(void){

    Clock_APBxPeriph_FUN(Clock_CLK, ENABLE);

    TIM_InternalClockConfig(Clock_TIM);

    TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;

    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_Period = Clock_ARR_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = Clock_PSC_Prescaler;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(Clock_TIM, &TIM_TimeBaseStructure);

    TIM_ClearFlag(Clock_TIM, TIM_FLAG_Update);
    TIM_ITConfig(Clock_TIM, TIM_IT_Update, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef    NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = Clock_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(Clock_TIM, ENABLE);
}

static void KEY_Init(void){

    KEY_APBxPeriph_FUN(KEY_CLK, ENABLE);

    TIM_InternalClockConfig(KEY_TIM);

    TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;

    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_Period = KEY_ARR_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = KEY_PSC_Prescaler;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(KEY_TIM, &TIM_TimeBaseStructure);

    TIM_ClearFlag(KEY_TIM, TIM_FLAG_Update);
    TIM_ITConfig(KEY_TIM, TIM_IT_Update, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    NVIC_InitTypeDef    NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = KEY_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(KEY_TIM, ENABLE);
}

void TIMx_Init(void){

    Clock_Init();
    KEY_Init();
}
