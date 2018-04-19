//                                                                                                                                           
//                                           OPENGL 2.0 Abstraction API
//                                                January 24 2018
//                                               -----------------                                                                           
//                                                                                                                                           
//                                        COLLISION AND SIMPLE PHYSICS LIB                                                                    
//==========================================================================================================================


#include"Collision.h"

std::vector<CollisionSphere*> Collider;
unsigned int CollisionSphere::Collision_ObjectCount =0;;


 CollisionSphere::CollisionSphere(Vec3 pos, float radius, int parent)
    : 
      Radius(radius), 
      ParentID(parent),
      ID( Collision_ObjectCount++),
      Force(0,0,0),
      Acceleration(0,0,0),
      Velocity(0,0,0),
      Mass(radius / 2)

{
    Position = pos;
    Collision_ObjectList.push_back(this);
}

 float CollisionSphere::Is_Collision(int otherid)
{ 
    if(Collider[otherid]->ID != this->ID){

     float dist = Position.GetDistance(Collider[otherid]->Position); 

        if(dist  < (Radius + Collider[otherid]->Radius))
        {
            return dist;
        }
    }
    return false;
}


 void  CollisionSphere::CollisionDetection()
 {
     Force = 0;
     float DamperCoefficient = .1; // Dampening Factor
     float K = 1;
     for(CollisionSphere *List: Collider)
     {
         float CollisionDist = Is_Collision(List->ID); // Returns False if Same Object or No Collision

         if(CollisionDist != 0 ){                  // Returns Distance from Colliding object or FALSE for no Collision
//                         Axis Displacement   * Spring Factor - Damping Factor
            Force -= ((Position - List->Position) * (-K) - (Velocity * DamperCoefficient)) * .5;   // - DamperX;   
            List->Force += ((Position - List->Position) * (-K) - (Velocity * DamperCoefficient)) * .5;        
         }
     if (Position.y + Radius >= 0)  Position.y  = -Radius; /// CHEEP GROUND COLLISION DETECTION, Just dont let it go below 0;
     }
 }



 void CollisionSphere::Update(float TimeStep)
 {
     Vec3  Last_Acceleration = Acceleration;
           Position += Velocity * TimeStep + ( Last_Acceleration * 0.5f * Squared(TimeStep) );
           Acceleration = Force / Mass ;

     Vec3  Avg_Acceleration = ( Last_Acceleration + Acceleration ) / 2;
           Velocity += Avg_Acceleration * TimeStep;

           CollisionDetection();  
           Velocity = Velocity * .95f ;  
 }



 