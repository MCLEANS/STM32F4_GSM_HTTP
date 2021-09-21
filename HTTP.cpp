#include "HTTP.h"

namespace custom_libraries
{
    HTTP::HTTP(USART_TypeDef *_USART,
				GPIO_TypeDef *GPIO,
				_DMA ACTUAL_DMA,
				DMA_Stream_TypeDef *DMA_STREAM,
				uint8_t RX_PIN,
				uint8_t TX_PIN,
				int baudrate): USART(_USART,
                                    GPIO,
                                    ACTUAL_DMA,
                                    DMA_STREAM,
                                    RX_PIN,
                                    TX_PIN,
                                    baudrate){
        /* Initialize serial communication */
        initialize();
        
     }
    
    void HTTP::pseudo_delay(uint64_t duration){
        for(volatile int i = 0; i < duration; i++){}
    }

    void HTTP::send_sms(char* phone_number, char* payload){
        char sms_mode[] = "AT+CMGF=1\r";
        char config_number[] = "AT+CMGS=\"";
        char recipient_number[15];
        char command_termination[] = "\"\r";
        char send_payload[1024];
        char term = (char)26;
        strcpy(recipient_number,phone_number);
        strcat(config_number,recipient_number);
        strcat(config_number,command_termination);
        strcpy(send_payload,payload);
        print(sms_mode);
        pseudo_delay(100000); //The delay value of 100,000 was arrived at by experimentation
        print(config_number);
        pseudo_delay(100000);
        print(send_payload);
        pseudo_delay(100000);
        print(&term);
    }

    HTTP::~HTTP(){
         /* Implement destructor here */
     }
    
} // namespace custom_libaries
