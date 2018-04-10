/****************************************************
@file: port.c
@brief: Provdies control over GPIO, including LED pins
@author: John Kim
@date: Feb 21st, 2018
Note: function description resides in the header file
****************************************************/

#include "MKL25Z4.h"
#include "port.h"

void GPIO_Configure(){
	SIM_SCGC5 |= (SIM_SCGC5_PORTB_MASK + SIM_SCGC5_PORTD_MASK);
    PORTB_PCR18 |= (PORT_PCR_MUX(1));
    PORTB_PCR19 |= (PORT_PCR_MUX(1));
    PORTD_PCR1 |= (PORT_PCR_MUX(1));
	GPIOB_PDDR |= ((1 << RGB_RED_PIN) + (1 << RGB_GREEN_PIN));
	GPIOB_PSOR |= ((1 << RGB_RED_PIN) + (1 << RGB_GREEN_PIN));
	GPIOD_PDDR |= 1<<RGB_BLUE_PIN;
	GPIOD_PSOR |= 1<<RGB_BLUE_PIN;
}

void Toggle_Red_LED(){
	uint32_t set = 0x1 << RGB_RED_PIN;
	PTB_BASE_PTR->PTOR ^= set;
}//Toggle the Red LED state. On to Off, or Off to on.

void PORTB_Set(uint8_t bit_num){
	uint32_t set = 0x1 << (bit_num);
	PTB_BASE_PTR->PSOR |= set;
}

void PORTD_Set(uint8_t bit_num){
	uint32_t set = 0x1 << bit_num;
	PTD_BASE_PTR->PSOR |= set;
}//These two functions should use the appropriate GPIO function to toggle the output (PSOR)

void PORTB_Clear(uint8_t bit_num){
	uint32_t clear = 0x1 << bit_num;
	PTB_BASE_PTR->PCOR |= clear;
}

void PORTD_Clear(uint8_t bit_num){
	uint32_t clear = 0x1 << bit_num;
	PTD_BASE_PTR->PCOR |= clear;
}//These two functions should use the appropriate GPIO function to toggle the output (PCOR)

void PORTB_Toggle(uint8_t bit_num){
	uint32_t clear = 0x1 << bit_num;
	PTB_BASE_PTR->PTOR |= clear;
}

void PORTD_Toggle(uint8_t bit_num){
	uint32_t clear = 0x1 << bit_num;
	PTD_BASE_PTR->PTOR |= clear;
}//These two functions should use the appropriate GPIO function to toggle the output (PTOR)
