/*
    __digipot_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__digipot_driver.h"
#include "__digipot_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __DIGIPOT_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _DIGIPOT_VOLATILE_WIPER_0                                  = 0x00;
const uint8_t _DIGIPOT_VOLATILE_WIPER_1                                  = 0x01;
const uint8_t _DIGIPOT_NON_VOLATILE_WIPER_0                              = 0x02;
const uint8_t _DIGIPOT_NON_VOLATILE_WIPER_1                              = 0x03;
const uint8_t _DIGIPOT_VOLATILE_TCON_REGISTER                            = 0x04;
const uint8_t _DIGIPOT_STATUS_REGISTER                                   = 0x05;
const uint8_t _DIGIPOT_DATA_EEPROM_6                                     = 0x06;
const uint8_t _DIGIPOT_DATA_EEPROM_7                                     = 0x07;
const uint8_t _DIGIPOT_DATA_EEPROM_8                                     = 0x08;
const uint8_t _DIGIPOT_DATA_EEPROM_9                                     = 0x09;
const uint8_t _DIGIPOT_DATA_EEPROM_A                                     = 0x0A;
const uint8_t _DIGIPOT_DATA_EEPROM_B                                     = 0x0B;
const uint8_t _DIGIPOT_DATA_EEPROM_C                                     = 0x0C;
const uint8_t _DIGIPOT_DATA_EEPROM_D                                     = 0x0D;
const uint8_t _DIGIPOT_DATA_EEPROM_E                                     = 0x0E;
const uint8_t _DIGIPOT_DATA_EEPROM_F                                     = 0x0F;
const uint8_t _DIGIPOT_DATA_WRITE_CMD                                    = 0x20;

const float _DIGIPOT2_VREF_3V3                                           = 3.30;
const float _DIGIPOT2_VREF_5V                                            = 5.00;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DIGIPOT_DRV_SPI__

void digipot_spiDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(0);
}

#endif
#ifdef   __DIGIPOT_DRV_I2C__

void digipot_i2cDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DIGIPOT_DRV_UART__

void digipot_uartDriverInit(T_DIGIPOT_P gpioObj, T_DIGIPOT_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */



/* Generic write 8-bit data function */
void digipot_writeByte( uint8_t command, uint8_t writeData )
{
    uint8_t buffer[ 2 ];

    buffer[ 0 ] = command;
    buffer[ 1 ] = writeData;

    hal_gpio_csSet( 0 );
    hal_spiWrite( buffer, 2 );
    hal_gpio_csSet( 1 );
}

/* Generic read 8-bit data function */
uint8_t digipot_readByte( uint8_t command )
{
    uint8_t writeCommand[ 1 ];
    uint8_t readData[ 1 ];

    writeCommand[ 0 ] = command;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( readData, writeCommand,  1 );
    hal_gpio_csSet( 1 );
    
    return readData[ 0 ];
}

/* Read status register data function */
uint8_t digipot_readStatus()
{
    uint8_t result;
    
    result = digipot_readByte( _DIGIPOT_STATUS_REGISTER );

    return result;
}

/* Set 8-bit wiper positions */
void digipot_setWiperPositions( uint8_t wiperPositions )
{
    uint8_t buffer[ 4 ];

    buffer[ 0 ] = _DIGIPOT_VOLATILE_WIPER_0;
    buffer[ 1 ] = wiperPositions;
    buffer[ 2 ] = _DIGIPOT_DATA_WRITE_CMD;
    buffer[ 3 ] = wiperPositions;

    hal_gpio_csSet( 0 );
    Delay_100ms();
    hal_spiWrite( buffer, 4 );
    hal_gpio_csSet( 1 );
}

/* Convert ADC value to volatage */
float digipot_convertOutput( uint8_t valueADC, float vRef )
{
    float result;

    result = ( ( float ) valueADC * vRef ) / 255.00;

    return result;
}



/* -------------------------------------------------------------------------- */
/*
  __digipot_driver.c

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