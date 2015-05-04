// Freddy + MSc

#define NDEBUG

#include <algorithm>
#include <vector>
#include <cassert>
#include "ferrocarril.h"

// Main
//	int EncontrarVagon(int v)
//	int VagonEnPosicion(int p)
//	int IntercambiarVagones(int a, int b)

using namespace std;

#define MAXN 50000
#define K 3.5

#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;

int N, sqN;

struct block {
	int i; // start index
	int size, prev, next;
	block(int i, int s, int p, int n):
		i(i), size(s), prev(p), next(n) {};
};

vector<block> B;

// bucket storage
int w[MAXN];

// idx[x] = idx of x in w
int idx[MAXN];

// a[idx[x]] = bucket of wagon x
int a[MAXN];

void printWagons() {
#ifdef NDEBUG
	return;
#endif
	printf("My wagons  : ");
	for (int i = 0; i != 1; i = B[i].next)
		for (int j = 0; j < B[i].size; j++)
			printf(" %d", w[B[i].i + j]);
	printf("\n");
	fflush(stdout);
}

void rebuild() {
	static bool first = true;
	static int wtmp[MAXN];

#ifndef NDEBUG
	printf("Rebuilding! D:\n");
	fflush(stdout);
#endif

	if (!first) {
		for (int i = 0, c = 1; i != 1; i = B[i].next)
			for (int j = 0; j < B[i].size; j++, c++)
				wtmp[c] = w[B[i].i + j];

		copy(wtmp + 1, wtmp + 1 + N, w + 1);
	} else first = false;

	for (int i = 1; i <= N; i++)
		idx[w[i]] = i;

	B.clear();

	B.pb(block(-1, 0, -1, 2));
	B.pb(block(-1, 0, 2, -1));

	for (int i = 0; i < (N + sqN - 1) / sqN; i++) {
		int bi = 1 + i * sqN;
		int size = min(N, (i + 1) * sqN) - i * sqN;
		B.pb(block(bi, size, i + 2 - 1, i + 2 + 1));
		fill(a + bi, a + bi + size, 2 + i);
	}

	B[2].prev = 0;

	B[1].prev = B.size() - 1;
	B[B.size() - 1].next = 1;
}

int findWagon(int t) {
	int bidx = a[idx[t]];
	int r = 1;

	for (int i = 0; i != bidx; i = B[i].next)
		r += B[i].size;

	auto it = find(w + B[bidx].i, w + B[bidx].i + B[bidx].size, t);

	r += it - (w + B[bidx].i);

	assert(it != w + B[bidx].i + B[bidx].size);
	assert(r == EncontrarVagon(t));

	return r;
}

int findBlock(int x) {
	int i, c = 1;

	for (i = B[0].next; c < x && c + B[i].size <= x; i = B[i].next)
		c += B[i].size;

	if (c == x) return i;

	int r = B.size();
	B.pb(block(B[i].i + (x - c), B[i].size - (x - c), i, B[i].next));
	B[i] = block(B[i].i, x - c, B[i].prev, r);
	B[B[r].next].prev = r;

	fill(a + B[r].i, a + B[r].i + B[r].size, r);

	return r;
}

void swapWagons(int a, int b) {
	int r = IntercambiarVagones(a, b);

	assert(r == 1);

	// x - ss ~~ se - ms ~~ me - es

	int ss = findBlock(a);
	int ms = findBlock((a + b + 1) / 2);
	int es = findBlock(b + 1);

	int x = B[ss].prev;
	int se = B[ms].prev;
	int me = B[es].prev;

	B[x].next = ms;
	B[ms].prev = x;

	B[me].next = ss;
	B[ss].prev = me;

	B[se].next = es;
	B[es].prev = se;

	if (B.size() > K * sqN)
		rebuild();

	printWagons();
}

void intercambia_vagon(int &indice, int inicio, int final) {
	if (indice < inicio || indice > final) return;

	int tamanho_mitad = (final - inicio) / 2 + 1;

	if (indice < inicio + tamanho_mitad)
		indice += tamanho_mitad;
	else
		indice -= tamanho_mitad;
}

void AcomodarFerrocarril(int n) {
	N = n;
	sqN = sqrt(N);

	for (int i = 1; i <= n; i++)
		w[i] = VagonEnPosicion(i);

	rebuild();
	printWagons();

	int inicio = 1;
	int final = n;

	int inicio_indice = findWagon(1);
	int final_indice = findWagon(n);

	while (final - 1 >= inicio) {

		int tamanho_segmento = final - inicio + 1;

		if ( (inicio_indice - inicio) * 2 <= tamanho_segmento ) {

			if (inicio_indice != inicio) {
				swapWagons(inicio, inicio + (inicio_indice - inicio) * 2 - 1);
				intercambia_vagon(final_indice, inicio, inicio + (inicio_indice - inicio) * 2 - 1);
			}

			inicio++;
			inicio_indice = findWagon(inicio);

		} else if ( (final - final_indice) * 2 <= tamanho_segmento ) {

			if (final_indice != final) {
				swapWagons(final - (final - final_indice) * 2 + 1, final);
				intercambia_vagon(inicio_indice, final - (final - final_indice) * 2 + 1, final);
			}

			final--;
			final_indice = findWagon(final);
		} else {
			int final_par = final;

			if (tamanho_segmento % 2 == 1) final_par--;

			swapWagons(inicio, final_par);
			intercambia_vagon(inicio_indice, inicio, final_par);
			intercambia_vagon(final_indice, inicio, final_par);
		}
	}
}