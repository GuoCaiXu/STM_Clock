# include "./clock/bsp_clock.h"
# include "./oled/OLED.h"
# include "./key/bsp_key.h"
# include "./delay/bsp_delay.h"
# include "./led/bsp_led.h"

extern uint8_t Hour, Minute, Second;
uint8_t alarm_hour = 0, alarm_minute = 0;
uint8_t alarm_switch = 0;   // 闹钟开关 0 关闭    1 开启
uint8_t alarm_flag = 0;     // 1 闹钟响了未按   0 按了
sint8_t count_hour = 0, count_minute = 0, count_second = 0;
uint8_t count_flag = 0;     // 0 未开启计时   1 开启计时

void CLock_Show_OLED_Init(void){

    OLED_ShowString(1, 1, "     Clock:     ");
    OLED_ShowString(2, 7, ":  :");
}

void Clock_Show_OLED(void){

    if (Second >= 60){
      Minute ++;
      Second = 0;
      if (Minute >= 60){
        Hour ++;
        Minute = 0;
        if (Hour >= 24) Hour = 0;
      }
    }
    OLED_ShowNum(2, 5, Hour, 2);
    OLED_ShowNum(2, 8, Minute, 2);
    OLED_ShowNum(2, 11, Second, 2);
}

void Alter_Time(void){

  sint8_t My_Hour, My_Minute, My_Second;
  My_Hour = Hour;
  My_Minute = Minute;
  My_Second = Second;
  uint8_t alter_port = 0; // 等于0 修改小时   1 修改分钟  2 修改秒钟
  uint8_t Save_flag = 0;    // 1 保存修改时间   2 不保存修改时间

  OLED_ShowNum(2, 5, My_Hour, 2);
  OLED_ShowNum(2, 8, My_Minute, 2);
  OLED_ShowNum(2, 11, My_Second, 2);
  while(1){

    uint8_t key_flag = Key_dl();
    
    if (key_flag == 4){
      OLED_ShowString(1, 1, "                 ");
      OLED_ShowString(2, 1, "Whether to save?");
      OLED_ShowString(3, 1, " Yes        NO  ");
      
      while(1){
        key_flag = Key_dl();

        if (key_flag == 1){
          Save_flag = 1;
          break;
        }
        if (key_flag == 2){
          Save_flag = 2;
          break;
        }
      }

      if (Save_flag == 1 || Save_flag == 2) {
        OLED_ShowString(1, 1, "     Clock:      ");
        OLED_ShowString(2, 1, "                 ");
        OLED_ShowString(3, 1, "                 ");
        OLED_ShowString(2, 7, ":  :");

        if (Save_flag == 1){
          Hour = My_Hour;
          Minute = My_Minute;
          Second = My_Second;
        }
        break;
      }
    }

    if (key_flag == 2){
      alter_port ++;
      alter_port &= 0x03;
    }
    if (alter_port == 0){
      if (key_flag == 1){
        My_Hour ++;
        if (My_Hour == 24) My_Hour = 0;
      }
        if (key_flag == 3){
          My_Hour --;
          if (My_Hour < 0) My_Hour = 23;
      }
      OLED_ShowNum(2, 5, My_Hour, 2);
      OLED_ShowString(3, 5, "--       ");
    }
    if (alter_port == 1){
      if (key_flag == 1){
        My_Minute ++;
        if (My_Minute == 60) My_Minute = 0;
      }
        if (key_flag == 3){
          My_Minute --;
          if (My_Minute < 0) My_Minute = 59;
      }
      OLED_ShowNum(2, 8, My_Minute, 2);
      OLED_ShowString(3, 5, "   --   ");
    }
    if (alter_port == 2){
      if (key_flag == 1) My_Second = 0;
      OLED_ShowNum(2, 11, My_Second, 2);
      OLED_ShowString(3, 5, "      --");
    }
  }
}

void Clock_Alarm(void){

  sint8_t My_Hour, My_Minute;
  My_Hour = alarm_hour;
  My_Minute = alarm_minute;
  uint8_t alter_port = 0; // 等于0 修改小时   1 修改分钟  2 修改秒钟

  OLED_ShowString(1, 1, "     Alarm:      ");
  OLED_ShowString(2, 1, "                 ");
  OLED_ShowString(3, 1, "                 ");
  OLED_ShowString(2, 8, ":    ");
  OLED_ShowNum(2, 6, My_Hour, 2);
  OLED_ShowNum(2, 9, My_Minute, 2);

  while(1){

    uint8_t key_flag = Key_dl();
    uint8_t Save_flag = 0;

    if (key_flag == 4){
      alarm_hour = My_Hour;
      alarm_minute = My_Minute;
      OLED_ShowString(1, 1, "                 ");
      OLED_ShowString(2, 1, "     Saved      ");
      OLED_ShowString(3, 1, " Yes            ");

      while(1){
        key_flag = Key_dl();

        if (key_flag == 1) {
          Save_flag = 1;
          break;
        }
      }

      if (Save_flag == 1){
        OLED_ShowString(1, 1, "     Clock:      ");
        OLED_ShowString(2, 1, "                 ");
        OLED_ShowString(3, 1, "                 ");
        OLED_ShowString(2, 7, ":  :");
        break;
      }
    }

    if (key_flag == 2){
      alter_port ++;
      alter_port &= 0x01;
    }
    if (alter_port == 0){
      if (key_flag == 1){
        My_Hour ++;
        if (My_Hour == 24) My_Hour = 0;
      }
        if (key_flag == 3){
          My_Hour --;
          if (My_Hour < 0) My_Hour = 23;
      }
      OLED_ShowNum(2, 6, My_Hour, 2);
      OLED_ShowString(3, 6, "--      ");
    }
    if (alter_port == 1){
      if (key_flag == 1){
        My_Minute ++;
        if (My_Minute == 60) My_Minute = 0;
      }
        if (key_flag == 3){
          My_Minute --;
          if (My_Minute < 0) My_Minute = 59;
      }
      OLED_ShowNum(2, 9, My_Minute, 2);
      OLED_ShowString(3, 6, "   --  ");
    }
  }
}

