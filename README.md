![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DIGI_POT Click

---

- **CIC Prefix**  : DIGIPOT
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Oct 2018.

---

### Software Support

We provide a library for the DIGI_POT Click on our [LibStock](https://libstock.mikroe.com/projects/view/200/digipot-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control DIGI POT Click board. 
Library performs the communication with the device via SPI driver by writting to registers and reading from register.
The library set 8-bit ( 256 ) wiper positions value, reading status register and 
convert to volatage 0V - 3.3V  or  0V - 5.0V.

Key functions :

- ``` void digipot_writeByte( uint8_t command, uint8_t writeData ) ``` - Generic write 8-bit data function
- ``` uint8_t digipot_readByte( uint8_t command ) ``` - Generic read 8-bit data function
- ``` void digipot_setWiperPositions( uint8_t wiperPositions ) ``` - Set 8-bit wiper positions

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, SPI and LOG structures, set CS pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of DIGI POT Click board.
     Increments the wiper position by 10 position every 3 seconds.
     Calculate ADC voltage and write log UART.
     All data logs on usb uart for aproximetly every 3 sec.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/200/digipot-click-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
