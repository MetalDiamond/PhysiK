#ifndef VEC3_H
#define VEC3_H

namespace PhysiK {

	/**
	 * @brief A vertex
	 */
	class vec3
	{

		public:

			float x,y,z;

			vec3(const float fst = 0, const float snd = 0, const float thr = 0);

			/**
			 * @brief hash the parameter
			 */
			unsigned int operator()(const vec3& to_hash) const;

			const float& operator[](const unsigned int offset) const;

			float& operator[](const unsigned int offset);

			vec3 operator*(const float snd) const;

			vec3 operator+(const vec3 snd) const;

			vec3 operator/(const float snd) const;

			vec3 operator-(const vec3 snd) const;

			float length() const;

			vec3 cross(vec3 snd) const;

			float dot(vec3 snd) const;

	};

}

#endif // VEC3_H