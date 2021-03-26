#define CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <windows.h>

i, j, k, x, y, o, N;
main() {
    float z[1760], a
#define R(t,x,y) f=x;x-=t*y\
   ;y+=t*f;f=(3-x*x-y*y)/2;x*=f;y*=f;
        = 0, e = 1, c = 1, d = 0, f, g, h, G, H, A, t, D; char
        b[1760]; for (;;) {
        memset(b, 32, 1760); g = 0,
            h = 1; memset(z, 0, 7040); for (j = 0; j < 90; j++) {
            G = 0, H = 1; for (i = 0; i < 314; i++) {
                A = h + 2, D = 1 / (G *
                    A * a + g * e + 5); t = G * A * e - g * a; x = 40 + 30 * D
                    * (H * A * d - t * c); y = 12 + 15 * D * (H * A * c +
                        t * d); o = x + 80 * y; N = 8 * ((g * a - G * h * e)
                            * d - G * h * a - g * e - H * h * c);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
                {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }R(.02, H, G);
            }R(
                .07, h, g);
        }for (k = 0; 1761 > k; k++)putchar
        (k % 80 ? b[k] : 10); R(.04, e, a); R(.02, d,
            c); 
        printf('\n' + (
                " donut.c! \x1b[23A"));
    }
}
/*no math lib needed
   .@a1k0n 2021.*/
//int k;
//double sin(), cos();
//main() {
//    float A = 0, B = 0, i, j, z[1760];
//    char b[1760];
//    printf("\x1b[2J");
//    for (; ; ) {
//        memset(b, 32, 1760);
//        memset(z, 0, 7040);
//        for (j = 0; 6.28 > j; j += 0.07) {
//            for (i = 0; 6.28 > i; i += 0.02) {
//                float sini = sin(i),
//                    cosj = cos(j),
//                    sinA = sin(A),
//                    sinj = sin(j),
//                    cosA = cos(A),
//                    cosj2 = cosj + 2,
//                    mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5),
//                    cosi = cos(i),
//                    cosB = cos(B),
//                    sinB = sin(B),
//                    t = sini * cosj2 * cosA - sinj * sinA;
//                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB),
//                    y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
//                    o = x + 80 * y,
//                    N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);
//                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o]) {
//                    z[o] = mess;
//                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
//                }
//            }
//        }
//        printf("\x1b[d");
//        for (k = 0; 1761 > k; k++)
//            putchar(k % 80 ? b[k] : 10);
//        A += 0.04;
//        B += 0.02;
//    }
//}