#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "horse.h"

void addHorse(Horse* horses, int* numHorses) {
	Horse newHorse;
	printf("Enter horse name: ");
	scanf("%s", newHorse.name);
	printf("Enter horse age: ");
	scanf("%d", &newHorse.age);
	printf("Enter horse speed: ");
	scanf("%f", &newHorse.speed);
	printf("Enter horse odds: ");
	scanf("%f", &newHorse.odds);

	horses[*numHorses] = newHorse;
	(*numHorses)++;
}

int compareHorsesByAge(const void* a, const void* b) {
	const Horse* horseA = (const Horse*)a;
	const Horse* horseB = (const Horse*)b;
	return horseA->age - horseB->age;
}

int compareHorsesBySpeed(const void* a, const void* b) {
	const Horse* horseA = (const Horse*)a;
	const Horse* horseB = (const Horse*)b;
	if (horseA->speed < horseB->speed) {
		return -1;
	}
	else if (horseA->speed > horseB->speed) {
		return 1;
	}
	else {
		return 0;
	}
}

int compareHorsesByName(const void* a, const void* b) {
	const Horse* horseA = (const Horse*)a;
	const Horse* horseB = (const Horse*)b;
	return strcmp(horseA->name, horseB->name);
}

void sortHorses(Horse* horses, int numHorses) {
	int choice;
	printf("Sort horses by:\n");
	printf("1. Age\n");
	printf("2. Speed\n");
	printf("3. Name\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		qsort(horses, numHorses, sizeof(Horse), compareHorsesByAge);
		break;
	case 2:
		qsort(horses, numHorses, sizeof(Horse), compareHorsesBySpeed);
		break;
	case 3:
		qsort(horses, numHorses, sizeof(Horse), compareHorsesByName);
		break;
	default:
		printf("Invalid choice.\n");
		break;
	}
}

void displayHorses(Horse* horses, int numHorses) {
	printf("Horse List:\n");
	for (int i = 0; i < numHorses; i++) {
		printf("Horse %d:\n", i + 1);
		printf("Name: %s\n", horses[i].name);
		printf("Age: %d\n", horses[i].age);
		printf("Speed: %.2f\n", horses[i].speed);
		printf("Odds: %.2f\n", horses[i].odds);
		printf("-----------------\n");
	}
}

void placeBet(Horse* horses, int numHorses, float* balance) {
	int choice;
	printf("Available balance: $%.2f\n", *balance);
	printf("Select a horse to bet on (1-%d): ", numHorses);
	scanf("%d", &choice);

	if (choice >= 1 && choice <= numHorses) {
		float betAmount;
		printf("Enter the bet amount: ");
		scanf("%f", &betAmount);

		if (betAmount > * balance) {
			printf("Insufficient balance.\n");
		}
		else {
			Horse selectedHorse = horses[choice - 1];
			float payout = betAmount * selectedHorse.odds;

			printf("You placed a bet of $%.2f on %s.\n", betAmount, selectedHorse.name);

			// Simulating the race
			printf("Race in progress...\n");
			int winner = rand() % numHorses;
			if (winner == choice - 1) {
				printf("Congratulations! Your horse %s won!\n", selectedHorse.name);
				printf("You won $%.2f\n", payout);
				*balance += payout;
			}
			else {
				printf("Oops! Your horse %s didn't win.\n", selectedHorse.name);
				printf("You lost $%.2f\n", betAmount);
				*balance -= betAmount;
			}
		}
	}
	else {
		printf("Invalid horse selection.\n");
	}
}
