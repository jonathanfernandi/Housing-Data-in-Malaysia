#include <stdio.h>
#include <string.h>

char loc1[3939][255], loc2[3939][255], price[3939][255], room[3939][255], bathrooms[3939][255], carparks[3939][255], type[3939][255], area[3939][255], furnish[3939][255];

char list[3939][2300];

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
				fscanf(housingData, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", loc1[line], loc2[line], price[line], room[line], bathrooms[line], carparks[line], type[line], area[line], furnish[line]);
			}
			line++;
		}
	}
	
	for(int i = 1; i < line; i++) {
		strcpy(list[i], loc1[i]);
		strcat(list[i], loc2[i]);
		strcat(list[i], price[i]);
		strcat(list[i], room[i]);
		strcat(list[i], bathrooms[i]);
		strcat(list[i], carparks[i]);
		strcat(list[i], type[i]);
		strcat(list[i], area[i]);
		strcat(list[i], furnish[i]);
	}
	
	for(int i = 2; i < line; i++) {
		for(int j = (line - 1); j >= i; j--) {
			if(strcmp(list[j - 1], list[j]) > 0) {
				char temp[2300];
				
				strcpy(temp, loc1[j - 1]);
				strcpy(loc1[j - 1], loc1[j]);
				strcpy(loc1[j], temp);
				
				strcpy(temp, loc2[j - 1]);
				strcpy(loc2[j - 1], loc2[j]);
				strcpy(loc2[j], temp);
				
				strcpy(temp, price[j - 1]);
				strcpy(price[j - 1], price[j]);
				strcpy(price[j], temp);
				
				strcpy(temp, room[j - 1]);
				strcpy(room[j - 1], room[j]);
				strcpy(room[j], temp);
				
				strcpy(temp, bathrooms[j - 1]);
				strcpy(bathrooms[j - 1], bathrooms[j]);
				strcpy(bathrooms[j], temp);
				
				strcpy(temp, carparks[j - 1]);
				strcpy(carparks[j - 1], carparks[j]);
				strcpy(carparks[j], temp);
				
				strcpy(temp, type[j - 1]);
				strcpy(type[j - 1], type[j]);
				strcpy(type[j], temp);
				
				strcpy(temp, area[j - 1]);
				strcpy(area[j - 1], area[j]);
				strcpy(area[j], temp);
				
				strcpy(temp, furnish[j - 1]);
				strcpy(furnish[j - 1], furnish[j]);
				strcpy(furnish[j], temp);
				
				strcpy(temp, list[j - 1]);
				strcpy(list[j - 1], list[j]);
				strcpy(list[j], temp);
			}
		}
	}
	
	for(int i = 1; i < line; i++) {
		printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %d | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
	}
	
	fclose(housingData);
	
	return 0;
}
