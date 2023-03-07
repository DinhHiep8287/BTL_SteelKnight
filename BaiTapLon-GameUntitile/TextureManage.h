#pragma once
#include "Engine.h"
#include <map>
class TextureManage
{
public: 
    TextureManage(){}
    static TextureManage* _instance;
    map<string, SDL_Texture*> _textureMap;


    static TextureManage* GetInstance() {
        return _instance = (_instance != nullptr) ? _instance : new TextureManage();
    }
    bool load(string id, string fileName);
    void drop(string id);
    void clean();
    void draw(string id, float x, float y, float width, float height, SDL_RendererFlip flip);
    // Vẽ từng khung hình của một Sprite 
    void drawFrame(string id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip);
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
};

