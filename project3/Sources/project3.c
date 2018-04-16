#include "project3.h"
#include "nordic.h"
#include "uart.h"
#include "spi.h"
#include "conversion.h"
#include "systick.h"


void project3(){
	uint8_t status, digits;
	GPIO_Configure();
	GPIO_nrf_init();
	UART_configure(9600);
	SPI_init();
	SYST_RVR = SysTick_RVR_RELOAD(20971520/4);
	SYST_CVR = SysTick_CVR_CURRENT(0);
	SYST_CSR |= SysTick_CSR_ENABLE_MASK | SysTick_CSR_TICKINT_MASK | SysTick_CSR_CLKSOURCE_MASK;


	char a[50] = "Status register value: ";
	char b[50] = "Config register value: ";
	char number1[10] = "";
	char number2[10] = "";
	char nline[3] = "\n";

/*
	nrf_write_config(0x08);
	status = nrf_read_config();
	UART_send_string(b);
	digits=my_itoa((uint32_t) status, number2, 2);
	UART_send_n(number2, digits-1);
	UART_send(nline);
*/
	while(1){
		tick1 = SYST_CVR&SysTick_CVR_CURRENT_MASK;
		//status = nrf_read_status();
		nrf_write_config(0x00);
		while((tick1-(SYST_CVR&SysTick_CVR_CURRENT_MASK))<50000){}
		status = nrf_read_config();
		//while((tick1-(SYST_CVR&SysTick_CVR_CURRENT_MASK))<300000){}
	}

	status = nrf_read_status();
	UART_send_string(a);
	digits=my_itoa((uint32_t) status, number1, 2);
	UART_send_n(number1, digits-1);
	UART_send(nline);
}
