#include "physicobject.h"

PhysiK::PhysicObject::PhysicObject(int nbPosition){
	positions = new Particle[nbPosition]();
    newPositions = new vec3[nbPosition]();
}

void PhysiK::PhysicObject::computeBarycenter()
{

    float xSum = 0.f, ySum = 0.f, zSum = 0.f;
    for(unsigned int i = 0; i < nbParticles; ++i){

        xSum += positions[i].pos.x;
        ySum += positions[i].pos.y;
        zSum += positions[i].pos.z;
    }

    xSum /= nbParticles;
    ySum /= nbParticles;
    zSum /= nbParticles;

	barycenter = vec3(xSum, ySum, zSum);
}

PhysiK::Particle *PhysiK::PhysicObject::getPositions()
{
    return positions;
}

void PhysiK::PhysicObject::preUpdate(float dt, float gravity, float damping)
{
    for(unsigned int i=0; i<nbParticles; ++i)
    {
        positions[i].velocity.y += gravity * dt;
        positions[i].velocity *= damping;
        newPositions[i] = positions[i].pos + positions[i].velocity*dt;
    }
}

void PhysiK::PhysicObject::postUpdate(float dt)
{
    for(unsigned int i=0; i<nbParticles; ++i)
    {
        positions[i].velocity = (newPositions[i] - positions[i].pos)/dt;
        positions[i].pos = newPositions[i];
    }
}

PhysiK::PhysicObject::~PhysicObject(){
	delete positions;
    delete newPositions;
}
