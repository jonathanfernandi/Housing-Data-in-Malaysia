#include <stdio.h>
#include <string.h>

char loc1[3939][255], loc2[3939][255], price[3939][255], room[3939][255], bathrooms[3939][255], carparks[3939][255], type[3939][255], area[3939][255], furnish[3939][255];

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
	
	char dataX[255], columnName[255];
	printf("Type \"[DataX] in [ColumnName]\" to search: ");
	scanf("%s in %[^\n]", dataX, columnName);
	getchar();
	puts("");
	
	if(strcmp(columnName, "loc1") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(loc1[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "loc2") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(loc2[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "room") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(room[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "bathrooms") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(bathrooms[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "carparks") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(carparks[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "type") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(type[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "furnish") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(furnish[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else {
		printf("Column \"%s\" does not exist!\n", columnName);
	}
	
	fclose(housingData);
	
	return 0;
}
