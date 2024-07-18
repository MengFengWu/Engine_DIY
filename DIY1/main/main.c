#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spiffs.h"

#include "Engine.h"

#include "../files/image.h"

//--Declare Managers and objects--//
extern const uint16_t people[];

Engine* gEngine;
RenderObject *mRenderObject;
//----//

//--Init Function--//
void init()
{   
    gEngine = newEngine();
    Engine_Render_addImage(gEngine, "image", image, 100, 50);
    mRenderObject = Engine_Render_newObject(gEngine, "image", 100, 100, 1);
    Engine_Render_addObject(gEngine, mRenderObject);
    Engine_Render_update(gEngine);
}
//----//

void app_main(void)
{   
    init();
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
    while(1)
    {
        mRenderObject->setPos(mRenderObject, 150, 125);
        Engine_Render_render(gEngine, mRenderObject);
        Engine_Render_update(gEngine);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        mRenderObject->setPos(mRenderObject, 100, 100);
        Engine_Render_render(gEngine, mRenderObject);
        Engine_Render_update(gEngine);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
