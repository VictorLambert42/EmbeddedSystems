help:
	@echo 'Help details:'
	@echo 'hex: compile hex file'
	@echo 'flash: install hex file'

hex:
	avr-gcc -Os -DF_CPU=1000000 -mmcu=attiny85 -o main.elf main.c
	avr-objcopy -O ihex main.elf main.hex
	#rm led_flash.elf

flash:
	avrdude -c avrisp -p attiny85 -b 19200 -P /dev/ttyACM0 -U flash:w:main.hex

full: hex flash