#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spiffs.h"

#include "st7789.h"
#include "fontx.h"
#include "pngle.h"
#include "decode_png.h"

#include "Engine.h"

#include "../files/image.h"

//--class Person--//
typedef struct person
{
    RenderObject *mRenderObject;
    int attack;
    int HP;
    int oriX;
    int oriY;

    void (*move)(struct person*);
}Person;

void personMove(Person* obj)
{
    //Parameters of the image and screen, DON'T MODIFY THEM!
    uint16_t imageWidth = 50;
    uint16_t imageHeight = 50;
    uint16_t screenWidth = 320;
    uint16_t screenHeight = 240;
    //Parameters you can use AND MODIFY: posX, posY, oriX, oriY
    uint16_t posX = obj->mRenderObject->getPosX(obj->mRenderObject);
    uint16_t posY = obj->mRenderObject->getPosY(obj->mRenderObject);
    int16_t oriX = obj->oriX;
    int16_t oriY = obj->oriY;

    //TO-DO: let the object move 5 pixels on both dimensions
    //      and bounce back when it hits the edge
    if(???) //Control statement (check if the object goes out of screen (x-axis) in next frame)
    {
        ??? //Change oriX accordingly
    }
    if(???) //Control statement (check if the object goes out of screen (y-axis) in next frame)
    {
        ??? //Change oriY accordingly
    }
    posX += 5 * oriX; //Moves 5 pixels (x-axis), whose direction is determined by oriX
    posY += 5 * oriY; //Moves 5 pixels (y-axis), whose direction is determined by oriX
    //TO-DO ends

    printf("posX: %d, posY: %d, oriX: %d, oriY: %d\n", posX, posY, oriX, oriY);
    obj->mRenderObject->setPos(obj->mRenderObject, posX, posY);
    obj->oriX = oriX;
    obj->oriY = oriY;
}

void newPerson(Person* obj, Engine* engine, int16_t posX, int16_t posY)
{
    obj->move = personMove;
    obj->oriX = 1;
    obj->oriY = 1;
    obj->attack = 10;
    obj->HP = 100;
    obj->mRenderObject = Engine_Render_newObject(engine, "person", posX, posY, 1);
}

void deletePerson(Person* obj, Engine* engine)
{
    Engine_Render_deleteObject(engine, obj->mRenderObject);
}
//----//

//--Declare Managers and objects--//
extern const uint16_t people[];

Engine* gEngine;

Person John;
//----//

//--Init Function--//
void init()
{   
    gEngine = newEngine();
    Engine_Render_addImage(gEngine, "person", people, 50, 50);
}
//----//

void app_main(void)
{   
    init();

    newPerson(&John, gEngine, 0, 0);
    Engine_Render_addObject(gEngine, John.mRenderObject);
    
    while(1)
    {
        John.move(&John);
        Engine_Render_render(gEngine, John.mRenderObject);
        Engine_Render_update(gEngine);
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}
