#pragma once
#include <SDL_image.h>
#include <map>
#include "Camera.h"
#include "Game.h"
class TextureManage
{
public: 
    static TextureManage* _instance;
    map<string, SDL_Texture*> _textureMap;
    static TextureManage* GetInstance() {
        return _instance = (_instance != nullptr) ? _instance : new TextureManage ;
    }
    bool load(string id, string fileName);
    void drop(string id);
    void clean();
    // vẽ 1 frame 
    void draw(string id, float x, float y, float width, float height, SDL_RendererFlip flip , float paralaxSpeed);
    // Vẽ từng khung hình của một Sprite 
    void drawFrame(string id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip );

    void loadTextureFromSurface(string id, SDL_Surface* surface);
    
    float textureWidth(string id)
    {
        SDL_Texture* texture = _textureMap[id];
        SDL_Rect rect1;
        SDL_QueryTexture(texture, NULL, NULL, &rect1.w, &rect1.h);
        return rect1.w;
    }
    float textureHeight(string id)
    {
        SDL_Texture* texture = _textureMap[id];
        SDL_Rect rect1;
        SDL_QueryTexture(texture, NULL, NULL, &rect1.w, &rect1.h);
        return rect1.h;
    }
    SDL_Texture* load_texture(string path);

    void drawHitbox(SDL_Rect* hitbox, SDL_Renderer* ren)
    {
        SDL_Rect tempRect = { hitbox->x - Camera::getInstance()->pos.x , hitbox->y - Camera::getInstance()->pos.y , hitbox->w , hitbox->h };
        SDL_RenderDrawRect(ren, &tempRect);
    }

};

