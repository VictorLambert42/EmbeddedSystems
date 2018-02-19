# ATTiny85

## Compile main.c
avr-gcc -Os -DF_CPU=1000000 -mmcu=attiny85 -o main.elf main.c

## Copy main.elf as hex file
avr-objcopy -O ihex main.elf main.hex

## Copy the .hex file on the ATTiny85
avrdude -c avrisp -p attiny85 -b 19200 -P /dev/ttyACM0 -U flash:w:main.hex