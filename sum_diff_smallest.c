/**
 * http://bbs.chinaunix.net/forum.php?mod=viewthread&tid=855126&page=8#pid6022430
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int
sum_array(int *a, int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

void
do_swap(int *a, int *b, int n)
{
	int A, i, j, x, d, m, si, sj, *ap, *bp;

do_start:
	i = sum_array(a, n);
	j = sum_array(b, n);
	A = i - j;
	ap = a;
	bp = b;
	if(A < 0) {
		ap = b;
		bp = a;
		A = j - i;
	}
	
	m = A;
	si = sj = -1;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++) {
			x = ap[i] - bp[j];
			if(x > 0 && x < A) {
				d = abs((x * 2) - A);
				if(d < m) {
					m = d;
					si = i;
					sj = j;
				}
			}

		}
	}

	if(si != -1) {
		i = ap[si];
		ap[si] = bp[sj];
		bp[sj] = i;
		goto do_start;
	}
}

void
dump_array(int *a, int n)
{
	int i;
	printf("\n");
	for(i = 0; i < n; i++) {
		printf(" %d ", a[i]);
	}
}

void
mk_rand_int_array(int *a, int n)
{
	int i, r;
	for(i = 0; i < n; i++) {
		r = rand(100);
		a[i] = r % 101; //* ( r % 2 ? 1 : -1);
	}
}

int
main()
{
	int n = 3;
	int a[] = {999, 1, 0};
	int b[] = {1, 0, 2};

	do_swap(a, b, n);
	dump_array(a, n);
	dump_array(b, n);

	int n2 = 4;
	int a2[] = {1, 2, 3, 4};
	int b2[] = {5, 6, 7, 8};

	do_swap(a2, b2, n2);
	dump_array(a2, n2);
	dump_array(b2, n2);

	int n3 = 5;
	int a3[n3], b3[n3];
	mk_rand_int_array(a3, n3);
	mk_rand_int_array(b3, n3);

	do_swap(a3, b3, n3);
	dump_array(a3, n3);
	dump_array(b3, n3);

	exit(0);
}
