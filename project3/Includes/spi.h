 /****************************************************
@file: spi.h
@brief: header file for spi.c
@author: John Kim
@date: Apr 7th, 2018
****************************************************/

#include <stdint.h>
#include <stdlib.h>
#ifndef SPI_H
#define SPI_H

void SPI_init();

/***************************************
@brief: Initializes SPI as master with with 15kHz baud rate
****************************************/

void SPI_read_byte(uint8_t * byte);
/***************************************
@brief: Read a byte from SPI
@param: byte-address to store read value
****************************************/

void SPI_write_byte(uint8_t byte);
/***************************************
@brief: Write a byte to SPI
@param: byte write value
****************************************/

void SPI_send_packet(uint8_t * p, size_t length);
/***************************************
@brief: Writes multiple bytes to SPI
@param: p-address where data is stored
        length-number of bytes to transmit
****************************************/

void SPI_flush();
/***************************************
@brief: Waits until spi transmit is complete
****************************************/

#endif /*spi*/
