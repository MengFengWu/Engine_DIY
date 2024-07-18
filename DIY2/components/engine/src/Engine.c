#include "Engine.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

Engine* newEngine()
{
    Engine *engine = calloc(1, sizeof(Engine));
    engine->ResourceManager = newResourceManager();
    engine->RenderManager = newRenderManager();
    return engine;
}

void deleteEngine(Engine *engine)
{
    deleteResourceManager(engine->ResourceManager);
    deleteRenderManager(engine->RenderManager);
    free(engine);
}

RenderResource* Engine_Render_findRenderResourceByID(Engine *engine, uint8_t ID)
{
    return renderManagerFindRenderResourceByID(engine->RenderManager, ID);
} 

RenderResource* Engine_Render_findRenderResourceByName(Engine *engine, char name[])
{
    return renderManagerFindRenderResourceByName(engine->RenderManager, name);
}

void Engine_Render_addImage(Engine *engine, char name[], uint16_t* image, uint16_t width, uint16_t height)
{
    renderManagerAddImage(engine->RenderManager, engine->ResourceManager, name, image, width, height);
}

RenderObject* Engine_Render_newObject(Engine *engine, char name[], int16_t posX, int16_t posY, uint8_t visible)
{
    RenderObject* renderObject = calloc(1, sizeof(RenderObject));
    renderObjectNew(renderObject, Engine_Render_findRenderResourceByName(engine, name), posX, posY, visible);
    return renderObject;
}

void Engine_Render_deleteObject(Engine *engine, RenderObject* renderObject)
{
    if(renderObject != NULL) free(renderObject);
}

void Engine_Render_addObject(Engine *engine, RenderObject* renderObject)
{
    renderManagerAddObject(engine->RenderManager, renderObject);  
}

void Engine_Render_removeObject(Engine *engine, RenderObject* renderObject)
{
    renderManagerRemoveObject(engine->RenderManager, renderObject);  
}

void Engine_Render_render(Engine *engine, RenderObject* renderObject)
{
    renderManagerReRender(engine->RenderManager, renderObject);
}

void Engine_Render_clear(Engine *engine)
{
    renderManagerClear(engine->RenderManager);
}

void Engine_Render_update(Engine *engine)
{
    renderManagerUpdate(engine->RenderManager);
}