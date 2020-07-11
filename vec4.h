/* VEC4.H --- 4 dimensional vector --- copyright kbe --- MIT LICENSE */

#ifndef VEC4_H
#define VEC4_H

#include <math.h>

struct vec4 {
	float x;
	float y;
	float z;
	float w;
};

extern struct vec4 vec4_sum(struct vec4 v, struct vec4 u);

extern struct vec4 vec4_mul(struct vec4 v, struct vec4 u);

extern struct vec4 vec4_negate(struct vec4 v);

extern float vec4_dot(struct vec4 v, struct vec4 w);
/* for 3-d vectors */
extern struct vec4 vec4_cross(struct vec4 v, struct vec4 w);

extern float vec4_mag(struct vec4 v); 

extern struct vec4 vec4_normalize(struct vec4 v);

#define vec4_sum(v, u)		\
	((struct vec4) {	\
		(v).x + (u).x,	\
		(v).y + (u).y,	\
		(v).z + (u).z,	\
		(v).w + (u).w	\
	 })

#define vec4_mul(v, c)		\
	((struct vec4) {	\
		(v).x * (c),	\
		(v).y * (c),	\
		(v).z * (c),	\
		(v).w * (c)	\
	 })

#define vec4_negate(self) 	\
	((struct vec4) {	\
		-((v).x),	\
		-((v).y),	\
		-((v).z),	\
		-((v).w)	\
	 })

#define vec4_dot(v, u)	\
	(((v).x * (u).x) + ((v).y * (u).y) + ((v).z * (u).z) + ((v).w * (u).w))

#define vec4_cross(v, u) 			\
	((struct vec4) {			\
		(v).y * (u).z - (v).z * (u).y,	\
		(v).z * (u).x - (v).x * (u).z,	\
		(v).x * (u).y - (v).y * (u).x,	\
		0				\
	})

#define vec4_mag(v)	\
	(sqrtf(vec4_dot((v), (v))))

#define vec4_normalize(v)	\
	vec4_mul((v), 1.0f / vec4_mag(v))

#endif /* VEC4_H */
