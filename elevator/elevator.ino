#define LGFX_AUTODETECT
#include <LovyanGFX.hpp>

static LGFX lcd;
static LGFX_Sprite elevator[3](&lcd);
int i =0;
uint32_t fpsCount = 0, fpsSec = 0;

void setup(void){

    lcd.init();
    lcd.setRotation(1);
    lcd.setBrightness(128);
    lcd.setColorDepth(16);

    elevator[0].createSprite(50, 30);
    elevator[0].fillRect(0,10,50,10,0x001F); //BLUE

    elevator[1].createSprite(50, 30);
    elevator[1].fillRect(0,10,50,10,0x07E0); //GREEN

    elevator[2].createSprite(50, 30);
    elevator[2].fillRect(0,10,50,10,0xF800); //RED
}

void loop(){

    while(1){
        lcd.setCursor(0,20);
        lcd.printf("THETA=%d",i);
        elevator[0].pushSprite( 50,120+50*sin((float)DEG_TO_RAD*i));
        elevator[1].pushSprite(150, 80+50*sin((float)DEG_TO_RAD*(i+120)));
        elevator[2].pushSprite(250,120+50*sin((float)DEG_TO_RAD*(i+60)));
        i++;
        if(i==360)i=0;
        //delay(1);

        //Count Frame rate
        fpsCount++;
        if (fpsSec != millis() / 1000) {
            fpsSec = millis() / 1000;
            lcd.setCursor(0,0);
            lcd.printf("FPS:%d\r\n",fpsCount);
            fpsCount = 0;
        }
    }
    
}