#ifndef HORSE_H
#define HORSE_H

typedef struct {
	char name[50];
	int age;
	float speed;
	float odds;
} Horse;

void addHorse(Horse* horses, int* numHorses);
void sortHorses(Horse* horses, int numHorses);
void displayHorses(Horse* horses, int numHorses);
void placeBet(Horse* horses, int numHorses, float* balance);

#endif
