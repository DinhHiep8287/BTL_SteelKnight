#include "TextureManage.h"
#include "Game.h"

TextureManage* TextureManage::_instance = nullptr;

bool TextureManage::load(string id, string fileName)
{
    SDL_Surface* surface = IMG_Load(fileName.c_str());
    if (surface == nullptr)
    {
        SDL_Log(" Fail to load Texture : ", fileName.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetInstance()->renderer, surface);
    if (texture == nullptr)
    {
        SDL_Log(" Fail to load Texture from surface : " , SDL_GetError());
    }

    _textureMap[id] = texture;
    return true;
}

void TextureManage::drop(string id)
{
    SDL_DestroyTexture(_textureMap[id]);
    _textureMap.erase(id);
}

void TextureManage::clean()
{
    map<string, SDL_Texture*>::iterator it;
    for (it = _textureMap.begin(); it != _textureMap.end(); it++)
    {
        SDL_DestroyTexture(it->second);
    }
    _textureMap.clear();
}

void TextureManage::draw(string id, float x, float y, float width, float height, SDL_RendererFlip flip)
{
    SDL_Rect srcrect = { 0 , 0 , width , height };
    SDL_Rect dstrect = { x , y , width , height };
    SDL_RenderCopyEx(Game::GetInstance()->renderer, _textureMap[id], &srcrect, &dstrect, 0, NULL, flip);
}

void TextureManage::drawFrame(string id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip)
{
        // Tọa độ của 1 source frame sẽ được xác định bởi x = Chiều Dài 1 frame * thứ tự frame ; y = Chiều cao 1 frame * thứ tự cột
        SDL_Rect srcrect = { width * frame , height * row , width , height };
        SDL_Rect dstrect = { x , y , width , height };
        SDL_RenderCopyEx(Game::GetInstance()->renderer, _textureMap[id], &srcrect, &dstrect, 0, NULL, flip);
}

