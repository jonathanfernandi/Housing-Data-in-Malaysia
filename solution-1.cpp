#include <stdio.h>
#include <string.h>

char loc1[3939][255], loc2[3939][255];
int price[3939], room[3939], bathrooms[3939], carparks[3939];
char type[3939][255];
int area[3939];
char furnish[3939][255];

char loc1Value[3939][255];
int uniqueLoc1Value = 0;
int loc1Frequency[3939];
char loc1MaximumValue[255];
int loc1MaximumFrequency = 0;
char loc1MinimumValue[255];
int loc1MinimumFrequency = 0;

char loc2Value[3939][255];
int uniqueLoc2Value = 0;
int loc2Frequency[3939];
char loc2MaximumValue[255];
int loc2MaximumFrequency = 0;
char loc2MinimumValue[255];
int loc2MinimumFrequency = 0;

int roomValue[3939];
int uniqueRoomValue = 0;
int roomFrequency[3939];
int roomMaximumValue;
int roomMaximumFrequency = 0;
int roomMinimumValue;
int roomMinimumFrequency = 0;

int bathroomsValue[3939];
int uniqueBathroomsValue = 0;
int bathroomsFrequency[3939];
int bathroomsMaximumValue;
int bathroomsMaximumFrequency = 0;
int bathroomsMinimumValue;
int bathroomsMinimumFrequency = 0;

int carparksValue[3939];
int uniqueCarparksValue = 0;
int carparksFrequency[3939];
int carparksMaximumValue;
int carparksMaximumFrequency = 0;
int carparksMinimumValue;
int carparksMinimumFrequency = 0;

char typeValue[3939][255];
int uniqueTypeValue = 0;
int typeFrequency[3939];
char typeMaximumValue[255];
int typeMaximumFrequency = 0;
char typeMinimumValue[255];
int typeMinimumFrequency = 0;

char furnishValue[3939][255];
int uniqueFurnishValue = 0;
int furnishFrequency[3939];
char furnishMaximumValue[255];
int furnishMaximumFrequency = 0;
char furnishMinimumValue[255];
int furnishMinimumFrequency = 0;

