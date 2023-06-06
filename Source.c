#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "horse.h"

int main() {
	int choice;
	int numHorses = 0;
	float balance = 100.0;
	Horse* horses = malloc(10 * sizeof(Horse));  // Initial capacity of 10 horses

	do {
		printf("\nHorse Betting Game\n");
		printf("1. Add Horse\n");
		printf("2. Sort Horses\n");
		printf("3. Display Horses\n");
		printf("4. Place Bet\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addHorse(horses, &numHorses);
			break;
		case 2:
			sortHorses(horses, numHorses);
			break;
		case 3:
			displayHorses(horses, numHorses);
			break;
		case 4:
			placeBet(horses, numHorses, &balance);
			break;
		case 5:
			printf("Exiting the game.\n");
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
	} while (choice != 5);

	free(horses);
	return 0;
}
