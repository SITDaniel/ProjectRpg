#include "Map.h"
#include "World.h"


void main()
{
    World& w = World::GetInstance();
	w.InitCharacter();
	w.CreateMaps(5);
	
    for (int i = 0; i < 5; i++)
    {
        Map& m = w[i];
        m("Map " + std::to_string(i));
        m(10, 10);     
    }
    
    Map& m = w[w.GetMapIndex()];    
	m.SetCharacter(&w.GetPlayer());
    m.Display();

    
}