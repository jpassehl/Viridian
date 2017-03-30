//DrawableManager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawableManager.h"
#include "Drawable.h"
#include <string>
#include <list>


void DrawableManager::Register(Drawable* up)
{
	drawableList.push_front(up);
}
void DrawableManager::Deregister(Drawable* up)
{
	drawableList.remove(up);
}
void DrawableManager::ProcessElements()
/*Goes through the list and calls update on all the updatables
// replacing the scenes update call in the update tick, the scene iself just calls this!
*/
{
	for (std::list<Drawable*>::iterator it = drawableList.begin(); it != drawableList.end(); ++it)
	{
		(*it)->Draw();
	}
}