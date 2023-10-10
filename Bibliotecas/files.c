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
int createStudentBatch(const char* fileName, const char* fileMode)
{
    tStudent data[] =
    {
        {10123456, "Maidana", "Carlos", 2.5},
        {20123456, "Soligo", "Pablo", 4.67},
        {40123456, "Brocani", "Agustin", 9.8},
        {42123456, "Martucci", "Federico", 10 },
        {44444444, "Cassiani", "Joaquin", 7.8},
        {45123456, "Bombon", "Simon", 1.2},
        {55555555, "Antelo", "Pedro", 6.1},
        {66666666, "Vazquez", "Juan Cruz", 7.67}
    };

    FILE* filePointer;
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}
int createEmployeeBatch(const char* fileName, const char* fileMode)
{
    tEmployee data[] =
    {
        {10123456, "Maidana", "Carlos", 40000.44},
        {20123456, "Soligo", "Pablo", 50000.55},
        {40123456, "Brocani", "Agustin", 30000.33},
        {42123456, "Martucci", "Federico", 10000.11},
        {44444444, "Cassiani", "Joaquin", 60000.66},
        {45123456, "Bombon", "Simon", 20000.22},
        {55555555, "Antelo", "Pedro", 70000.77},
        {66666666, "Vazquez", "Juan Cruz", 80000.88}
    };

    FILE* filePointer;
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}
int createNoveltiesBatch(const char* fileName, const char* fileMode)
{
    tNovelty data[] =
    {
        {{10123456, "Maidana", "Carlos", 5555.44}, 'm'},
        {{11111111, "Freire", "Nacho", 40000.44}, 'a'},
        {{20123456, "Soligo", "Pablo", 50000.55}, 'b'},
        {{42123456, "Martucci", "Federico", 99999.99}, 'm'},
        {{45123456, "Bombon", "Simon", 20000.22}, 'b'},
        {{99999999, "Dougan", "Pablo", 60000.66}, 'b'}
    };

    FILE* filePointer;
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}
int createPatentBatch(const char* fileName, const char* fileMode)
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
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}
int createBatch(const char* fileName, const char* fileMode, int(*createTypeBatch)(const char*, const char*))
{
    return createTypeBatch(fileName, fileMode);
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
	int counterRegisters = 0;

	if(!data){
        perror("Oops! Something wrong occurred.");
        return MEM_ERR;
	}

	fread(data, dataSize, 1, filePointer);
	while(!feof(filePointer)){
        counterRegisters++;
        action(data);
		fread(data, dataSize, 1, filePointer);
	}
	free(data);
	fclose(filePointer);
	return counterRegisters;
}
///TODO que pasa si llamo al cmp dentro de la funcion de accion?

int updateFile(FILE* masterFilePointer, FILE* noveltiesFilePointer, size_t masterDataSize, size_t noveltyDataSize, int (*action)(void* data, const void* data2, int), int (*compare)(const void*, const void*), void(*error)(const void*))
{
    void* masterData = malloc(masterDataSize);
    void* noveltyDataAux = malloc(masterDataSize);
    void* noveltyData = malloc(noveltyDataSize);
    FILE* tempFilePointer;
    int cmpResult;
    int actionResult;

    if(!masterData || !noveltyData || !noveltyDataAux){
        free(masterData);
        free(noveltyData);
        perror("Oops! Something wrong occurred.");
        return MEM_ERR;
	}

    if(openFile(&tempFilePointer, "temp.dat", "wb") == FILE_ERR){
        free(masterData);
        free(noveltyData);
        return UPDATE_ERR;
    }

    fread(masterData, masterDataSize, 1, masterFilePointer);
    fread(noveltyData, noveltyDataSize, 1, noveltiesFilePointer);

    while(!feof(masterFilePointer) && !feof(noveltiesFilePointer)){
        cmpResult = compare(masterData, noveltyData);
        if(cmpResult == 0){
            if((actionResult = action(noveltyDataAux, noveltyData, cmpResult)) == 1)//if it is not an error, it will write the register in the file
                fwrite(noveltyDataAux, masterDataSize, 1, tempFilePointer);
            else if(actionResult == 0)
                error(noveltyData);
            fread(masterData, masterDataSize, 1, masterFilePointer);
            fread(noveltyData, noveltyDataSize, 1, noveltiesFilePointer);
        }else if(cmpResult > 0){
            if((actionResult = action(noveltyDataAux, noveltyData, cmpResult)) == 1)//if it is not an error, it will write the register in the file
                fwrite(noveltyDataAux, masterDataSize, 1, tempFilePointer);
            else if(actionResult == 0)
                error(noveltyData);
            fread(noveltyData, noveltyDataSize, 1, noveltiesFilePointer);
        }else{
            fwrite(masterData, masterDataSize, 1, tempFilePointer);
            fread(masterData, masterDataSize, 1, masterFilePointer);
        }
    }
    while(!feof(masterFilePointer)){
        fwrite(masterData, masterDataSize, 1, tempFilePointer);
        fread(masterData, masterDataSize, 1, masterFilePointer);
    }
    cmpResult = 1;
    while(!feof(noveltiesFilePointer)){
        if((actionResult = action(noveltyDataAux, noveltyData, cmpResult)) == 1)
            fwrite(noveltyDataAux, masterDataSize, 1, tempFilePointer);
        else if(actionResult == 0)
            error(noveltyData);
        fread(noveltyData, noveltyDataSize, 1, noveltiesFilePointer);
    }

    free(masterData);
    free(noveltyData);

    fclose(tempFilePointer);
    fclose(masterFilePointer);
    fclose(noveltiesFilePointer);

    remove("master.dat");
    rename("temp.dat", "master.dat");

    return OK;
}
int updateEmployee(void* destiny, const void* source, int cmp)
{
    if((toupper(((tNovelty*)source)->noveltyType) == 'M' && cmp == 0) ||
        (toupper(((tNovelty*)source)->noveltyType) == 'A' && cmp > 0)){
        ((tEmployee*)destiny)->dni = ((tNovelty*)source)->employee.dni;
        strcpy(((tEmployee*)destiny)->surname,((tNovelty*)source)->employee.surname);
        strcpy(((tEmployee*)destiny)->name,((tNovelty*)source)->employee.name);
        ((tEmployee*)destiny)->salary = ((tNovelty*)source)->employee.salary;
    }
    else if(toupper(((tNovelty*)source)->noveltyType) == 'B' && cmp == 0)
        return -1;
    else
        return 0;
    return 1;
}
int compareEmployeeDNI(const void* employee, const void* novelty)
{
    return ((tEmployee*)employee)->dni - ((tNovelty*)novelty)->employee.dni;
}

