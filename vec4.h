/* VEC4.H --- 4 dimensional vector --- Copyright kbe --- MIT LICENSE */

#ifndef VEC4_H
#define VEC4_H

#include <math.h>

struct vec4 {
	float x;
	float y;
	float z;
	float w;
};

extern void vec4_add(struct vec4 *self, struct vec4 const *other);

extern void vec4_mul(struct vec4 *self, float c);

extern void vec4_negate(struct vec4 *v);

extern float vec4_dot(struct vec4 const *v, struct vec4 const *w);
/* for 3-d vectors */
extern struct vec4 vec4_cross(struct vec4 const *v, struct vec4 const *w);

extern float vec4_mag(struct vec4 const *v); 

extern void vec4_normalize(struct vec4 *v);

#define vec4_mag(v)	\
	(sqrt(vec4_dot(v, v)))

#define vec4_normalize(v) \
	vec4_mul(v, 1.0f / vec4_mag(v))

#define vec4_add(self, other)		\
	do {				\
		self->x += other->x;	\
		self->y += other->y;	\
		self->z += other->z;	\
		self->w += other->w;	\
	} while(0)

#define vec4_mul(self, c)	\
	do {			\
		self->x *= c;	\
		self->y *= c;	\
		self->z *= c;	\
		self->w *= c;	\
	} while(0)

#define vec4_negate(v) 			\
	do {				\
		self->x = -(self->x);	\
		self->y = -(self->y);	\
		self->z = -(self->z);	\
		self->w = -(self->w);	\
	} while(0)

#define vec4_dot(v, w)	\
	((v->x * w->x) + (v->y * w->y) + (v->z * w->z) + (v->w * w->w))

#define vec4_cross(v, w) 			\
	(struct vec4 {				\
		v->y * w->z - v->z * w->y,	\
		v->z * w->x - v->x * w->z,	\
		v->x * w->y - v->y * w->x,	\
		0				\
	})

#endif
