#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Game.h"
#include "Camera.h"
using namespace std;
const int NUMMAPX = 128;
const int NUMMAPY = 28;
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
        int id, int NUMTILESETX , int NUMTILESETY ,  int _w = SIZE, int _h = SIZE)
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
    void load(string path, SDL_Texture* tileSetTex, int NumTileSetX, int NumTileSetY, int firstId)
    {
        {
            ifstream _map(path);
            for (int i = 0; i < NUMMAPX * NUMMAPY; i++)
            {
                int id = 0;
                int x = (i % NUMMAPX) * SIZE;
                int y = (i / NUMMAPX) * SIZE;
                _map >> id;
                id = id - firstId + 1;
                tile tempTile(tileSetTex, x, y, id, NumTileSetX, NumTileSetY);
                tiles.push_back(tempTile);
            }
        }
    }
    void draw(SDL_Renderer* ren)
    {
        /*int right  = ((hitbox._hitBox.x + screenWidth / 2) / 32 <= 128)
        (hitbox._hitBox.x - screenWidth / 2) / 32;
        (hitbox._hitBox.y + screenHeight / 2) / 32;
        (hitbox._hitBox.y - screenHeight / 2) / 32;*/

        for (int i = 0; i < tiles.size(); i++) {
            tiles[i].draw(ren);
        }
    }
};
class level
{
public:vector<layer*> _layers;
      void loadLayerToLevel(layer* layer)
      {
          _layers.push_back(layer);
      }
      void renderLevel(SDL_Renderer* ren)
      {
          for (int i = 0; i < _layers.size(); i++)
          {
              _layers[i]->draw(ren);
          }
      }
};

