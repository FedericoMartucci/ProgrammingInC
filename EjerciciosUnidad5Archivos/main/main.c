#include "../../Bibliotecas/files.h"

int main()
{
    ///Exercise 1
//    createBatch("patents.dat", "wb", createPatentBatch);
//    FILE* filePointer;
//    if(openFile(&filePointer, "patents.dat", "rb") == OK){
//        traverseBinaryFile(filePointer, sizeof(tPatent), showPatent);
//    }
    ///Exercise 7
//    createBatch("employees.dat", "wb", createEmployeeBatch);
//    createBatch("students.dat", "wb", createStudentBatch);
//    FILE* filePointerStudent;
//    FILE* filePointerEmployee;
/*    if(openFile(&filePointerStudent, "students.dat", "rb") == OK){
        traverseBinaryFile(filePointerStudent, sizeof(tStudent), showStudent);
    }
    if(openFile(&filePointerEmployee, "employees.dat", "rb") == OK){
        traverseBinaryFile(filePointerEmployee, sizeof(tEmployee), showEmployee);
    }
    system("pause");
    system("cls");*/

//    if(openFile(&filePointerEmployee, "employees.dat", "r+b") == OK && openFile(&filePointerStudent, "students.dat", "r+b") == OK){
//        mergeFiles(filePointerEmployee, filePointerStudent, sizeof(tEmployee), sizeof(tStudent), increaseSalaryIfAvgGraterThan7, compareDNI);
//    }
//
//    rewind(filePointerEmployee);
//    traverseBinaryFile(filePointerEmployee, sizeof(tEmployee), showEmployee);
//    fclose(filePointerEmployee);
//    fclose(filePointerStudent);
    ///Class exercise
    /*  Tengo un maestro.dat y un novedades.dat, si se da de alta alguien en dat entonces guardo dicho registro en un
        archivo temp.dat. Si hay algún error lo guardo en un archivo errores.dat
        Nota:
            - Crear una estructura con un empleado y un char tipoNovedad. (Indice)
            - Rename renombra archivos
            - Remove borra archivos
    */
    createBatch("master.dat", "wb", createEmployeeBatch);
    createBatch("novelties.dat", "wb", createNoveltiesBatch);
    FILE* masterFilePointer;
    FILE* noveltyFilePointer;

    if(openFile(&masterFilePointer, "master.dat", "rb") != FILE_ERR && openFile(&noveltyFilePointer, "novelties.dat", "rb") != FILE_ERR){
        updateFile(masterFilePointer, noveltyFilePointer, sizeof(tEmployee), sizeof(tNovelty), updateEmployee, compareEmployeeDNI, showNoveltyErrors);
        system("pause");
        system("cls");
    }

    if(openFile(&masterFilePointer, "master.dat", "rb") == OK){
        traverseBinaryFile(masterFilePointer, sizeof(tEmployee), showEmployee);
    }

    fclose(masterFilePointer);

    return 0;
}
