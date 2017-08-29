/*
  One MAX7219 connected to an 8x8 LED matrix.
 */

#include <avr/io.h>
#include <util/delay.h>

#define CLK_HIGH()  PORTB |= (1<<PB2)
#define CLK_LOW()   PORTB &= ~(1<<PB2)
#define CS_HIGH()   PORTB |= (1<<PB1)
#define CS_LOW()    PORTB &= ~(1<<PB1)
#define DATA_HIGH() PORTB |= (1<<PB0)
#define DATA_LOW()  PORTB &= ~(1<<PB0)
#define INIT_PORT() DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2)

const __flash uint8_t smile[8] = {
        0b00000000,
        0b01100110,
        0b01100110,
        0b00011000,
        0b00011000,
        0b10000001,
        0b01000010,
        0b00111100};

const __flash uint8_t sad[8] = {
        0b00000000,
        0b01100110,
        0b01100110,
        0b00011000,
        0b00011000,
        0b00000000,
        0b00111100,
        0b01000010,
};


void spi_send(uint8_t data)
{
    uint8_t i;

    for (i = 0; i < 8; i++, data <<= 1)
    {
	CLK_LOW();
	if (data & 0x80)
	    DATA_HIGH();
	else
	    DATA_LOW();
	CLK_HIGH();
    }
    
}

void max7219_writec(uint8_t high_byte, uint8_t low_byte)
{
    CS_LOW();
    spi_send(high_byte);
    spi_send(low_byte);
    CS_HIGH();
}

void max7219_clear(void)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
	max7219_writec(i+1, 0);
    }
}

void max7219_init(void)
{
    INIT_PORT();
    // Decode mode: none
    max7219_writec(0x09, 0);
    // Intensity: 3 (0-15)
    max7219_writec(0x0A, 1);
    // Scan limit: All "digits" (rows) on
    max7219_writec(0x0B, 7);
    // Shutdown register: Display on
    max7219_writec(0x0C, 1);
    // Display test: off
    max7219_writec(0x0F, 0);
    max7219_clear();
}


uint8_t display[8];

void update_display(void)
{
    uint8_t i;

    for (i = 0; i < 8; i++)
    {
	max7219_writec(i+1, display[i]);
    }
}

void image(const __flash uint8_t im[8])
{
    uint8_t i;

    for (i = 0; i < 8; i++)
	display[i] = im[i];
}

void set_pixel(uint8_t r, uint8_t c, uint8_t value)
{
    switch (value)
    {
    case 0: // Clear bit
	display[r] &= (uint8_t) ~(0x80 >> c);
	break;
    case 1: // Set bit
	display[r] |= (0x80 >> c);
	break;
    default: // XOR bit
	display[r] ^= (0x80 >> c);
	break;
    }
}


int main(void)
{
    uint8_t i;
    
    max7219_init();
    
    while(1)
    {
	image(sad);
	update_display();
	_delay_ms(500);
	image(smile);
	update_display();
	_delay_ms(500);

	// Invert display
	for (i = 0 ; i < 8*8; i++)
	{
	    set_pixel(i / 8, i % 8, 2);
	    update_display();
	    _delay_ms(10);
	}
	_delay_ms(500);
    }
}