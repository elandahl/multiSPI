// MCP3008read.c
//
// By Eric Landahl, 7/25/2018
// Program to read all 4 differential channels of the MCP3008 12-bit ADC
// Note that the Chip Select should be connected to CE0
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o MCP3008read MCP3008read.c -l bcm2835
// sudo ./MCP3008read
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
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default is 65536
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
    
    // Send a some bytes to the slave and simultaneously read 
    // some bytes back from the slave
    // Most SPI devices expect one or 2 bytes of command, after which they will send back
    // some data. In such a case you will have the command bytes first in the buffer,
    // followed by as many 0 bytes as you expect returned data bytes. After the transfer, you 
    // Can the read the reply bytes from the buffer.
    // If you tie MISO to MOSI, you should read back what was sent.

    // Channel 0 = IN+, Channel 1 = IN-    
    char buf0[] = { 0x01, 0x00, 0x00}; // Data to send
    bcm2835_spi_transfern(buf0, sizeof(buf0));
    // buf will now be filled with the data that was read from the slave
    printf("Ch 0 - Ch 1:  %02X  %02X  %02X  \n", buf0[0], buf0[1], buf0[2]);

    // Channel 2 = IN+, Channel 3 = IN-    
    char buf2[] = { 0x01, 0x20, 0x00}; // Data to send
    bcm2835_spi_transfern(buf2, sizeof(buf2));
    printf("Ch 2 - Ch 3:  %02X  %02X  %02X  \n", buf2[0], buf2[1], buf2[2]);

    // Channel 4 = IN+, Channel 5 = IN-    
    char buf4[] = { 0x01, 0x40, 0x00}; // Data to send
    bcm2835_spi_transfern(buf4, sizeof(buf4));
    printf("Ch 4 - Ch 5:  %02X  %02X  %02X  \n", buf4[0], buf4[1], buf4[2]);

    // Channel 6 = IN+, Channel 7 = IN-    
    char buf6[] = { 0x01, 0x60, 0x00}; // Data to send
    bcm2835_spi_transfern(buf6, sizeof(buf6));
    printf("Ch 6 - Ch 7:  %02X  %02X  %02X  \n", buf6[0], buf6[1], buf6[2]);

    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