int main() {
	FILE *housingData = fopen("file.csv", "r");
	
	int line = 0;
	if(housingData == NULL) {
		puts("Data does not exist!");
		return 0;
	} else {
		while(!feof(housingData)) {
			if(line == 0) {
				char header[2300];
				fscanf(housingData, "%[^\n]\n", header);
			} else {
				fscanf(housingData, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", loc1[line], loc2[line], &price[line], &room[line], &bathrooms[line], &carparks[line], type[line], &area[line], furnish[line]);
				
				if(line == 1) {
					uniqueLoc1Value++;
					strcpy(loc1Value[uniqueLoc1Value], loc1[line]);
					loc1Frequency[uniqueLoc1Value]++;
					
					uniqueLoc2Value++;
					strcpy(loc2Value[uniqueLoc2Value], loc2[line]);
					loc2Frequency[uniqueLoc2Value]++;
					
					uniqueRoomValue++;
					roomValue[uniqueRoomValue] = room[line];
					roomFrequency[uniqueRoomValue]++;
					
					uniqueBathroomsValue++;
					bathroomsValue[uniqueBathroomsValue] = bathrooms[line];
					bathroomsFrequency[uniqueBathroomsValue]++;
					
					uniqueCarparksValue++;
					carparksValue[uniqueCarparksValue] = carparks[line];
					carparksFrequency[uniqueCarparksValue]++;
					
					uniqueTypeValue++;
					strcpy(typeValue[uniqueTypeValue], type[line]);
					typeFrequency[uniqueTypeValue]++;
					
					uniqueFurnishValue++;
					strcpy(furnishValue[uniqueFurnishValue], furnish[line]);
					furnishFrequency[uniqueFurnishValue]++;
				} else {
					for(int i = 1; i <= uniqueLoc1Value; i++) {
						if(strcmp(loc1[line], loc1Value[i]) == 0) {
							loc1Frequency[uniqueLoc1Value]++;
							break;
						} else if(i == uniqueLoc1Value) {
							uniqueLoc1Value++;
							strcpy(loc1Value[uniqueLoc1Value], loc1[line]);
							loc1Frequency[uniqueLoc1Value]++;
						}
					}
					
					for(int i = 1; i <= uniqueLoc2Value; i++) {
						if(strcmp(loc2[line], loc2Value[i]) == 0) {
							loc2Frequency[uniqueLoc2Value]++;
							break;
						} else if(i == uniqueLoc2Value) {
							uniqueLoc2Value++;
							strcpy(loc2Value[uniqueLoc2Value], loc2[line]);
							loc2Frequency[uniqueLoc2Value]++;
						}
					}
					
					for(int i = 1; i <= uniqueRoomValue; i++) {
						if(room[line] == roomValue[i]) {
							roomFrequency[uniqueRoomValue]++;
							break;
						} else if(i == uniqueRoomValue) {
							uniqueRoomValue++;
							roomValue[uniqueRoomValue] = room[line];
							roomFrequency[uniqueRoomValue]++;
						}
					}
					
					for(int i = 1; i <= uniqueBathroomsValue; i++) {
						if(bathrooms[line] == bathroomsValue[i]) {
							bathroomsFrequency[uniqueBathroomsValue]++;
							break;
						} else if(i == uniqueBathroomsValue) {
							uniqueBathroomsValue++;
							bathroomsValue[uniqueBathroomsValue] = bathrooms[line];
							bathroomsFrequency[uniqueBathroomsValue]++;
						}
					}
					
					for(int i = 1; i <= uniqueCarparksValue; i++) {
						if(carparks[line] == carparksValue[i]) {
							carparksFrequency[uniqueCarparksValue]++;
							break;
						} else if(i == uniqueCarparksValue) {
							uniqueCarparksValue++;
							carparksValue[uniqueCarparksValue] = carparks[line];
							carparksFrequency[uniqueCarparksValue]++;
						}
					}
					
					for(int i = 1; i <= uniqueTypeValue; i++) {
						if(strcmp(type[line], typeValue[i]) == 0) {
							typeFrequency[uniqueTypeValue]++;
							break;
						} else if(i == uniqueTypeValue) {
							uniqueTypeValue++;
							strcpy(typeValue[uniqueTypeValue], type[line]);
							typeFrequency[uniqueTypeValue]++;
						}
					}
					
					for(int i = 1; i <= uniqueFurnishValue; i++) {
						if(strcmp(furnish[line], furnishValue[i]) == 0) {
							furnishFrequency[uniqueFurnishValue]++;
							break;
						} else if(i == uniqueFurnishValue) {
							uniqueFurnishValue++;
							strcpy(furnishValue[uniqueFurnishValue], furnish[line]);
							furnishFrequency[uniqueFurnishValue]++;
						}
					}
				}
			}
			line++;
		}
	}
	
	char columnName[255];
	printf("Enter column name: ");
	scanf("%[^\n]", columnName);
	getchar();
	puts("");
	
	if(strcmp(columnName, "loc1") == 0) {
		for(int i = 1; i <= uniqueLoc1Value; i++) {
			printf("%s : %d\n", loc1Value[i], loc1Frequency[i]);
		}
		
		for(int i = 1; i <= uniqueLoc1Value; i++) {
			if(i == 1) {
				strcpy(loc1MaximumValue, loc1Value[i]);
				loc1MaximumFrequency = loc1Frequency[i];
				strcpy(loc1MinimumValue, loc1Value[i]);
				loc1MinimumFrequency = loc1Frequency[i];
			} else {
				if(loc1Frequency[i] > loc1MaximumFrequency) {
					strcpy(loc1MaximumValue, loc1Value[i]);
					loc1MaximumFrequency = loc1Frequency[i];
				}
				
				if(loc1Frequency[i] < loc1MinimumFrequency) {
					strcpy(loc1MinimumValue, loc1Value[i]);
					loc1MinimumFrequency = loc1Frequency[i];
				}
			}
		}
		
		printf("Maximum value: %s with frequency: %d\n", loc1MaximumValue, loc1MaximumFrequency);
		printf("Minimum value: %s with frequency: %d\n", loc1MinimumValue, loc1MinimumFrequency);
	} else if(strcmp(columnName, "loc2") == 0) {
		for(int i = 1; i <= uniqueLoc2Value; i++) {
			printf("%s : %d\n", loc2Value[i], loc2Frequency[i]);
		}
		
		for(int i = 1; i <= uniqueLoc2Value; i++) {
			if(i == 1) {
				strcpy(loc2MaximumValue, loc2Value[i]);
				loc2MaximumFrequency = loc2Frequency[i];
				strcpy(loc2MinimumValue, loc2Value[i]);
				loc2MinimumFrequency = loc2Frequency[i];
			} else {
				if(loc2Frequency[i] > loc2MaximumFrequency) {
					strcpy(loc2MaximumValue, loc2Value[i]);
					loc2MaximumFrequency = loc2Frequency[i];
				}
				
				if(loc2Frequency[i] < loc2MinimumFrequency) {
					strcpy(loc2MinimumValue, loc2Value[i]);
					loc2MinimumFrequency = loc2Frequency[i];
				}
			}
		}
		
		printf("Maximum value: %s with frequency: %d\n", loc2MaximumValue, loc2MaximumFrequency);
		printf("Minimum value: %s with frequency: %d\n", loc2MinimumValue, loc2MinimumFrequency);
	} else if(strcmp(columnName, "room") == 0) {
		for(int i = 1; i <= uniqueRoomValue; i++) {
			printf("%d : %d\n", roomValue[i], roomFrequency[i]);
		}
		
		for(int i = 1; i <= uniqueRoomValue; i++) {
			if(i == 1) {
				roomMaximumValue = roomValue[i];
				roomMaximumFrequency = roomFrequency[i];
				roomMinimumValue = roomValue[i];
				roomMinimumFrequency = roomFrequency[i];
			} else {
				if(roomFrequency[i] > roomMaximumFrequency) {
					roomMaximumValue = roomValue[i];
					roomMaximumFrequency = roomFrequency[i];
				}
				
				if(roomFrequency[i] < roomMinimumFrequency) {
					roomMinimumValue = roomValue[i];
					roomMinimumFrequency = roomFrequency[i];
				}
			}
		}
		
		printf("Maximum value: %d with frequency: %d\n", roomMaximumValue, roomMaximumFrequency);
		printf("Minimum value: %d with frequency: %d\n", roomMinimumValue, roomMinimumFrequency);
	} else if(strcmp(columnName, "bathrooms") == 0) {
		for(int i = 1; i <= uniqueBathroomsValue; i++) {
			printf("%d : %d\n", bathroomsValue[i], bathroomsFrequency[i]);
		}
		
		for(int i = 1; i <= uniqueBathroomsValue; i++) {
			if(i == 1) {
				bathroomsMaximumValue = bathroomsValue[i];
				bathroomsMaximumFrequency = bathroomsFrequency[i];
				bathroomsMinimumValue = bathroomsValue[i];
				bathroomsMinimumFrequency = bathroomsFrequency[i];
			} else {
				if(bathroomsFrequency[i] > bathroomsMaximumFrequency) {
					bathroomsMaximumValue = bathroomsValue[i];
					bathroomsMaximumFrequency = bathroomsFrequency[i];
				}
				
				if(bathroomsFrequency[i] < bathroomsMinimumFrequency) {
					bathroomsMinimumValue = bathroomsValue[i];
					bathroomsMinimumFrequency = bathroomsFrequency[i];
				}
			}
		}
		
		printf("Maximum value: %d with frequency: %d\n", bathroomsMaximumValue, bathroomsMaximumFrequency);
		printf("Minimum value: %d with frequency: %d\n", bathroomsMinimumValue, bathroomsMinimumFrequency);
	} else if(strcmp(columnName, "carparks") == 0) {
		for(int i = 1; i <= uniqueCarparksValue; i++) {
			printf("%d : %d\n", carparksValue[i], carparksFrequency[i]);
		}
		
		for(int i = 1; i <= uniqueCarparksValue; i++) {
			if(i == 1) {
				carparksMaximumValue = carparksValue[i];
				carparksMaximumFrequency = carparksFrequency[i];
				carparksMinimumValue = carparksValue[i];
				carparksMinimumFrequency = carparksFrequency[i];
			} else {
				if(carparksFrequency[i] > carparksMaximumFrequency) {
					carparksMaximumValue = carparksValue[i];
					carparksMaximumFrequency = carparksFrequency[i];
				}
				
				if(carparksFrequency[i] < carparksMinimumFrequency) {
					carparksMinimumValue = carparksValue[i];
					carparksMinimumFrequency = carparksFrequency[i];
				}
			}
		}
		
		printf("Maximum value: %d with frequency: %d\n", bathroomsMaximumValue, bathroomsMaximumFrequency);
		printf("Minimum value: %d with frequency: %d\n", bathroomsMinimumValue, bathroomsMinimumFrequency);
	} else if(strcmp(columnName, "type") == 0) {
		for(int i = 1; i <= uniqueTypeValue; i++) {
			printf("%s : %d\n", typeValue[i], typeFrequency[i]);
		}
		
		for(int i = 1; i <= uniqueTypeValue; i++) {
			if(i == 1) {
				strcpy(typeMaximumValue, typeValue[i]);
				typeMaximumFrequency = typeFrequency[i];
				strcpy(typeMinimumValue, typeValue[i]);
				typeMinimumFrequency = typeFrequency[i];
			} else {
				if(typeFrequency[i] > typeMaximumFrequency) {
					strcpy(typeMaximumValue, typeValue[i]);
					typeMaximumFrequency = typeFrequency[i];
				}
				
				if(typeFrequency[i] < typeMinimumFrequency) {
					strcpy(typeMinimumValue, typeValue[i]);
					typeMinimumFrequency = typeFrequency[i];
				}
			}
		}
		
		printf("Maximum value: %s with frequency: %d\n", typeMaximumValue, typeMaximumFrequency);
		printf("Minimum value: %s with frequency: %d\n", typeMinimumValue, typeMinimumFrequency);
	} else if(strcmp(columnName, "furnish") == 0) {
		for(int i = 1; i <= uniqueFurnishValue; i++) {
			printf("%s : %d\n", furnishValue[i], furnishFrequency[i]);
		}
		
		for(int i = 1; i <= uniqueFurnishValue; i++) {
			if(i == 1) {
				strcpy(furnishMaximumValue, furnishValue[i]);
				furnishMaximumFrequency = furnishFrequency[i];
				strcpy(furnishMinimumValue, furnishValue[i]);
				furnishMinimumFrequency = furnishFrequency[i];
			} else {
				if(furnishFrequency[i] > furnishMaximumFrequency) {
					strcpy(furnishMaximumValue, furnishValue[i]);
					furnishMaximumFrequency = furnishFrequency[i];
				}
				
				if(furnishFrequency[i] < furnishMinimumFrequency) {
					strcpy(furnishMinimumValue, furnishValue[i]);
					furnishMinimumFrequency = furnishFrequency[i];
				}
			}
		}
		
		printf("Maximum value: %s with frequency: %d\n", furnishMaximumValue, furnishMaximumFrequency);
		printf("Minimum value: %s with frequency: %d\n", furnishMinimumValue, furnishMinimumFrequency);
	} else if(strcmp(columnName, "area") == 0) {
		int minimumValue, maximumValue;
		double averageValue = 0.00;
		for(int i = 1; i < line; i++) {
			if(i == 1) {
				minimumValue = area[i];
				maximumValue = area[i];
			} else {
				if(area[i] < minimumValue) {
					minimumValue = area[i];
				}
				
				if(area[i] > maximumValue) {
					maximumValue = area[i];
				}
			}
			
			averageValue += area[i];
		}
		averageValue /= 3939.00;
		
		printf("Minimum value: %d\n", minimumValue);
		printf("Maximum value: %d\n", maximumValue);
		printf("Average value: %.2lf\n", averageValue);
	} else if(strcmp(columnName, "price") == 0) {
		int minimumValue, maximumValue;
		double averageValue = 0.00;
		for(int i = 1; i < line; i++) {
			if(i == 1) {
				minimumValue = price[i];
				maximumValue = price[i];
			} else {
				if(price[i] < minimumValue) {
					minimumValue = price[i];
				}
				
				if(price[i] > maximumValue) {
					maximumValue = price[i];
				}
			}
			
			averageValue += price[i];
		}
		averageValue /= 3939.00;
		
		printf("Minimum value: %d\n", minimumValue);
		printf("Maximum value: %d\n", maximumValue);
		printf("Average value: %.2lf\n", averageValue);
	} else {
		printf("Column \"%s\" does not exist!\n", columnName);
	}
	
	fclose(housingData);
	
	return 0;
}
