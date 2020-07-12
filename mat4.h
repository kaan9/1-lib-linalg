/* MAT4.H --- 4 dimensional matrix --- copyright kbe --- MIT LICENSE */

#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"

struct mat4 {
	struct vec4 vs[4];
};

extern struct mat4 mat4_sum(struct mat4 m, struct mat4 n);

extern struct mat4_prod_f(struct mat4 m, float c);

extern struct mat4 mat4_prod_mat4(struct mat4 m, struct mat4 n);

extern struct mat4 mat4_prod_vec4(struct mat4 m, struct vec4 v);

extern struct vec4 vec4_prod_mat4(struct vec4 v, struct mat4 m);


extern struct mat4 mat4_neg(struct mat4 m);

extern struct mat4 mat4_transpose(struct mat4 m);

extern struct vec4 mat4_row(struct mat4 m, unsigned int index);

/* identity matrix */
extern struct mat4 mat4_make_id();
/* diagonal matrix */
extern struct mat4 mat4_make_diag(float c);
/* Rodrigues's formula for 3d rotation matrix by an angle around an xyz axis */
extern struct mat4 mat4_make_rot(float angle, float x, float y, float z);
/* 4x4 translation matrix of an xyz displacement */
extern struct mat4 mat4_make_trans(float x, float y, float z);
/* 4x4 scale matrix of an xyz scaling */
extern struct mat4 mat4_make_scale(float x, float y, float z);

#define mat4_sum(m, n)				\
	((struct mat4) {			\
		vec4_sum(m.vs[0], n.vs[0]),	\
		vec4_sum(m.vs[1], n.vs[1]),	\
		vec4_sum(m.vs[2], n.vs[2]),	\
		vec4_sum(m.vs[3], n.vs[3]),	\
	 })

#define mat4_prod_f(m, c)			\
	do {					\
		vec4_prod((m)->vs[0], c);	\
		vec4_prod((m)->vs[1], c);	\
		vec4_prod((m)->vs[2], c);	\
		vec4_prod((m)->vs[3], c);	\
	} while (0)

#define mat4_prod_mat4(m, n)			\
	do {					\
						\
	} while (0)

#define mat4_prod_vec4(m, v)			\
	do {					\
						\
	} while (0)

#define mat4_neg(m)				\
	do {					\
		vec4_neg((m)->vs[0])		\
		vec4_neg((m)->vs[1])		\
		vec4_neg((m)->vs[2])		\
		vec4_neg((m)->vs[3])		\
	} while (0)

#define mat4_transpose(m)			\
	
#define vec4_prod_mat4(v, m)			\

#define mat4_row(m, i)				\
	((vec4) {				\
		((float[]) m->vs[0])[i],	\
		((float[]) m->vs[1])[i],	\
		((float[]) m->vs[2])[i],	\
		((float[]) m->vs[3])[i],	\
	})
