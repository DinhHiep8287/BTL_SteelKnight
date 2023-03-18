#include "TileLayer.hpp"
using namespace std;
void layer::load(string path , SDL_Texture* tileSetTex , int NumTileSetX , int NumTileSetY , int firstId) {
    ifstream _map(path);
    
    for (int i = 0; i < NUMMAPX * NUMMAPY; i++)
    {   
        int id = 0 ;
        int x = (i % NUMMAPX) * SIZE;
        int y = (i / NUMMAPX) * SIZE;
        _map >> id;
        id = id - firstId + 1;
        tile tempTile(tileSetTex, x, y, id , NumTileSetX , NumTileSetY );
        tiles.push_back(tempTile);
    }

}

void layer::draw(SDL_Renderer* ren) {
    for (int i = 0; i < tiles.size() ; i++) {
        tiles[i].draw(ren);
    }
}