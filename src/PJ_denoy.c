#define PJ_LIB__
#include    <projects.h>

PROJ_HEAD(denoy, "Denoyer Semi-Elliptical") "\n\tPCyl., no inv., Sph.";

#define C0  0.95
#define C1 -0.08333333333333333333
#define C3  0.00166666666666666666
#define D1  0.9
#define D5  0.03


static XY s_forward (LP lp, PJ *P) {            /* Spheroidal, forward */
    XY xy = {0.0, 0.0};
    (void) P;
    xy.y = lp.phi;
    xy.x = lp.lam;
    lp.lam = fabs(lp.lam);
    xy.x *= cos((C0 + lp.lam * (C1 + lp.lam * lp.lam * C3)) *
            (lp.phi * (D1 + D5 * lp.phi * lp.phi * lp.phi * lp.phi)));
    return xy;
}


PJ *PROJECTION(denoy) {
    P->es = 0.0;
    P->fwd = s_forward;

    return P;
}

