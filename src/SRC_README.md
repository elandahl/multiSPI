# Directory of source files for multiSPI
## Installation instructions
1. bcm2835 library
2. multiSPI
## Usage
To select an SPI device:  `./SPIselect` *num*
  
where *num* is the address 0 - F

For instance, `./SPIselect 1` should return the statement `Device 1 has been selected`.

To read 4 differential voltages of the selected MCP3008 ADC:  `./MCP3008read`

This will return the hexadecimal readings for each differential pair; see MCP3008 datasheet for details on how to convert this output to a voltage.
