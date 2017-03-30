//CollisionTestSelfCommand.h
//Jacqueline Passehl Winter Quarter 2k16
#ifndef _CollisionTestSelfCommand
#define _CollisionTestSelfCommand

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"

template <typename C>
class CollisionTestSelfCommand :public CollisionTestCommandBase
{
private:
	typename CollidableGroup<C>::CollidableCollection& Collection;

	CollisionTestSelfCommand operator=(const CollisionTestSelfCommand&) = delete;

public:
	CollisionTestSelfCommand()
		:Collection(CollidableGroup<C>::GetColliderCollection())
		{
		};
	virtual void execute()
	{
		for (auto it = Collection.begin(); it != Collection.end(); it++)
		{
			auto it2 = it;
			for (it2; it2 != Collection.end(), it2++)
			{
				if (it2!=it)
				{
				

				if (Collidable::CollisionTestPairBSphere(*it1, *it2))
				{

					bool testResult = Collidable::CollisionTestPair(*it1, *it2);
					//bool testResult = true; 

						if (testResult == true)
						{
							(*it)->Collision(*it2);
							(*it2)->Collision(*it);


						}
						else
						{
							//beSpheres are colliding but collision volumes arent
							(*it)->CollisionBSphere(*it2);
							(*it2)->CollisionBSphere(*it);
						}
					}
				}
			}
		}
		
	}
};
#endif _CollisionTestSelfCommand