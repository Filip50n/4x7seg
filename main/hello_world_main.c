/*  Ponizszy porgram obsluguje wyswietlacz 4 x 7 SEG poprzez płytkę ESP 32 wykorzystujac do tego piny 18,12,14,27,19,21,3,1,22,23,13
 * 	poprzez podanie wysokiego napięcia na piny odpowiadajace za ledy mozliwe jest ich zapalenia
 * 	natomiast poprzez podanie niskiego napiecia na dany segment mozliwe jest jego uaktywnienie
 * 	do zbudowania takiego ukladu wykorzystujemy 4 tranzystry bipolarne "BC 557C", 7 rezystorow 240 omow i 4 rezystory 2,2k oma
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "freertos/queue.h"

//Pins
//Pin 18 - SEGMENT 1
//Pin 12 - SEGMENT 2
//Pin 14 - SEGMENT 3
//Pin 27 - SEGMENT 4
//Pin 19 - LED A
//Pin 21 - LED B
//Pin 3  - LED C
//Pin 1  - LED D
//Pin 22 - LED E
//Pin 23 - LED F
//Pin 13 - LED G


#define SEG1    18
#define LEDA    19
#define LEDB    21
#define LEDC    3
#define LEDD    1
#define LEDE    22
#define LEDF    23
#define LEDG    13
#define SEG2    12
#define SEG3    14
#define SEG4    27

//#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<SEG1) | (1ULL<<SEG2)|(1ULL<<SEG3) | (1ULL<<SEG4)|(1ULL<<LED1) | (1ULL<<LED2)|(1ULL<<LED3) | (1ULL<<LED4) | (1ULL<<LED5)  | (1ULL<<LED6)|(1ULL<<LED7) | (1ULL<<LED8))
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<SEG1)|(1ULL<<LEDA)|(1ULL<<LEDB)|(1ULL<<LEDC)|(1ULL<<LEDD)|(1ULL<<LEDE)|(1ULL<<LEDF)|(1ULL<<LEDG)|(1ULL<<SEG2)|(1ULL<<SEG3)|(1ULL<<SEG4))


void app_main(void)
{
	gpio_config_t io_conf = {};
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	gpio_config(&io_conf);
	int czas=0;
	int sek = 2;


	while(1){

	if(sek == 1){
		//for(int i = 0 ; i<=10 ; i++){
	if(czas == 6){
		czas = 0;
	}
    printf("Hello world!\n");
    printf("ODPALAM SWIATLA!\n");
    gpio_set_level(SEG1, 0);
    gpio_set_level(SEG2, 0);
    gpio_set_level(SEG3, 0);
    gpio_set_level(SEG4, 0);
    	if(czas % 6 == 0){
    		gpio_set_level(LEDA, 1);
    		gpio_set_level(LEDB, 0);
    		gpio_set_level(LEDC, 0);
    		gpio_set_level(LEDD, 0);
    		gpio_set_level(LEDE, 0);
    		gpio_set_level(LEDF, 0);
    	}else if (czas % 6 == 1){
    		gpio_set_level(LEDA, 0);
    		gpio_set_level(LEDB, 1);
    		gpio_set_level(LEDC, 0);
    		gpio_set_level(LEDD, 0);
    		gpio_set_level(LEDE, 0);
    		gpio_set_level(LEDF, 0);
    	}else if (czas % 6 == 2){
    		gpio_set_level(LEDA, 0);
    		gpio_set_level(LEDB, 0);
    		gpio_set_level(LEDC, 1);
    		gpio_set_level(LEDD, 0);
    		gpio_set_level(LEDE, 0);
    		gpio_set_level(LEDF, 0);
    	}else if (czas % 6 == 3){
    		gpio_set_level(LEDA, 0);
    		gpio_set_level(LEDB, 0);
    		gpio_set_level(LEDC, 0);
    		gpio_set_level(LEDD, 1);
    		gpio_set_level(LEDE, 0);
    		gpio_set_level(LEDF, 0);
    	}else if (czas % 6 == 4){
    		gpio_set_level(LEDA, 0);
    		gpio_set_level(LEDB, 0);
    		gpio_set_level(LEDC, 0);
    		gpio_set_level(LEDD, 0);
    		gpio_set_level(LEDE, 1);
    		gpio_set_level(LEDF, 0);
    	}else if (czas % 6 == 5){
    		gpio_set_level(LEDA, 0);
    		gpio_set_level(LEDB, 0);
    		gpio_set_level(LEDC, 0);
    		gpio_set_level(LEDD, 0);
    		gpio_set_level(LEDE, 0);
    		gpio_set_level(LEDF, 1);
    	}

        vTaskDelay(200 / portTICK_PERIOD_MS);
        czas++;
		//}
		}else if(sek == 2){
			gpio_set_level(SEG1, 0);
			gpio_set_level(SEG2, 1);
			gpio_set_level(SEG3, 1);
			gpio_set_level(SEG4, 1);

			gpio_set_level(LEDA, 1);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 1);
			gpio_set_level(LEDE, 1);
			gpio_set_level(LEDF, 1);
			gpio_set_level(LEDG, 1);

			gpio_set_level(LEDA, 0);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 0);
			gpio_set_level(LEDE, 0);
			gpio_set_level(LEDF, 0);
			gpio_set_level(LEDG, 0);

			gpio_set_level(SEG1, 1);
			gpio_set_level(SEG2, 0);
			gpio_set_level(SEG3, 1);
			gpio_set_level(SEG4, 1);

			gpio_set_level(LEDA, 0);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 1);
			gpio_set_level(LEDE, 1);
			gpio_set_level(LEDF, 1);
			gpio_set_level(LEDG, 0);

			gpio_set_level(LEDA, 0);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 0);
			gpio_set_level(LEDE, 0);
			gpio_set_level(LEDF, 0);
			gpio_set_level(LEDG, 0);


			gpio_set_level(SEG1, 1);
			gpio_set_level(SEG2, 1);
			gpio_set_level(SEG3, 0);
			gpio_set_level(SEG4, 1);

			gpio_set_level(LEDA, 1);
			gpio_set_level(LEDB, 1);
			gpio_set_level(LEDC, 1);
			gpio_set_level(LEDD, 1);
			gpio_set_level(LEDE, 1);
			gpio_set_level(LEDF, 1);
			gpio_set_level(LEDG, 0);

			gpio_set_level(LEDA, 0);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 0);
			gpio_set_level(LEDE, 0);
			gpio_set_level(LEDF, 0);
			gpio_set_level(LEDG, 0);

			gpio_set_level(SEG1, 1);
			gpio_set_level(SEG2, 1);
			gpio_set_level(SEG3, 1);
			gpio_set_level(SEG4, 0);

			gpio_set_level(LEDA, 1);
			gpio_set_level(LEDB, 1);
			gpio_set_level(LEDC, 1);
			gpio_set_level(LEDD, 1);
			gpio_set_level(LEDE, 1);
			gpio_set_level(LEDF, 1);
			gpio_set_level(LEDG, 0);

			gpio_set_level(LEDA, 0);
			gpio_set_level(LEDB, 0);
			gpio_set_level(LEDC, 0);
			gpio_set_level(LEDD, 0);
			gpio_set_level(LEDE, 0);
			gpio_set_level(LEDF, 0);
			gpio_set_level(LEDG, 0);

			vTaskDelay(5 / portTICK_PERIOD_MS);

		}

	}
    //esp_restart();
}
