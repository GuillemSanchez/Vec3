#ifndef Vec3_h
#define Vec3_h

#include <math.h>



template<class _Type>

class Vec3 {

public:
	_Type x, y, z;


	Vec3() 
	{}

	Vec3(const _Type &x, const _Type &y, const _Type &z) : // con los dos puntitos utilizas el metodo rapido.
		x(x),
		y(y),
		z(z)
	{}


	Vec3(const Vec3 &vec1, const Vec3 &vec2) :
		x(vec1.x - vec2.x),
		y(vec1.y - vec2.y),
		z(vec1.z - vec2.z)
	{}

	Vec3 operator + (const Vec3 &vec) const { // como no cambias nada de la clase puedes poner el const
		Vec3 vecr; // puedes crear uno directamente.
		vecr.x = x + vec.x;
		vecr.y = y + vec.y;
		vecr.z = z + vec.z;
		return vecr;
	}
	// return Vec3(x+vecs.x, y+vecs.y, z+vecs.z)
	
	Vec3 operator -(const Vec3 &vec) const {
		// puedes utilizar el metodo de arriba too.
		return Vec3(x+vec.x,y+vec.y,z+vec.z)
	}

	Vec3 operator +=(const Vec3 &vec) {// al modificar el vector primero no lo puedes hacer constante 
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	Vec3 operator -=(const Vec3 &vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}
	
	Vec3 operator =(const Vec3 &vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}

	bool operator== (const Vec3 &vec) const {
		return (x == vec.x && y == vec.y && z == vec.z);
	}

	void normalize() {
		_Type vec = (_type)sqrt(x * x + y * y + z * z);
		x /= vec;
		y /= vec;
		z /= vec;
	}

	void zero() {
		x = (_Type)0;
		y = (_Type)0;
		z = (_Type)0;
	}

	bool is_zero() const {
		return (x == (_Type)0 && y == (_Type)0 && z == (_Type)0);
	}

	_Type distance_to(const Vec3 &Vec2) const {
		return (_Type)sqrt((Vec2.x - x)*(Vec2.x - x) + (Vec2.y - y) * (Vec2.y - y) + (Vec2.z - z) * (Vec2.z - z));
	}

	_Type distance_to_squared(const Vec3 &Vec2) const {
		return (_Type)(Vec2.x - x) * (Vec2.x - x) + (Vec2.y - y) * (Vec2.y - y) + (Vec2.z - z) * (Vec2.z - z);
	}

};










#endif
