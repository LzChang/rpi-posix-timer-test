#include "send_uart.h"
#include <unistd.h>

extern struct local_variable local_variable_information;
void send_data(ui8_t * send_buffer,ui8_t send_length)
{
	printf("enter send function\n");

	const ui8_t send_interrupt=1;

	digitalWrite(send_interrupt,LOW);
	digitalWrite(send_interrupt,HIGH);
	digitalWrite(send_interrupt,LOW);

	for(ui32_t k=0;k<send_length;k++)
	{
		//serialPutchar(local_variable_information.fd,send_buffer[k]);
		write(local_variable_information.fd, send_buffer, send_length -1);
	}
	printf("send finshed\n");
}

