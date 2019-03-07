/*
    __digipot_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __digipot_driver.h
@brief    DIGI_POT Driver
@mainpage DIGI_POT Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DIGIPOT
@brief      DIGI_POT Click Driver
@{

| Global Library Prefix | **DIGIPOT** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DIGIPOT_H_
#define _DIGIPOT_H_

/** 
 * @macro T_DIGIPOT_P
 * @brief Driver Abstract type 
 */
#define T_DIGIPOT_P    const uint8_t*

/** @defgroup DIGIPOT_COMPILE Compilation Config */              /** @{ */

   #define   __DIGIPOT_DRV_SPI__                            /**<     @macro __DIGIPOT_DRV_SPI__  @brief SPI driver selector */
//  #define   __DIGIPOT_DRV_I2C__                            /**<     @macro __DIGIPOT_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DIGIPOT_DRV_UART__                           /**<     @macro __DIGIPOT_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DIGIPOT_VAR Variables */                           /** @{ */

extern const uint8_t _DIGIPOT_VOLATILE_WIPER_0;
extern const uint8_t _DIGIPOT_VOLATILE_WIPER_1;
extern const uint8_t _DIGIPOT_NON_VOLATILE_WIPER_0;
extern const uint8_t _DIGIPOT_NON_VOLATILE_WIPER_1;
extern const uint8_t _DIGIPOT_VOLATILE_TCON_REGISTER;
extern const uint8_t _DIGIPOT_STATUS_REGISTER;
extern const uint8_t _DIGIPOT_DATA_EEPROM_6;
extern const uint8_t _DIGIPOT_DATA_EEPROM_7;
extern const uint8_t _DIGIPOT_DATA_EEPROM_8;
extern const uint8_t _DIGIPOT_DATA_EEPROM_9;
extern const uint8_t _DIGIPOT_DATA_EEPROM_A;
extern const uint8_t _DIGIPOT_DATA_EEPROM_B;
extern const uint8_t _DIGIPOT_DATA_EEPROM_C;
extern const uint8_t _DIGIPOT_DATA_EEPROM_D;
extern const uint8_t _DIGIPOT_DATA_EEPROM_E;
extern const uint8_t _DIGIPOT_DATA_EEPROM_F;
extern const uint8_t _DIGIPOT_DATA_WRITE_CMD;

extern const float _DIGIPOT2_VREF_3V3;
extern const float _DIGIPOT2_VREF_5V;

                                                                       /** @} */
/** @defgroup DIGIPOT_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DIGIPOT_INIT Driver Initialization */              /** @{ */

#ifdef   __DIGIPOT_DRV_SPI__
void digipot_spiDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P spiObj);
#endif
#ifdef   __DIGIPOT_DRV_I2C__
void digipot_i2cDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P i2cObj, uint8_t slave);
#endif
#ifdef   __DIGIPOT_DRV_UART__
void digipot_uartDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P uartObj);
#endif


/** @defgroup DIGIPOT_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 8-bit data function
 *
 * @param[in] command         8-bit data address command
 *
 * @param[in] writeData       8-bit data to write
 *
 * Function write 8-bit data via SPI
 * on the MCP4161 chip register.
 */
void digipot_writeByte( uint8_t command, uint8_t writeData );

/**
 * @brief Generic read 8-bit data function
 *
 * @param[in] command         8-bit data address command
 *
 * @return
 * 8-bit data from address command register
 *
 * Function read 8-bit data from address command register
 * on the MCP4161 chip register.
 */
uint8_t digipot_readByte( uint8_t command );

/**
 * @brief Read status register data function
 *
 * @return
 * 8-bit data from status register
 *
 * Function read 8-bit data from atatus register
 * on the MCP4161 chip register.
 */
uint8_t digipot_readStatus();

/**
 * @brief Set 8-bit wiper positions
 *
 * @param[in] wiperPositions    8-bit wiper positions data
 *
 * Function set 8-bit wiper positions data via SPI
 * on the MCP4161 chip register.
 */
void digipot_setWiperPositions( uint8_t wiperPositions );

/**
 * @brief Convert ADC value to volatage
 *
 * @param[in] valueADC         10-bit ADC value
 *
 * @param[in] vRef             Voltage Reference 3.3V or 5V
 *
 * @return
 * float voltage ( 0V - 3.3V ) or ( 0V - 5.0V )
 *
 * Convert 8-bit ADC value to volatage
 */
float digipot_convertOutput( uint8_t valueADC, float vRef );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DIGI_POT_STM.c
    @example Click_DIGI_POT_TIVA.c
    @example Click_DIGI_POT_CEC.c
    @example Click_DIGI_POT_KINETIS.c
    @example Click_DIGI_POT_MSP.c
    @example Click_DIGI_POT_PIC.c
    @example Click_DIGI_POT_PIC32.c
    @example Click_DIGI_POT_DSPIC.c
    @example Click_DIGI_POT_AVR.c
    @example Click_DIGI_POT_FT90x.c
    @example Click_DIGI_POT_STM.mbas
    @example Click_DIGI_POT_TIVA.mbas
    @example Click_DIGI_POT_CEC.mbas
    @example Click_DIGI_POT_KINETIS.mbas
    @example Click_DIGI_POT_MSP.mbas
    @example Click_DIGI_POT_PIC.mbas
    @example Click_DIGI_POT_PIC32.mbas
    @example Click_DIGI_POT_DSPIC.mbas
    @example Click_DIGI_POT_AVR.mbas
    @example Click_DIGI_POT_FT90x.mbas
    @example Click_DIGI_POT_STM.mpas
    @example Click_DIGI_POT_TIVA.mpas
    @example Click_DIGI_POT_CEC.mpas
    @example Click_DIGI_POT_KINETIS.mpas
    @example Click_DIGI_POT_MSP.mpas
    @example Click_DIGI_POT_PIC.mpas
    @example Click_DIGI_POT_PIC32.mpas
    @example Click_DIGI_POT_DSPIC.mpas
    @example Click_DIGI_POT_AVR.mpas
    @example Click_DIGI_POT_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __digipot_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */