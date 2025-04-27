

#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 100


//* Function Prototypes

void processCommand(const char* command);


void processCommand(const char* command) {
	 if (strcmp(command, "cmd1") == 0) {
	      //  Cy_SCB_UART_PutString(SCB2, "Response for Command 1\r\n");
		 printf("Response for Command 1\r\n");
	    } else if (strcmp(command, "cmd2") == 0) {
	       // Cy_SCB_UART_PutString(SCB2, "Response for Command 2\r\n");
	        printf("Response for Command 2\r\n");
	    } else if (strcmp(command, "cmd3") == 0) {
	        //Cy_SCB_UART_PutString(SCB2, "Response for Command 3\r\n");
	    	printf("Response for Command 3\r\n");
	    } else if (strcmp(command, "cmd4") == 0) {
	       // Cy_SCB_UART_PutString(SCB2, "Response for Command 4\r\n");
	    	printf("Response for Command 4\r\n");
	    } else if (strcmp(command, "cmd5") == 0) {
	       // Cy_SCB_UART_PutString(SCB2, "Response for Command 5\r\n");
	    	printf("Response for Command 5\r\n");
	    } else {
	       // Cy_SCB_UART_PutString(SCB2, "Unknown Command\r\n");
	    	printf("Unknown Command\r\n");
	    }
}


int main(void)
{
	//uint8_t uart_read_value; // Variable for storing character read from terminal
	cy_stc_scb_uart_context_t UART_context;
	char buffer[BUFFER_SIZE];
	int ind = 0;
    cy_rslt_t result;

#if defined (CY_DEVICE_SECURE)
    cyhal_wdt_t wdt_obj;

    /* Clear watchdog timer so that it doesn't trigger a reset */
    result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    cyhal_wdt_free(&wdt_obj);
#endif /* #if defined (CY_DEVICE_SECURE) */

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }



    /* Initialize retarget-io to use the debug UART port */


    result = cy_retarget_io_init_fc(CYBSP_DEBUG_UART_TX,
                                    CYBSP_DEBUG_UART_RX,
                                    CYBSP_DEBUG_UART_CTS,
                                    CYBSP_DEBUG_UART_RTS,
                                    CY_RETARGET_IO_BAUDRATE);

    if (result != CY_RSLT_SUCCESS)
      {
    	printf("Error");
          CY_ASSERT(0);
      }
    Cy_GPIO_Pin_Init(CYBSP_A8_PORT, CYBSP_A8_PIN, &CYBSP_A8_config);
    Cy_GPIO_Pin_Init(CYBSP_A9_PORT, CYBSP_A9_PIN, &CYBSP_A9_config);


       // Initialize SCB2 UART
       result = Cy_SCB_UART_Init(SCB2, &scb_2_config, &UART_context);
       if (result != CY_RSLT_SUCCESS)
       {
         //  printf("SCB2 UART Initialization Failed\n");
           CY_ASSERT(0);
       }

    /* Enable global interrupts */
       __enable_irq();

    Cy_SCB_UART_Enable(SCB2);



   // Cy_SCB_UART_PutString(SCB2,"\x1b[2J\x1b[;H");
//    Cy_SCB_UART_PutString(SCB2,"\r\nhii  viral\r\n");
//    Cy_SCB_UART_PutString(SCB2, "UART without retarget I/O \r\n");
    printf("nhii  viral\r\n");
    printf("UART with retarget I/O \r\n");
    uint8_t read_data;

     for (;;)
     {
        	 while (Cy_SCB_UART_GetNumInRxFifo(SCB5) > 0)
    	        {
    	            read_data = (uint8_t)Cy_SCB_UART_Get(SCB5);
    	            Cy_SCB_UART_Put(SCB5, read_data); // Echo the character back to the terminal
    	            if (read_data == '\n' || read_data == '\r')  // Command delimiter
    	            {
    	                buffer[ind] = '\0';  // Null-terminate the string
    	                processCommand(buffer);
    	                ind = 0;  // Reset buffer index
    	            }
   	            else if (ind < BUFFER_SIZE - 1)
    	            {
    	                buffer[ind++] = read_data;  // Store character in buffer
    	            }
    	        }

     }
}






