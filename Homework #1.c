
#include <stdio.h>

int get_eps_float();
int get_eps_double();

// 1234번 - 샘플 코드
int main(void){
    int method_1 = 3;
    printf("Method 1: %d\n", method_1);
    int method_2_float = get_eps_float();
    int method_2_double = get_eps_double();
    printf("Method 2: %d(float), %d(double)\n", method_2_float, method_2_double);
    return 0;
}
/* Functions */
int get_eps_float(){
    int count=0;
    float eps = 1;
    while((float)1 + eps > (float)1){
        eps /= 2;
        count++;
    }
    return count;
}
int get_eps_double(){
    int count=0;
    double eps = 1;
    while((double)1 + eps > (double)1){
        eps /= 2;
        count++;
    }
    return count;
}
#include <math.h>
#define CONV(i) ((float)(i))
Change float to double here and in declarations below to find double precision parameters.
void machar(int *ibeta, int *it, int *irnd, int *ngrd, int *machep, int *negep,
int *iexp, int *minexp, int *maxexp, float *eps, float *epsneg,
float *xmin, float *xmax)
Determines and returns machine-specific parameters affecting floating-point arithmetic. Returned
values include ibeta, the floating-point radix; it, the number of base-ibeta digits in
the floating-point mantissa; eps, the smallest positive number that, added to 1.0, is not equal
to 1.0; epsneg, the smallest positive number that, subtracted from 1.0, is not equal to 1.0;
xmin, the smallest representable positive number; and xmax, the largest representable positive
number. See text for description of other returned parameters.
{
int i,itemp,iz,j,k,mx,nxres;
float a,b,beta,betah,betain,one,t,temp,temp1,tempa,two,y,z,zero;
one=CONV(1);
two=one+one;
zero=one-one;
a=one; Determine ibeta and beta by the method of M.
do { Malcolm.
a += a;
temp=a+one;
temp1=temp-a;
} while (temp1-one == zero);
b=one;
do {
b += b;
temp=a+b;
itemp=(int)(temp-a);
} while (itemp == 0);
*ibeta=itemp;
beta=CONV(*ibeta);
*it=0; Determine it and irnd.
b=one;
do {
++(*it);
b *= beta;
temp=b+one;
temp1=temp-b;
} while (temp1-one == zero);
*irnd=0;
betah=beta/two;
temp=a+betah;
if (temp-a != zero) *irnd=1;
tempa=a+beta;
temp=tempa+betah;
if (*irnd == 0 && temp-tempa != zero) *irnd=2;
*negep=(*it)+3; Determine negep and epsneg.
betain=one/beta;
a=one;
for (i=1;i<=(*negep);i++) a *= betain;
b=a;
for (;;) {
temp=one-a;
if (temp-one != zero) break;
a *= beta;
--(*negep);
}
*negep = -(*negep);
*epsneg=a;
*machep = -(*it)-3; Determine machep and eps.
a=b;
for (;;) {
temp=one+a;
if (temp-one != zero) break;
a *= beta;
++(*machep);
}
*eps=a;
*ngrd=0; Determine ngrd.
temp=one+(*eps);
if (*irnd == 0 && temp*one-one != zero) *ngrd=1;
i=0; Determine iexp.
k=1;
z=betain;
t=one+(*eps);
nxres=0;
for (;;) { Loop until an underflow occurs, then exit.
y=z;
z=y*y;
a=z*one; Check here for the underflow.
temp=z*t;
if (a+a == zero || fabs(z) >= y) break;
temp1=temp*betain;
if (temp1*beta == z) break;
++i;
k += k;
}
if (*ibeta != 10) {
*iexp=i+1;
mx=k+k;
} else { For decimal machines only.
*iexp=2;
iz=(*ibeta);
while (k >= iz) {
iz *= *ibeta;
++(*iexp);
}
mx=iz+iz-1;
}
for (;;) { To determine minexp and xmin, loop until an
*xmin=y; underflow occurs, then exit.
y *= betain;
a=y*one; Check here for the underflow.
temp=y*t;
if (a+a != zero && fabs(y) < *xmin) {
++k;
temp1=temp*betain;
if (temp1*beta == y && temp != y) {
nxres=3;
*xmin=y;
break;
}
}
else break;
}
*minexp = -k; Determine maxexp, xmax.
if (mx <= k+k-3 && *ibeta != 10) {
mx += mx;
++(*iexp);
}
*maxexp=mx+(*minexp);
*irnd += nxres; Adjust irnd to reflect partial underflow.
if (*irnd >= 2) *maxexp -= 2; Adjust for IEEE-style machines.
i=(*maxexp)+(*minexp);
Adjust for machines with implicit leading bit in binary mantissa, and machines with radix
point at extreme right of mantissa.
if (*ibeta == 2 && !i) --(*maxexp);
if (i > 20) --(*maxexp);
if (a != y) *maxexp -= 2;
*xmax=one-(*epsneg);
if ((*xmax)*one != *xmax) *xmax=one-beta*(*epsneg);
*xmax /= (*xmin*beta*beta*beta);
i=(*maxexp)+(*minexp)+3;
for (j=1;j<=i;j++) {
if (*ibeta == 2) *xmax += *xmax;
else *xmax *= beta;
}
}