int mergeFiles(FILE* filePointer1, FILE* filePointer2, size_t dataSize1, size_t dataSize2, void (*action)(void* data, const void* data2), int (*compare)(const void*, const void*))
{
    void* data1 = malloc(dataSize1);
    void* data2 = malloc(dataSize2);
    int cmpResult;

    fread(data1, dataSize1, 1, filePointer1);
    fread(data2, dataSize2, 1, filePointer2);

    while(!feof(filePointer1) || !feof(filePointer2)){
        cmpResult = compare(data1, data2);
        if(cmpResult == 0){
            action(data1, data2);
            fseek(filePointer1, dataSize1 * (-1L), SEEK_CUR);
            fwrite(data1, dataSize1, 1, filePointer1);
            fflush(filePointer1);
            fread(data1, dataSize1, 1, filePointer1);
            fread(data2, dataSize2, 1, filePointer2);
        }else if(cmpResult > 0)
                fread(data1, dataSize1, 1, filePointer1);
            else
                fread(data2, dataSize2, 1, filePointer2);
    }
    free(data1);
    free(data2);

    return OK;
}

int compareDNI(const void* employee, const void* student)
{
    return ((tEmployee*)employee)->dni - ((tStudent*)student)->dni;
}

void increaseSalaryIfAvgGraterThan7(void* employee, const void* student)
{
    if(((tStudent*)student)->average > 7)
        ((tEmployee*)employee)->salary *= 1.0728;
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
void showStudent(const void* data)
{
    printf("Student:\nDNI: \t\t%d\nSurname: \t%s\nName: \t\t%s\nAverage: \t %.2f\n", ((tStudent*)data)->dni,
                                                                                        ((tStudent*)data)->surname,
                                                                                        ((tStudent*)data)->name,
                                                                                        ((tStudent*)data)->average);
    printf("=====================================================\n");
}
void showEmployee(const void* data){
    printf("Employee: \nDNI: \t\t%d\nSurname: \t%s\nName: \t\t%s\nSalary: \tU$D %.2f\n",    ((tEmployee*)data)->dni,
                                                                                            ((tEmployee*)data)->surname,
                                                                                            ((tEmployee*)data)->name,
                                                                                            ((tEmployee*)data)->salary);
    printf("=====================================================\n");
}
void showNoveltyErrors(const void* data){
    printf("\t\t\tERROR\t\t\t\n");
    printf("Novelty: \nDNI: \t\t%d\nSurname: \t%s\nName: \t\t%s\nSalary: \tU$D %.2f\nType: \t\t%c\n",   ((tNovelty*)data)->employee.dni,
                                                                                                        ((tNovelty*)data)->employee.surname,
                                                                                                        ((tNovelty*)data)->employee.name,
                                                                                                        ((tNovelty*)data)->employee.salary,
                                                                                                        ((tNovelty*)data)->noveltyType);
    printf("=====================================================\n");
}
