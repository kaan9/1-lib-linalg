/* TEST.C --- 4 dimensional vector and matrix tests --- copyright kbe --- MIT LICENSE */
#include <stdio.h>

#include "vec4.h"
#include "mat4.h"

void pvec(struct vec4 const *v, struct vec4 const *w)
{
	printf("1: [ %f | %f | %f | %f ]", v->x, v->y, v->z, v->w);
	printf("2: [ %f | %f | %f | %f ]\n", w->x, w->y, w->z, w->w);
}

void vec4tests()
{
	float c,l;
	struct vec4 v = {1.f, 2.f, 3.f, 4.f};
	struct vec4 w = v;
	pvec(&v, &w);
	struct vec4 vcross;
	v = vec4_sum(v, w);
	pvec(&v, &w);
	v = vec4_prod(v, 2.f);
	pvec(&v, &w);
	v = vec4_neg(v);
	pvec(&v, &w);
	c = vec4_dot(v, w);
	printf("c = %f\n", c);
	vcross = vec4_cross(v, w);
	pvec(&v, &vcross);
	l = vec4_mag(v);
	printf("l = %f\n", l);
	v = vec4_normalize(v);
	pvec(&v, &w);
}

void pmat(struct mat4 const *m)
{
	printf("\n| %f | %f | %f | %f |\n| %f | %f | %f | %f |\n"
			"| %f | %f | %f | %f |\n| %f | %f | %f | %f |\n",
			m->vs[0].x, m->vs[1].x, m->vs[2].x, m->vs[3].x,
			m->vs[0].y, m->vs[1].y, m->vs[2].y, m->vs[3].y,
			m->vs[0].z, m->vs[1].z, m->vs[2].z, m->vs[3].z,
			m->vs[0].w, m->vs[1].w, m->vs[2].w, m->vs[3].w);
}

void mat4tests()
{
	pmat(&mat4_make_diag(1.f));
	pmat(&mat4_make_diag(0.f));
	struct mat4 mrot = mat4_make_rot(74.f, 0.f, 1.f, 0.f);
	pmat(&mrot);
	
}


int main(void)
{
//	vec4tests();
	mat4tests();
	return 0;
}
