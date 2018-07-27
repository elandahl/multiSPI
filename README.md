# multiSPI
Multiple SPI Devices on a Raspberry Pi

## Description:

Circuit diagram and software to use multiple (> 2) SPI devices on a Raspberry Pi.  This approach uses a shift register to address a demultiplexer which in turn routes up to eight chip selects.  All devices share the same MISO, MOSI, and SCLK.  The Raspberry Pi chip select CE0 is used for SPI communication to the selected device, whereas chip select CE1 is used for latching the shift register.  The particular SPI devices used in this design for demonstration purposes are four 10 bit, 4 differential channel MCP3008 Analog-to-Digital Converters.  Differential voltage measurement is implemented, although the 4 differential measurements could be replaced with eight single inputs.  Another four SPI devices could be added, and this could be further extended with a second demultiplexer to 16 devices.  An additional shft register could be added after the first for essentially unlimited extension to arbitrary numbers of SPI devices.  This same approach could be extended to other platforms such as a microcontroller.

## Author:

Eric Landahl, elandahl@gmail.com

## Acknowledgements:

Motivation from C.D. Landahl

Concept from Ellie Martin-Eberhardt

Requires use of the [C library for Broadcom BCM 2835 as used in Raspberry Pi](http://www.airspayce.com/mikem/bcm2835/index.html) by Mike McCauley.  The code here is based closely on the bcm2835 example file `spin.c`.
