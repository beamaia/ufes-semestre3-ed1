#include <stdio.h>
#include <stdlib.h>

//EN: Show the value of each int
//PT: Mostra o valor de cada int
void show_values(int *p1, int *p2, int *p3, int *p4) {
    printf("V1: %d\nV2: %d\nV3: %d\nV4: %d\n", *p1, *p2, *p3, *p4);
}

//EN: Add two to each int
//PT: Soma dois em cada int
void add_two(int *p1, int *p2, int *p3, int *p4) {
	*p1 += 2;
	*p2 += 2;
	*p3 += 2;
	*p4 += 2;
}

//EN: Elevate each int to the second power
//PT: Eleva cada numero ao quadrado
void elevate_to_second_power(int *p1, int *p2, int *p3, int *p4) {
	*p1 *= *p1;
	*p2 *= *p2;
	*p3 *= *p3;
	*p4 *= *p4;
}

//EN: Changes the value of each int
//PT: Muda o valor de cada int
void change_value(int *p1, int *p2, int *p3, int *p4) {
    printf("Add 4 new values\n");
	scanf("%d%d%d%d", p1, p2, p3, p4);
}

//EN: Manipulates int according to the user
//PT: Manipula int de acordo com o usuario
void manipulate_int(int *p1, int *p2, int *p3, int *p4) {
	int choice, repeat = 1;	
	printf("Insert 4 numbers:\n");
	scanf("%d%d%d%d", p1, p2, p3, p4);
	
	while(repeat) {
		printf("What do you want to do:\n");
		printf("(1) Show values\n");
		printf("(2) Add 2 to all numbers\n");
		printf("(3) Elevate to second power\n");
		printf("(4) Add new values\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1: show_values(p1, p2, p3, p4);
					break;
			case 2:	add_two(p1, p2, p3, p4);
					break;	
			case 3: elevate_to_second_power(p1, p2, p3, p4);
					break;
			case 4:	change_value(p1, p2, p3, p4);
		}

		printf("Do you want to exit?\n");
		printf("(1) Yes (2) No\n");
		scanf("%d", &repeat);
		if(repeat == 1) {
			repeat = 0;
		} else {
			system("clear");
		}
	}
}

int main() {
    int v1, v2, v3, v4;

	manipulate_int(&v1, &v2, &v3, &v4);	
    return 0;
}
