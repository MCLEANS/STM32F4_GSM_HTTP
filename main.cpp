#include "stm32f4xx.h"
#include "clockconfig.h"

/**
 * TASKS
 * 1. Implement HTTP class
 * 2. Inherit from the USART class
 * 3. Initialize USART and sent http packets
 */

custom_libraries::clock_config system_clock;

int main(void) {
  
  system_clock.initialize();

  while(1){

  }
}
