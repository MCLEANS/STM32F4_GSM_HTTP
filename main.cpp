#include "stm32f4xx.h"
#include "clockconfig.h"
#include "HTTP.h"

#define SERIAL_RX 7
#define SERIAL_TX 6
#define BAUDRATE 9600

custom_libraries::clock_config system_clock;
custom_libraries::HTTP GSM(USART1,GPIOB,custom_libraries::_DMA2,DMA2_Stream2,SERIAL_RX,SERIAL_TX,BAUDRATE);

int main(void) {
  
  system_clock.initialize();

  GSM.send_sms("+254719881926","SYSTEM_TEST");

  while(1){

  }
}
