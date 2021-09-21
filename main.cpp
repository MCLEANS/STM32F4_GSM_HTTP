#include "stm32f4xx.h"
#include "clockconfig.h"
#include "HTTP.h"

#define GSM_RX 7
#define GSM_TX 6

#define SERIAL_RX 9
#define SERIAL_TX 8

#define GSM_BAUDRATE 9600
#define SERIAL_BAUDRATE 9600

custom_libraries::clock_config system_clock;
custom_libraries::HTTP GSM(USART1,GPIOB,custom_libraries::_DMA2,DMA2_Stream2,GSM_RX,GSM_TX,GSM_BAUDRATE);
custom_libraries::HTTP Serial(USART3,GPIOD,custom_libraries::_DMA1,DMA1_Stream1,SERIAL_RX,SERIAL_TX,SERIAL_BAUDRATE);

int main(void) {
  
  system_clock.initialize();
  Serial.initialize();
  GSM.enable_sms_reception();

  while(1){
    Serial.println(GSM.receive_buffer);

  }
}
