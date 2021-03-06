#ifndef PARTICLEMESH_H
#define PARTICLEMESH_H

#include <SparrowRenderer/parametricmesh.h>

#include <PhysiK/particlegroup.h>

struct ParticleProperties
{
    unsigned int amount;
    bool isKinematic;
    float radius;
    float mass;
    float r;
    float g;
    float b;
};

class ParticleMesh : public Sphere
{
    PhysiK::ParticleGroup group;

public:
    ParticleMesh(ParticleProperties properties, const glm::vec3* positions);

    void updatePositions();

    PhysiK::ParticleGroup* getParticleGroup();

    void applyOffset(int particleId, glm::vec3 moveVec);
};

#endif // PARTICLEMESH_H
