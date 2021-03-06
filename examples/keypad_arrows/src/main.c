/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
 
/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CE Keypad C Library */
#include <libs/keypadc.h>

/* Some LCD defines */
void fillScreen(uint8_t color);

/* Main Function */
void main(void) {
    /* Key varaible */
    kb_key_t key;
    
    /* Loop until 2nd is pressed */
    do {
		/* Update kb_Data */
		kb_Scan();
		
		/* Load group 7 registers */
        key = kb_Data[kb_group_7];
        
        switch(key) {
            case kb_Down:           /* Change screen color to black */
                fillScreen(0x00);
                break;
            case kb_Right:          /* Change screen color to red */
                fillScreen(0xE0);
                break;
            case kb_Up:             /* Change screen color to white */
                fillScreen(0xFF);
                break;
            case kb_Left:           /* Change screen color to a different red */
                fillScreen(0xC0);
                break;
            default:
                break;
        }
    } while( kb_Data[kb_group_1] != kb_2nd );
	
    prgm_CleanUp();
}

/* Simple way to fill the screen with a given color */
void fillScreen(uint8_t color) {
    memset_fast(lcd_Ram, color, LCD_SIZE);
}
