#ifndef MATERIAL_H
#define MATERIAL_H

enum {
    // Geometry Flags
    DIFFUSE_TEXTURE, // must stay first for crappy rendering
    AMBIENT_TEXTURE,
    SPECULAR_TEXTURE,
    NORMAL_MAP,
    ALPHA_MASK,
    INSTANCING,
    NB_FLAGS
};

enum {
    // Geometry Flags
    DIFFUSE_TEXTURE_FLAG = 1 << DIFFUSE_TEXTURE,
    AMBIENT_TEXTURE_FLAG = 1 << AMBIENT_TEXTURE,
    SPECULAR_TEXTURE_FLAG = 1 << SPECULAR_TEXTURE,
    NORMAL_MAP_FLAG = 1 << NORMAL_MAP,
    ALPHA_MASK_FLAG = 1 << ALPHA_MASK,
    INSTANCING_FLAG = 1 << INSTANCING
};

class Shader;

class Material
{
public:
    virtual void bindAttributes(Shader*) = 0;
    virtual unsigned int getFlags() = 0;
    virtual ~Material(){}
};

#endif // MATERIAL_H
