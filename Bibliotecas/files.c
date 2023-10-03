#include "files.h"
/*typedef struct
{
    int year;
    int month;
    int day;
}tDate;

typedef struct
{
    char patent[SIZE];
    int quotaNumber;
    char nya[SIZE];
    int dni;
    tDate expirationDate;
    float amount;
}tPatent;*/
int createBatch()
{
    tPatent data[] =
    {
        {"AA100XU",52,"Federico Martucci",42123456,{2023,10,9},375.22 },
        {"FUT316",350,"Simon Bombon",45123456,{2024,12,9},50000 },
        {"NWO870",100,"Agustin Brocani",40123456,{2023,11,15},105.5 },
        {"ABC123",999,"Carlos Maidana",10123456,{2023,11,22},17.9 },
        {"AG777GD",1,"Pablo Soligo",20123456,{2023,10,10},500.5 }
    };

    FILE* filePointer;
    openFile(&filePointer, "patents.dat", "wb");

    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}

int openFile(FILE** filePointer, const char* fileName, const char* mode)
{
    *filePointer = fopen(fileName, mode);

    if(!*filePointer){
        perror("Oops! Something wrong occurred.");
        return FILE_ERR;
    }
    return OK;
}

int traverseBinaryFile(FILE* filePointer, size_t dataSize, void (*action)(const void* data)){
	void* data = malloc(dataSize);

	if(!data){
        perror("Oops! Something wrong occurred.");
        return MEM_ERR;
	}

	fread(data, dataSize, 1, filePointer);
	while(!feof(filePointer)){
		action(data);
		fread(data, dataSize, 1, filePointer);
	}

	free(data);
	fclose(filePointer);
	return OK;
}

void showPatent(const void* data){
    printf("Patent: \t%s\nQuota number: \t%d\nNya: \t\t%s\nDNI: \t\t%d\nDate:\t\t%02d-%02d-%d\nAmount: \tU$D %.2f\n",   ((tPatent*)data)->patent,
                                                                                                                        ((tPatent*)data)->quotaNumber,
                                                                                                                        ((tPatent*)data)->nya,
                                                                                                                        ((tPatent*)data)->dni,
                                                                                                                        ((tPatent*)data)->expirationDate.day,
                                                                                                                        ((tPatent*)data)->expirationDate.month,
                                                                                                                        ((tPatent*)data)->expirationDate.year,
                                                                                                                        ((tPatent*)data)->amount);
    printf("=====================================================\n");
}
