/* MAT4.H --- 4 dimensional matrix --- copyright kbe --- MIT LICENSE */

#ifndef MAT4_H
#define MAT4_H

#include <math.h>

#include "vec4.h"

struct mat4 {
	struct vec4 vs[4];
};

extern struct mat4 mat4_sum(struct mat4 m, struct mat4 n);

extern struct mat4 mat4_prod_f(struct mat4 m, float c);

/* 4x4 matrix times a 4x1 vector */
extern struct mat4 mat4_prod_mat4(struct mat4 m, struct mat4 n);

/* 4x4 matrix times a 4x4 vector */
extern struct vec4 mat4_prod_vec4(struct mat4 m, struct vec4 v);


/* 1x4 vector times a 4x4 matrix */
extern struct vec4 vec4_prod_mat4(struct vec4 v, struct mat4 m);


extern struct mat4 mat4_neg(struct mat4 m);

extern struct mat4 mat4_transpose(struct mat4 m);

extern struct vec4 mat4_row(struct mat4 m, unsigned int index);

/* diagonal matrix */
extern struct mat4 mat4_make_diag(float c);

/* Rodrigues's formula for 3d rotation matrix by an angle in degrees around an xyz axis  */
static inline struct mat4 mat4_make_rot(float angle, float x, float y, float z)
{
	float c = cosf((angle / 360.f) * 2.f * 3.1415927f), s = sinf((angle / 360.f) * 2.f * 3.1415927f);
	return (struct mat4) {
		(struct vec4) {c + x * x * (1.f - c), z * s + x * y * (1.f - c),
			-y * s + x * z * (1.f - c), 0.f},
		(struct vec4) {-z * s + x * y * (1.f - c), c + y * y * (1.f - c),
			x * s + y * z * (1.f - c), 0.f},
		(struct vec4) {y * s + x * z * (1.f - c), -x * s + y * z * (1.f - c),
			c + z * z * (1.f - c), 0.f},
		(struct vec4) {0.f, 0.f, 0.f, 1.f}
	};
}

/* 4x4 translation matrix of an xyz displacement */
extern struct mat4 mat4_make_trans(float x, float y, float z);

/* 4x4 scale matrix of an xyz scaling */
extern struct mat4 mat4_make_scale(float x, float y, float z);

#define mat4_sum(m, n)				\
	((struct mat4) {			\
		vec4_sum((m).vs[0], (n).vs[0]),	\
		vec4_sum((m).vs[1], (n).vs[1]),	\
		vec4_sum((m).vs[2], (n).vs[2]),	\
		vec4_sum((m).vs[3], (n).vs[3]),	\
	})

#define mat4_prod_f(m, c)		\
	((struct mat4) {		\
		vec4_prod((m).vs[0], (c)),	\
		vec4_prod((m).vs[1], (c)),	\
		vec4_prod((m).vs[2], (c)),	\
		vec4_prod((m).vs[3], (c)),	\
	})

#define mat4_prod_mat4(m, n)			\
	((struct mat4) {			\
		mat4_prod_vec4((m), (n).vs[0]),	\
		mat4_prod_vec4((m), (n).vs[1]),	\
		mat4_prod_vec4((m), (n).vs[2]),	\
		mat4_prod_vec4((m), (n).vs[3])	\
	})

#define mat4_prod_vec4(m, v)			\
	((struct vec4) {			\
		vec4_dot(mat4_row((m), 0), (v)),	\
		vec4_dot(mat4_row((m), 1), (v)),	\
		vec4_dot(mat4_row((m), 2), (v)),	\
		vec4_dot(mat4_row((m), 3), (v))	\
	})

#define vec4_prod_mat4(m, v)		\
	((struct vec4) {		\
		vec4_dot((v), (m).vs[0])),	\
		vec4_dot((v), (m).vs[1])),	\
		vec4_dot((v), (m).vs[2])),	\
		vec4_dot((v), (m).vs[3]))	\
	})


#define mat4_neg(m)			\
	((struct mat4) {		\
		vec4_neg((m).vs[0]),	\
		vec4_neg((m).vs[1]),	\
		vec4_neg((m).vs[2]),	\
		vec4_neg((m).vs[3]),	\
	})

#define mat4_transpose(m)	\
	((struct mat4) {	\
	 	mat4_row((m), 0),	\
	 	mat4_row((m), 1),	\
	 	mat4_row((m), 2),	\
	 	mat4_row((m), 3)	\
	})

#define mat4_row(m, i)				\
	((struct vec4) {			\
		((float[]) (m)->vs[0])[(i)],	\
		((float[]) (m)->vs[1])[(i)],	\
		((float[]) (m)->vs[2])[(i)],	\
		((float[]) (m)->vs[3])[(i)],	\
	})

#define mat4_make_diag(c)				\
	((struct mat4) {				\
		((struct vec4) {(c), 0.0f, 0.0f, 0.0f}),	\
	 	((struct vec4) {0.0f, (c), 0.0f, 0.0f}),	\
		((struct vec4) {0.0f, 0.0f, (c), 0.0f}),	\
		((struct vec4) {0.0f, 0.0f, 0.0f, (c)})	\
	})

#define mat4_make_trans(x, y, z)				\
	((struct mat4) {					\
		((struct vec4) {0.0f, 0.0f, 0.0f, 0.0f}),	\
	 	((struct vec4) {0.0f, 0.0f, 0.0f, 0.0f}),	\
		((struct vec4) {0.0f, 0.0f, 0.0f, 0.0f}),	\
		((struct vec4) {(x), (y), (z), 1.0f})			\
	})

#define mat4_make_scale(x, y, z)			\
	((struct mat4) {				\
		((struct vec4) {(x), 0.0f, 0.0f, 0.0f}),	\
	 	((struct vec4) {0.0f, (y), 0.0f, 0.0f}),	\
		((struct vec4) {0.0f, 0.0f, (z), 0.0f}),	\
		((struct vec4) {0.0f, 0.0f, 0.0f, 1})	\
	})

#endif /* MAT4_H */
