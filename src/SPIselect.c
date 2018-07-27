// SPIselect.c
//
// By Eric Landahl, 7/25/2018
// Program to select a particular SPI device using a shift register and DeMux
// Note that the Shift Register Chip Select should be connected to CE1
// And the DeMux should be connected to CE0
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o SPIselect SPIselect.c -l bcm2835
// sudo ./SPIselect 2
// where in this case 2 is the device number, currently 0 - F
//
// Adapted from spin.c by Mike McCauley
// See http://www.airspayce.com/mikem/bcm2835/index.html  
// Copyright (C) 2012 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include <bcm2835.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
// Use for testing
//        bcm2835_set_debug(1);
    
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }

    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failed. Are you running as root??\n");
      return 1;
    }
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS1);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);      // the default
    
    // Send a some bytes to the slave and simultaneously read 
    // some bytes back from the slave
    // Most SPI devices expect one or 2 bytes of command, after which they will send back
    // some data. In such a case you will have the command bytes first in the buffer,
    // followed by as many 0 bytes as you expect returned data bytes. After the transfer, you 
    // Can the read the reply bytes from the buffer.
    // If you tie MISO to MOSI, you should read back what was sent.

    // Select channel 0
    if( *argv[1] == '0' )
    {
      char buf[]={ 0x00 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 0 has been selected\n");
    }

    // Select channel 1
    if( *argv[1] == '1' )
    {
      char buf[]={ 0x01 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 1 has been selected\n");
    }

    // Select channel 2
    if( *argv[1] == '2' )
    {
      char buf[]={ 0x02 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 2 has been selected\n");
     }

    // Select channel 3
    if( *argv[1] == '3' )
    {
      char buf[]={ 0x03 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 3 has been selected\n");
     }

    // Select channel 4
    if( *argv[1] == '4' )
    {
      char buf[]={ 0x04 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 4 has been selected\n");
     }

    // Select channel 5
    if( *argv[1] == '5' )
    {
      char buf[]={ 0x05 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 5 has been selected\n");
     }

    // Select channel 6
    if( *argv[1] == '6' )
    {
      char buf[]={ 0x06 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 6 has been selected\n");
     }

    // Select channel 7
    if( *argv[1] == '7' )
    {
      char buf[]={ 0x07 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 7 has been selected\n");
     }

    // Select channel 9
    if( *argv[1] == '8' )
    {
      char buf[]={ 0x08 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 8 has been selected\n");
     }

    // Select channel 9
    if( *argv[1] == '9' )
    {
      char buf[]={ 0x09 };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 9 has been selected\n");
     }

    // Select channel 10
    if( *argv[1] == 'A' )
    {
      char buf[]={ 0x0A };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 10 has been selected\n");
     }

    // Select channel 11
    if( *argv[1] == 'B' )
    {
      char buf[]={ 0x0B };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 11 has been selected\n");
     }

    // Select channel 12
    if( *argv[1] == 'C' )
    {
      char buf[]={ 0x0C };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 12 has been selected\n");
     }

    // Select channel 13
    if( *argv[1] == 'D' )
    {
      char buf[]={ 0x0D };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 13 has been selected\n");
     }

    // Select channel 14
    if( *argv[1] == 'E' )
    {
      char buf[]={ 0x0E };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 14 has been selected\n");
     }

    // Select channel 15
    if( *argv[1] == 'F' )
    {
      char buf[]={ 0x0F };
      bcm2835_spi_transfern(buf, 1);
      printf("Device 15 has been selected\n");
     }

    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

