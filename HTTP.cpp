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
    
    bool HTTP::available(){
        if(DMA_STREAM == DMA1_Stream0 || DMA_STREAM == DMA2_Stream0){
            if(DMA_STREAM == DMA1_Stream0){
                if(DMA1->LISR & DMA_LISR_TCIF0) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->LIFCR |= DMA_LIFCR_CTCIF0;
                }
                else{
                   
                }
            }
            if(DMA_STREAM == DMA2_Stream0){
                if(DMA2->LISR & DMA_LISR_TCIF0) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->LIFCR |= DMA_LIFCR_CTCIF0;
                }
                else{
                    
                }
            }

        }

        if(DMA_STREAM == DMA1_Stream1 || DMA_STREAM == DMA2_Stream1){
            if(DMA_STREAM == DMA1_Stream1){
                if(DMA1->LISR & DMA_LISR_TCIF1) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->LIFCR |= DMA_LIFCR_CTCIF1;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream1){
                if(DMA2->LISR & DMA_LISR_TCIF1) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
                }
                else{
                    
                }
            }
        }
        if(DMA_STREAM == DMA1_Stream2 || DMA_STREAM == DMA2_Stream2){
            if(DMA_STREAM == DMA1_Stream2){
                if(DMA1->LISR & DMA_LISR_TCIF2) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->LIFCR |= DMA_LIFCR_CTCIF2;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream2){
                if(DMA2->LISR & DMA_LISR_TCIF2) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->LIFCR |= DMA_LIFCR_CTCIF2;
                }
                else{
                    
                }
            }
        }
        if(DMA_STREAM == DMA1_Stream3 || DMA_STREAM == DMA2_Stream3){
            if(DMA_STREAM == DMA1_Stream3){
                if(DMA1->LISR & DMA_LISR_TCIF3) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->LIFCR |= DMA_LIFCR_CTCIF3;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream3){
                if(DMA2->LISR & DMA_LISR_TCIF3) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->LIFCR |= DMA_LIFCR_CTCIF3;
                }
                else{
                    
                }
            }
        }
        if(DMA_STREAM == DMA1_Stream4 || DMA_STREAM == DMA2_Stream4){
            if(DMA_STREAM == DMA1_Stream4){
                if(DMA1->HISR & DMA_HISR_TCIF4) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->HIFCR |= DMA_HIFCR_CTCIF4;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream4){
                if(DMA2->HISR & DMA_HISR_TCIF4) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->HIFCR |= DMA_HIFCR_CTCIF4;
                }
                else{
                    
                }
            }
        }

        if(DMA_STREAM == DMA1_Stream5 || DMA_STREAM == DMA2_Stream5){
            if(DMA_STREAM == DMA1_Stream5){
                if(DMA1->HISR & DMA_HISR_TCIF5) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->HIFCR |= DMA_HIFCR_CTCIF5;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream5){
                if(DMA2->HISR & DMA_HISR_TCIF5) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->HIFCR |= DMA_HIFCR_CTCIF5;
                }
                else{
                    
                }
            }
        }

        if(DMA_STREAM == DMA1_Stream6 || DMA_STREAM == DMA2_Stream6){
            if(DMA_STREAM == DMA1_Stream6){
                if(DMA1->HISR & DMA_HISR_TCIF6) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->HIFCR |= DMA_HIFCR_CTCIF6;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream6){
                if(DMA2->HISR & DMA_HISR_TCIF6) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->HIFCR |= DMA_HIFCR_CTCIF6;
                }
                else{
                    
                }
            }
        }

        if(DMA_STREAM == DMA1_Stream7 || DMA_STREAM == DMA2_Stream7){
            if(DMA_STREAM == DMA1_Stream7){
                if(DMA1->HISR & DMA_HISR_TCIF7) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA1->HIFCR |= DMA_HIFCR_CTCIF7;
                }
                else{
                    
                }
            }
            if(DMA_STREAM == DMA2_Stream4){
                if(DMA2->HISR & DMA_HISR_TCIF7) {
                    this->is_available = true;
                     /* Clear flag by writing 1 to the DMA_LIFCR register */
                    DMA2->HIFCR |= DMA_HIFCR_CTCIF7;
                }
                else{
                    
                }
            }
        }

        return this->is_available;
    }

    void HTTP::clear_flag(){
        this->is_available = false;
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

    void HTTP::read_buffer(char *buffer){
       
    }

    HTTP::~HTTP(){
         /* Implement destructor here */
     }
    
} // namespace custom_libaries
