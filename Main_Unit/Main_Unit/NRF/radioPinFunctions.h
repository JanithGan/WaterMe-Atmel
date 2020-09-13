/*
 * radioPinFunctions.h
 *
 * Created: 12/09/2020 1:38:50 PM
 *  Author: Hasindu
 */ 


#ifndef RADIOPINFUNCTIONS_H_
#define RADIOPINFUNCTIONS_H_

void nrf24_setupPins();
void nrf24_ce_digitalWrite(uint8_t state);
void nrf24_csn_digitalWrite(uint8_t state);
void nrf24_sck_digitalWrite(uint8_t state);
void nrf24_mosi_digitalWrite(uint8_t state);
uint8_t nrf24_miso_digitalRead();



#endif /* RADIOPINFUNCTIONS_H_ */