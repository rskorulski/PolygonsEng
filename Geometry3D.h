#ifndef _H_GEOMETRY_3D_
#define _H_GEOMETRY_3D_
#include "vectors.h"
#include "matrices.h"

typedef vec3 Point;

typedef struct Line
{
	Point start;
	Point end;
	inline Line() {}
	inline Line(const Point& s, const Point& e) : start(s), end(e) {}
}Line;

typedef struct Ray
{
	Point origin;
	vec3 dir;
	inline Ray() : dir(0.0f, 0.0f, 1.0f) {}
	inline Ray(const Point& o, const vec3& d) : origin(o), dir(d) { NormalizeDirection(); }
	inline void NormalizeDirection() { Nomd(dir); }
}Ray;

typedef struct Sphere
{
	Point position;
	float radius;
	inline Sphere() : radius(1.0f) {}
	inline Sphere(const Point& p, float r) : position(p), radius(r) {}
}Sphere;

typedef struct AABB
{
	Point position;
	vec3 size;
	inline AABB() : size(1, 1, 1) {}
	inline AABB(const Point& o, const vec3& s) : position(o), size(s) {}
}AABB;

typedef struct OBB
{
	Point position;
	vec3 size;
	mat3 orientation;
	inline OBB() : size(1, 1, 1) {}
	inline OBB(const Point& p, const vec3& s) : position(p), size(s) {}
	inline OBB(const Point& p, const vec3& s, const mat3& o) : position(p), size(s), orientation(o) {}
}OBB;

typedef struct Plane
{
	vec3 normal;
	float distance;
	inline Plane() : normal(1, 0, 0) {}
	inline Plane(const vec3& n, float d) : normal(n), distance(d) {}
}Plane;

typedef struct Triangle
{
	union 
	{
		struct
		{
			Point a;
			Point b;
			Point c;
		};
		Point points[3];
		float values[9];
	};
	inline Triangle() {}
	inline Triangle(const Point& p1, const Point& p2, const Point& p3) : a(p1), b(p2), c(p3) {}
}Triangle;

//Methods
//line

float Len(const Line& line);		//get line length
float LenSq(const Line& line);		//get squared line length

//ray
Ray FromPoints(const Point& from, const Point& to);

//AABB
vec3 GetMin(const AABB& aabb);
vec3 GetMax(const AABB& aabb);
AABB FromMinMax(const vec3& min, const vec3& max);

//plane
float PlaneEquation(const Point& pt, const Plane& plane);


#endif