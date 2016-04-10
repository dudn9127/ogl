#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>

using namespace glm;

namespace FVF {
	enum { Position = 0x0, Normal = 0x10, TexCoord = 0x100 };
}

typedef struct Vertex {
	vec3 position;
	vec3 normal;
	vec2 texcoord;
};

class Material;
class Mesh {
private:
	GLuint VBO;
	GLuint IBO;
	GLuint texture;
	mat4 world;
	Material* material;
	int fvf;

	int nVertices;
	int nIndeces;
public:
	Mesh();
	void SetMaterial(Material* m) { material = m; };
	void SetMatrix(const mat4& m) { world = m; };
	const mat4& GetMatrix() { return world; };
	Material* GetMaterial() { return material; }
	virtual void Update(float dt) {};
	virtual void Render(float dt);

	static Mesh* GenerateSphere(float radius, unsigned int rings, unsigned int sectors);
};