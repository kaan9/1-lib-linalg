/* MAT4.H --- 4 dimensional matrix --- copyright kbe --- MIT LICENSE */

#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"

struct mat4 {
	struct vec4 vs[4];
};

extern void mat4_add(struct mat4 *self, struct mat4 const *other);

extern void mat4_mul_f(struct mat4 *self, float c);

extern struct mat4 mat4_mul_mat4(struct mat4 const *m, struct mat4 const *n);

extern struct mat4 mat4_mul_vec4(struct mat4 const *m, struct vec4 const *v);


extern void mat4_negate(struct mat4 *self);

extern struct mat4 mat4_transpose(struct mat4 *self);

extern void vec4_mul_mat4(struct vec4 *self, const mat4 *m);

extern struct vec4 mat4_row(struct mat4 const *m, unsigned int index);

/* identity matrix */
extern struct mat4 mat4_id();
/* diagonal matrix */
extern struct mat4 mat4_diag(float c);
/* Rodrigues's formula for 3d rotation matrix by an angle around an xyz axis */
extern struct mat4 mat4_rot(float angle, float x, float y, float z);
/* 4x4 translation matrix of an xyz displacement */
extern struct mat4 mat4_trans(float x, float y, float z);
/* 4x4 scale matrix of an xyz scaling */
extern struct mat4 mat4_scale(float x, float y, float z);

#define mat4_add(m, n)					\
	do {						\
		vec4_add((m)->vs[0], (n)->vs[0]);	\
		vec4_add((m)->vs[1], (n)->vs[1]);	\
		vec4_add((m)->vs[2], (n)->vs[2]);	\
		vec4_add((m)->vs[3], (n)->vs[3]);	\
	} while (0)

#define mat4_mul_f(m, c)			\
	do {					\
		vec4_mul((m)->vs[0], c);	\
		vec4_mul((m)->vs[1], c);	\
		vec4_mul((m)->vs[2], c);	\
		vec4_mul((m)->vs[3], c);	\
	} while (0)

#define mat4_mul_mat4(m, n)			\
	do {					\
						\
	} while (0)

#define mat4_mul_vec4(m, v)			\
	do {					\
						\
	} while (0)

#define mat4_negate(m)				\
	do {					\
		vec4_negate((m)->vs[0])		\
		vec4_negate((m)->vs[1])		\
		vec4_negate((m)->vs[2])		\
		vec4_negate((m)->vs[3])		\
	} while (0)

#define mat4_transpose(m)			\
	
#define vec4_mul_mat4(v, m)			\

#define mat4_row(m, i)				\
	((vec4) {				\
		((float[]) m->vs[0])[i],	\
		((float[]) m->vs[1])[i],	\
		((float[]) m->vs[2])[i],	\
		((float[]) m->vs[3])[i],	\
	})


extern void vec4_add(struct vec4 *self, struct vec4 const *other);

extern void vec4_mul(struct vec4 *self, float c);

extern void vec4_negate(struct vec4 *v);

extern float vec4_dot(struct vec4 const *v, struct vec4 const *w);
/* for 3-d vectors */
extern void vec4_cross(struct vec4 const *v, struct vec4 const *w, struct vec4 *result);

extern float vec4_mag(struct vec4 const *v); 

extern void vec4_normalize(struct vec4 *v);

#define vec4_mag(v)	\
	(sqrtf(vec4_dot((v), (v))))

#define vec4_normalize(v) \
	vec4_mul((v), 1.0f / vec4_mag(v))

#define vec4_add(self, other)			\
	do {					\
		(self)->x += (other)->x;	\
		(self)->y += (other)->y;	\
		(self)->z += (other)->z;	\
		(self)->w += (other)->w;	\
	} while(0)

#define vec4_mul(self, c)		\
	do {				\
		(self)->x *= (c);	\
		(self)->y *= (c);	\
		(self)->z *= (c);	\
		(self)->w *= (c);	\
	} while(0)

#define vec4_negate(self) 			\
	do {					\
		(self)->x = -((self)->x);	\
		(self)->y = -((self)->y);	\
		(self)->z = -((self)->z);	\
		(self)->w = -((self)->w);	\
	} while(0)

#define vec4_dot(v, u)	\
	(((v)->x * (u)->x) + ((v)->y * (u)->y) + ((v)->z * (u)->z) + ((v)->w * (u)->w))

#define vec4_cross(v, u, r) 					\
	do { 							\
		(r)->x = (v)->y * (u)->z - (v)->z * (u)->y;	\
		(r)->y = (v)->z * (u)->x - (v)->x * (u)->z;	\
		(r)->z = (v)->x * (u)->y - (v)->y * (u)->x;	\
		(r)->w = 0;					\
	} while(0)

#endif /* MAT4_H */
