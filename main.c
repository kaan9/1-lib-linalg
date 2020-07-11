#include "vec4.h"
#include <stdio.h>

void pvec(struct vec4 const *v, struct vec4 const *w)
{
	printf("1: [ %f | %f | %f | %f ]", v->x, v->y, v->z, v->w);
	printf("2: [ %f | %f | %f | %f ]\n", w->x, w->y, w->z, w->w);
}

int main(void)
{
	float c,l;
	struct vec4 v = {1.f, 2.f, 3.f, 4.f};
	struct vec4 w = v;
	pvec(&v, &w);
	struct vec4 vcross;
	vec4_add(&v, &w);
	pvec(&v, &w);
	vec4_mul(&v, 2.f);
	pvec(&v, &w);
	vec4_negate(&v);
	pvec(&v, &w);
	c = vec4_dot(&v, &w);
	printf("c = %f\n", c);
	vec4_cross(&v, &w, &vcross);
	pvec(&v, &vcross);
	l = vec4_mag(&v);
	printf("l = %f\n", l);
	vec4_normalize(&v);
	pvec(&v, &w);

	return 0;
}
