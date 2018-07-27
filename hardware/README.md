# Hardware design files for multiSPI test board

## Contents
Schematic only so far, prepared in EAGLE 9.1.0, and using DIP format comonents

Available as .png, .pdf, and EAGLE .sch files

PCB files are under preparation

## Hardware used for tests

1. Raspberry Pi Model 3B running Raspbian GNU/Linux 8.0 (jessie)
2. Canakit cobbler breakout 
3. Full size solderless breadboard
4. Shift Register: SN74HC595N
5. Demultiplexer: T74LS138B1
6. ADC (QTY = 2 tested, QTY = 4 in circuit diagram): MCP3008
7. Pullup resistors on multi-chip select lines: (QTY = 2 or 4) approximately 100 kOhm

## Notes
Pin 13 on the 74595 is labeled as "G" on the schematic but appears instead as "~OE" on most datasheets, for "complimentary output enable".  It should be connected to GND for this application.
