/**********************************
@file: dma.h
@brief: header file for dma.c
@author: John Kim
@date: Mar 31st, 2018
***********************************/

#ifndef DMA_H_
#define DMA_H_

#include <MKL25Z4.h>
#include <stdint.h>
#include <stddef.h>


#define ONEBYTE 0x120000u
#define TWOBYTE 0x240000u
#define FOURBYTE 0x000000u
#define BUFF_SIZE 4
#define DESTINATION_ADDRESS 0x20000000

void dma_setup(uint8_t mode);
/***************************************
@brief: Initializes DMA with interrupt, variable source size, and peripheral request
@param: mode - selects between three different source size
****************************************/

void memmove_dma(uint8_t *src, uint8_t *dst, size_t length);
/***************************************
@brief: moves length number of bytes from source to destination
@param: src-source pointer dst-destination pointer length-number of bytes to transfer
****************************************/

void memset_dma(uint8_t *src, size_t length, uint8_t value);
/***************************************
@brief: sets length number of bytes as value
@param: src-address to set length-number of bytes to set value-value to set
****************************************/
void DMA0_IRQHandler(void);

#endif /*DMA*/
