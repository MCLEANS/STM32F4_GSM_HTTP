#ifndef _HTTP_H
#define _HTTP_H

#include "USART.h"
#include <string.h>

namespace custom_libraries
{
    class HTTP : public USART{
        private:
        private:
            void delay_ms(uint16_t duration);
        public:
            uint16_t duration_counter;
        public:
            HTTP(USART_TypeDef *_USART,
				GPIO_TypeDef *GPIO,
				_DMA ACTUAL_DMA,
				DMA_Stream_TypeDef *DMA_STREAM,
				uint8_t RX_PIN,
				uint8_t TX_PIN,
				int baudrate);
            void send_sms(char* phone_number, char* payload);
            ~HTTP();

    };

} // namespace custom_libaries




#endif //_HTTP_H