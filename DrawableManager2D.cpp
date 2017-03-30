//DrawableManager2D.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawableManager2D.h"
#include "Drawable2D.h"
#include <string>
#include <list>


void DrawableManager2D::Register(Drawable2D* draw)
{
	drawable2DList.push_front(draw);
}
void DrawableManager2D::Deregister(Drawable2D* draw)
{
	drawable2DList.remove(draw);
}
void DrawableManager2D::ProcessElements()
/*Goes through the list and calls update on all the updatables
// replacing the scenes update call in the update tick, the scene iself just calls this!
*/
{
	for (std::list<Drawable2D*>::iterator it = drawable2DList.begin(); it != drawable2DList.end(); ++it)
	{
		(*it)->Draw2D();
	}
}