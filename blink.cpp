/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdlib.h>
#include <unistd.h>
#include "pico/stdlib.h"
#include <stdio.h>


class Led 
{ 

  public:
    Led ()
    {
      printf("object created");
    }

    ~Led()
    {
      printf("led destruct");
    }

    void On()
    {
       gpio_put(pin_number_, 1);
      status_= true ;
      
    }
    void Off()
    {
      gpio_put(pin_number_, 0);
      status_= false ;
    }

    void Toggle()
    {
      if (status_==true)
      {
        Off();
      }
      else 
      {
        On();
      }
      
    }
    void Init(const int pin_number)
    {
      pin_number_ = pin_number;
      bool status_= false ;
      gpio_init(pin_number);
      gpio_set_dir(pin_number, GPIO_OUT);
    }
 private:
    bool status_;
    int pin_number_;
    

};


int main()
{

stdio_init_all();

Led pin;
pin.Init(PICO_DEFAULT_LED_PIN);
while (true)
{
  pin.On();
  sleep_ms(1000);
  printf("on_\n");
  pin.Toggle();
  sleep_ms(1000);
  printf("off_\n");
}


}

// int time() {
//   int sec = 0;
//   while (true) {
//     sleep_ms(1);
//     sec++;
//     printf("%d\n",sec);
//   }
// }

