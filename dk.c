// Ben Mikailenko
// Jakob Miner
// Katie Cederdahl

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	FILE *in;
	if (argc == 1) {
		in = stdin;
	}
	else if (argc == 2) {
		in = fopen(argv[1], "r");
		if (!in) {
			perror(argv[1]);
			return 1;
		}
	}
	else {
		fprintf(stderr, "Usage: %s [input-file]\n", argv[0]);
		return 1;
	}

	int n = 0;
	double x, y;

	while(fscanf(in, "%lf %lf", &x, &y) == 2){
	 	n++;
	}

	rewind(in);
	double allX[n];
	double allY[n];
	double allA[n];
	double allD[n][n];
	n=0;

	while(fscanf(in, "%lf %lf", &x, &y) == 2){
	 	allX[n]=x;
	 	allY[n]=y;
	 	n++;
	}

	fclose(in);

	allA[0]=allY[0];

	for ( int k = 1; k < n; k++) {
		allD[k][1] = (allY[k+1] - allY[k]) / (allX[k+1] - allX[k]);
	}

	for ( int j = 2; j < n; j++) {
		for ( int k = 1; k <= (n - j); k++) {
			allD[k][j] = (allD[k+1][j-1] - allD[k][j-1]) / (allX[k+j] - allX[k]);
		}
	}


	for ( int j = 2; j < n; j++) {
		allA[j] = allD[1][j-1];
	}

	for ( int i = 0; i < n; i++) {
		printf("%f\n",allA[i]);
		//printf("%f\n",allX[i]);
		//printf("%f\n",allY[i]);
	}


	return 0;
}
