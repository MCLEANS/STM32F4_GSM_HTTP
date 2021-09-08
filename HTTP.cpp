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
        /* Implement constructor here */
     }

     HTTP::~HTTP(){
         /* Implement destructor here */
     }
    
} // namespace custom_libaries
