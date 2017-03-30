//CollisionTestPairCommand.h
//Jacqueline Passehl Winter Quarter 2k16
#ifndef _CollisionTestPairCommand
#define _CollisionTestPairCommand

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"


template <typename C1, typename C2>
class CollisionTestPairCommand :public CollisionTestCommandBase,public Align16
{
private:
	typename CollidableGroup<C1>::CollidableCollection& Collection1;
	typename CollidableGroup<C2>::CollidableCollection& Collection2;

	Vect Blue = Vect(0, 0, 1);
	Vect Yellow = Vect(1, 1, 0);


	CollisionTestPairCommand operator=(const CollisionTestPairCommand&) = delete;

public:
	CollisionTestPairCommand()
		:Collection1(CollidableGroup<C1>::GetColliderCollection()),
		Collection2(CollidableGroup<C2>::GetColliderCollection())
		{
		};
	virtual void execute()
	{

		//if the two ABB groups arent colliding it doesnt do all this math
		if (CollidableGroup<C2>::IntersectGroupABBs(CollidableGroup<C1>::getAABB()))
		{
			//if colliding
			CollidableGroup<C1>::RenderThis(Yellow);
			CollidableGroup<C2>::RenderThis(Yellow);

			for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
			{
				//Bsphere vs Group ABB
				if (CollidableGroup<C2>::IntersectABBvBsphere((*it1)->getBSphere()))
				{
					for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						//Bsphere vs Bsphere
						if (Collidable::CollisionTestPairBSphere(*it1, *it2))
						{

							bool testResult = Collidable::CollisionTestPair(*it1, *it2);


							if (testResult == true)
							{
								(*it1)->Collision(*it2);
								(*it2)->Collision(*it1);
							}
							else
							{
								//beSpheres are colliding but collision volumes arent
								//so this tests that only the bspheres if the group abbs are colliding and
								//if not it doesnt check any collision,
								//if they are it checks bsphere collision between both groups and collision volume
								(*it1)->CollisionBSphere(*it2);
								(*it2)->CollisionBSphere(*it1);

							}
						}
					}
				
				}
			}
		}
		else
		{
			//else blue
			CollidableGroup<C1>::RenderThis(Blue);
			CollidableGroup<C2>::RenderThis(Blue);
		}

		
	}
}; 
#endif _CollisionTestPairCommand