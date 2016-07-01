#include "Map.h"
#include "World.h"

void main()
{
    World& w = World::GetInstance();
	w.InitCharacter();
	w.CreateMaps(5);
	
    Map& m = w[0];
	
	m.SetCharacter(&w.GetPlayer());
    m("Fields 1");
    m(10, 10);
    m.Display();
}