#include "../../Bibliotecas/files.h"

int main()
{
    createBatch();
    FILE* filePointer;
    if(openFile(&filePointer, "patents.dat", "rb") == OK){
        traverseBinaryFile(filePointer, sizeof(tPatent), showPatent);
    }

    return 0;
}
