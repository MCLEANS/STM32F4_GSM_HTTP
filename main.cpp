#include "stm32f4xx.h"
#include "clockconfig.h"
#include "HTTP.h"
#include "Timerconfiguration.h"

#define SERIAL_RX 7
#define SERIAL_TX 6
#define BAUDRATE 9600

custom_libraries::clock_config system_clock;
custom_libraries::HTTP GSM(USART1,GPIOB,custom_libraries::_DMA2,DMA2_Stream2,SERIAL_RX,SERIAL_TX,BAUDRATE);
custom_libraries::Timer_configuration timer(TIM7,65535,640); // (Timer,Prescaler,Auto_reload_value)

/* Timer Interrupt Service Routine */
extern "C" void TIM7_IRQHandler(){
    if(TIM7->SR & TIM_SR_UIF){
      GSM.duration_counter++;/* increment counter here */
      TIM7->SR &= ~TIM_SR_UIF;
    }
}

int main(void) {
  
  system_clock.initialize();

  NVIC_SetPriority(TIM7_IRQn,0x01);
  NVIC_EnableIRQ(TIM7_IRQn);

  GSM.send_sms("+254719881926","SYSTEM_TEST");

  while(1){

  }
}
