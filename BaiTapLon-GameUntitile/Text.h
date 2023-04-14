#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;
class Text
{
public: 
       string str;
       SDL_Texture* tex;
       int width = 200; int height = 200;
       int _x; int _y;
       SDL_Rect rect;
       void setText(const string& text) { str = text; }

       bool loadRenderText(TTF_Font* font, SDL_Renderer* ren , SDL_Color color = { 255,255,255 } )
       {
           SDL_Surface* textSurface = TTF_RenderText_Solid(font, str.c_str(), color);
           if (textSurface)
           {
               tex = SDL_CreateTextureFromSurface(ren, textSurface);
               width = textSurface->w;
               height = textSurface->h;
               rect.w = textSurface->w;
               rect.h = textSurface->h;
               SDL_FreeSurface(textSurface);
           }
           return tex != NULL;
       }
       void setRectPos(int x, int y)
       {
           rect.x = x;
           rect.y = y;

           _x = x;
           _y = y;
       }

       void Free()
       {
           if (tex != NULL)
           {
               SDL_DestroyTexture(tex);
               tex = NULL;
           }
       }

       void renderText(SDL_Renderer* ren, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0, SDL_Rect* clip = NULL, SDL_Point* center = NULL)
       {
           SDL_Rect renderQuad = { _x , _y , width , height };
           if (clip != NULL)
           {
               renderQuad.w = clip->w;
               renderQuad.h = clip->h;
           }

           SDL_RenderCopyEx(ren, tex, clip, &renderQuad, angle, center, flip);
       }
       
};