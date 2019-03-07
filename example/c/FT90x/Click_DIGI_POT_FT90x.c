/*
Example for DIGI_POT Click

    Date          : Oct 2018.
    Author        : Nenad Filipovic

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.3.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, SPI and LOG structures, set CS pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of DIGI POT Click board.
     Increments the wiper position by 10 position every 3 seconds.
     Calculate ADC voltage and write log UART.
     All data logs on usb uart for aproximetly every 3 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_DIGI_POT_types.h"
#include "Click_DIGI_POT_config.h"



uint16_t counter;
uint8_t adcValue;
float adcVoltage;
char logText[50];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_DIGIPOT_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_100ms();
}

void applicationInit()
{
     digipot_spiDriverInit( (T_DIGIPOT_P)&_MIKROBUS1_GPIO, (T_DIGIPOT_P)&_MIKROBUS1_SPI );
     mikrobus_logWrite( "      DIGI POT Click", _LOG_LINE );
     mikrobus_logWrite( "--------------------------", _LOG_LINE );
     Delay_100ms();
}

void applicationTask()
{
    for ( counter = 100; counter < 256; counter += 10 )
    {
        digipot_setWiperPositions( counter );
        Delay_1sec();

        adcValue = digipot_readByte( _DIGIPOT_STATUS_REGISTER );
        Delay_1sec();
        
        adcVoltage = digipot_convertOutput( adcValue, _DIGIPOT2_VREF_3V3 );

        mikrobus_logWrite( " ADC Voltage:  ", _LOG_TEXT );
        FloatToStr( adcVoltage, logText );
        ltrim( logText );
        mikrobus_logWrite( logText, _LOG_TEXT );
        mikrobus_logWrite( " V", _LOG_LINE );
        mikrobus_logWrite( "", _LOG_LINE );

        Delay_1sec();
        Delay_1sec();
        Delay_1sec();
    }

    mikrobus_logWrite( "--------------------------", _LOG_LINE );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}