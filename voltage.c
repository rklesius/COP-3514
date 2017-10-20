//This program calculates the voltage for an experiement that will be carried out
//repeated using an ac voltage signal.  The signal is to have one of three values,
//depending on the time since the beginning of the experiment
//By Rachel Klesius

#include <stdio.h>
#include <math.h>

int main(void){
	double t, v;
	printf("time(sec)\tvoltage\n");
	for(t = 0.0, v = 0.0; t <= 12; t += 0.5){
		if(t < 1)
			v = 0.5 * sin(2 * t);
		if(t >= 1.0 && t <= 10.0)
			v = sin(t);
		if(t > 10.0)
			v = sin(10.0);
		printf("%.2lf\t\t%.2lf\n", t, v);
	}
	return 0;
}

