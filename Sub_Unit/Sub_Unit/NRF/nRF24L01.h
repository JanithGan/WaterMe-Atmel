#ifndef NRF24L01_H_
#define NRF24L01_H_

#include "../Variables.h"
#include "../Pins.h"
#include "SPI_Slave.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// -----------------------------------------------------Constants----------------------------------------------------

#define W 1
#define R 0

// -----------------------------------------------------Functions----------------------------------------------------

// SPI Communication
void SPI_Init(void);
char WriteByteSPI(unsigned char cData);
uint8_t GetReg(uint8_t reg);

// NRF Module
void WriteToNrf(uint8_t reg, uint8_t Package);
uint8_t *WritetoNRF(uint8_t ReadWrite, uint8_t reg, uint8_t *val, uint8_t antVal);
void reset(void);

#endif // NRF24L01_H_