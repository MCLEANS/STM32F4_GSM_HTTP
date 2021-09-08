#ifndef _HTTP_H
#define _HTTP_H

#include "USART.h"

namespace custom_libraries
{
    class HTTP : public USART{
        private:
        private:
        public:
        public:
            HTTP(USART_TypeDef *_USART,
				GPIO_TypeDef *GPIO,
				_DMA ACTUAL_DMA,
				DMA_Stream_TypeDef *DMA_STREAM,
				uint8_t RX_PIN,
				uint8_t TX_PIN,
				int baudrate);
            ~HTTP();

    };

} // namespace custom_libaries




#endif //_HTTP_H