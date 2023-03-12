#pragma once
#include <string>
#include <vector>
#include "Game.h"
#include "TextureManage.h" 
#include "Camera.h"
using namespace std;
const int NUMTILESET = 132;
const int NUMTILESETX = 11;
const int NUMTILESETY = 12;
const int NUMMAPX = 64;
const int NUMMAPY = 32;
const int SIZE = 32;
struct tile {
    SDL_Texture* sheet;
    int id;
    // Tọa độ x trong map
    int x;
    // tọa độ y trong map
    int y;
    // tọa độ của x trong sprite sheet
    int tx;
    // tọa độ của y trong sprite sheet
    int ty;
    int width;
    int height;

    tile(SDL_Texture* tset, int _x, int _y,
        int id, int _w = SIZE, int _h = SIZE)
    {
        sheet = tset;
        x = _x;
        y = _y;
        tx = (id % NUMTILESETX == 0) ? (NUMTILESETX - 1) * SIZE : (id % NUMTILESETX - 1) * SIZE;
        ty = (id % NUMTILESETX == 0) ? (id / NUMTILESETX - 1) * SIZE : (id / NUMTILESETX) * SIZE;
        width = _w;
        height = _h;
    }
    void draw(SDL_Renderer* ren)
    {
        if (!ren || !sheet)
            return;

        SDL_Rect src;
        src.x = tx;
        src.y = ty;
        src.w = width;
        src.h = height;

        SDL_Rect dest;
        dest.x = x - Camera::getInstance()->pos.x;
        dest.y = y - Camera::getInstance()->pos.y;
        dest.w = src.w;
        dest.h = src.h;

        SDL_RenderCopy(ren, sheet, &src, &dest);
    }
};
struct layer {
    vector<tile> tiles;
    void load(string mapPath, SDL_Texture* tileSetTex);
    void draw(SDL_Renderer* ren);
};
class level
{
public:vector<layer*> _level;
      void loadLayerToLevel(layer* layer)
      {
          _level.push_back(layer);
      }
      void renderLevel(SDL_Renderer* ren)
      {
          for (int i = 0; i < _level.size(); i++)
          {
              _level[i]->draw(ren);
          }
      }
};

