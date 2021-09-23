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
        for(volatile uint64_t i = 0; i < duration; i++){}
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

    void HTTP::enable_sms_reception(){
        char sms_mode[] = "AT+CMGF=1\r\n";
        char delete_sms_from_storage[] = "AT+CMGDA=1\r\n";
        char notify_of_new_messages[] = "AT+CNMI=2,2,0,0,0\r\n";
        print(sms_mode);
        pseudo_delay(100000);
        print(delete_sms_from_storage);
        pseudo_delay(100000);
        print(notify_of_new_messages);
        pseudo_delay(100000);
    }

    HTTP::~HTTP(){
         /* Implement destructor here */
     }
    
} // namespace custom_libaries
