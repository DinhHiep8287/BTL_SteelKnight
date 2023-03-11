#include "TileLayer.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
void layer::load(string path , SDL_Texture* tileSetTex) {
    ifstream _map(path);
    
    for (int i = 0; i < NUMMAPX * NUMMAPY; i++)
    {   
        int id = 0 ;
        int x = (i % NUMMAPX) * SIZE;
        int y = (i / NUMMAPX) * SIZE;
        _map >> id;
        tile tempTile(tileSetTex, x, y, id);
        tiles.push_back(tempTile);
    }

}

void layer::draw(SDL_Renderer* ren) {
    for (int i = 0; i < tiles.size() ; i++) {
        tiles[i].draw(ren);
    }
}