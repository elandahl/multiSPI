# Directory of source files for multiSPI
## Installation
1. Obtain and install the [bcm2835 library](http://www.airspayce.com/mikem/bcm2835/index.html)
2. Download `MCP3008read.c` and compile with the command `gcc -o MCP3008read MCP3008read.c -l bcm2835`
3. Download `SPIselect.c` and compile with the command `gcc -o SPIselect SPIselect.c -l bcm2835`
## Usage
To select an SPI device:  `sudo ./SPIselect` *num*
  
where *num* is the address 0 - F

For instance, `sudo ./SPIselect 1` should return the statement `Device 1 has been selected`.

To read 4 differential voltages of the selected MCP3008 ADC:  `./MCP3008read`

This will return the hexadecimal readings for each differential pair; see MCP3008 datasheet for details on how to convert this output to a voltage.

Note that the use of `sudo` may not be required in more recent versions of Raspbian. Also note that depending on the Raspbian version, the SPI may need to be configured using `sudo raspi-config`.  