void Alarm_Switch_Show(void){

  alarm_switch ^= 1;
  if (alarm_switch == 1){
    OLED_ShowString(4, 15, "*");
  }
  else {
    OLED_ShowString(4, 15, " ");
  }
}

void Alarm_ON(void){

  if (alarm_flag == 1){

    OLED_ShowString(1, 1, "                 ");
    OLED_ShowString(2, 1, "   Shut Alarm    ");
    OLED_ShowString(3, 1, " Yes            ");

    while(1){

      uint8_t key_flag = Key_dl();

      if (key_flag == 1){
        LED_OFF;
        alarm_flag = 0;
        Alarm_Switch_Show();

        OLED_ShowString(1, 1, "     Clock:      ");
        OLED_ShowString(2, 1, "                 ");
        OLED_ShowString(3, 1, "                 ");
        OLED_ShowString(2, 7, ":  :");
        return;
      }
      LED_TOGGLE;
      Delay_ms(200);
    }
  }

  if (alarm_switch == 1){
    if (Hour == alarm_hour && Minute == alarm_minute){
      alarm_flag = 1;
    }
  }
}

void Count_Down(void){

  sint8_t My_Hour, My_Minute, My_Second;
  My_Hour = count_hour;
  My_Minute = count_minute;
  uint8_t alter_port = 0; // 等于0 修改小时   1 修改分钟  2 修改秒钟

  OLED_ShowString(1, 1, "  Count Down:    ");
  OLED_ShowString(2, 1, "                 ");
  OLED_ShowString(3, 1, "                 ");
  OLED_ShowString(2, 7, ":  :");
  OLED_ShowNum(2, 5, My_Hour, 2);
  OLED_ShowNum(2, 8, My_Minute, 2);
  OLED_ShowNum(2, 11, My_Second, 2);

  while(1){

    uint8_t key_flag = Key_dl();
    uint8_t Save_flag = 0;

    if (key_flag == 4){
      count_hour = My_Hour;
      count_minute = My_Minute;
      count_second = My_Second;
      OLED_ShowString(1, 1, "                 ");
      OLED_ShowString(2, 1, "     Saved      ");
      OLED_ShowString(3, 1, " Yes            ");

      while(1){
        key_flag = Key_dl();

        if (key_flag == 1) {
          Save_flag = 1;
          break;
        }
      }

      if (Save_flag == 1){
        OLED_ShowString(1, 1, "     Clock:      ");
        OLED_ShowString(2, 1, "                 ");
        OLED_ShowString(3, 1, "                 ");
        OLED_ShowString(2, 7, ":  :");
        count_flag = 1;
        break;
      }
    }

    if (key_flag == 2){
      alter_port ++;
      alter_port &= 0x03;
    }

    if (alter_port == 0){
      if (key_flag == 1){
        My_Hour ++;
        if (My_Hour == 24) My_Hour = 0;
      }
        if (key_flag == 3){
          My_Hour --;
          if (My_Hour < 0) My_Hour = 23;
      }
      OLED_ShowNum(2, 5, My_Hour, 2);
      OLED_ShowString(3, 5, "--       ");
    }
    if (alter_port == 1){
      if (key_flag == 1){
        My_Minute ++;
        if (My_Minute == 60) My_Minute = 0;
      }
        if (key_flag == 3){
          My_Minute --;
          if (My_Minute < 0) My_Minute = 59;
      }
      OLED_ShowNum(2, 8, My_Minute, 2);
      OLED_ShowString(3, 5, "   --   ");
    }
    if (alter_port == 2){
      if (key_flag == 1) {
        My_Second += 10;
        if (My_Second >= 60) My_Second = 0;
      }
      if (key_flag == 3){
        My_Second -= 10;
        if (My_Second <= 0) My_Second = 60;
      }
      OLED_ShowNum(2, 11, My_Second, 2);
      OLED_ShowString(3, 5, "      --");
    }
  }
}

void Count_Down_ON(void){

  if (count_flag == 1){
    static uint8_t count_ON_flag = 0;

    if (count_second <= 0){

      if (count_minute > 0) {
        count_second = 59;
        count_minute --;
        if (count_minute <= 0){
          if (count_hour > 0){
            count_hour --;
            count_minute = 59;
          }
          else count_ON_flag = 1;
        }
      }
      else count_ON_flag = 1;
    }

    if (count_ON_flag == 1){
      OLED_ShowString(1, 1, "                 ");
      OLED_ShowString(2, 1, "   Shut Count    ");
      OLED_ShowString(3, 1, " Yes             ");

      while(1){
      
        uint8_t key_flag = 0;
        key_flag = Key_dl();

        if (key_flag == 1){
          OLED_ShowString(1, 1, "     Clock:      ");
          OLED_ShowString(2, 1, "                 ");
          OLED_ShowString(3, 1, "                 ");
          OLED_ShowString(2, 7, ":  :");
          count_ON_flag = 0;
          count_flag = 0;
          LED_OFF;
          break;
        }
        LED_TOGGLE;
        Delay_ms(200);
      }
    }
  }
}

void Count_Show(void){

  OLED_ShowNum(2, 5, count_hour, 2);
  OLED_ShowNum(2, 8, count_minute, 2);
  OLED_ShowNum(2, 11, count_second, 2);
}
