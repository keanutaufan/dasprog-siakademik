#include <stdio.h>
#include "../include/ErrorList.h"
#include "../include/UI.h"

void clearScreen(void) {
    printf("\e[1;1H\e[2J");
}


int tabulateDosen(Dosen *dataDosen, DataSettings *dataSettings) {
    if (dataDosen == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("=============================================================================\n");
    printf("|         NIP          |                      Nama                          |\n");
    printf("=============================================================================\n");
    for (int i = 0; i < dataSettings->structSize_Dosen; i++) {
        fprintf(stdout, "| %-20s | %-50s |\n", dataDosen[i].NIP, dataDosen[i].nama);
    }
    printf("=============================================================================\n");

    return PROCCESS_SUCCESS;
}

int tabulateMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings) {
    if (dataMahasiswa == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("==============================================================================================================\n");
    printf("|         NRP          |               Nama             |                        Alamat                      |\n");
    printf("==============================================================================================================\n");
    for (int i = 0; i < dataSettings->structSize_Mahasiswa; i++) {
        fprintf(stdout, "| %-20s | %-30s | %-50s |\n", dataMahasiswa[i].NRP, dataMahasiswa[i].nama, dataMahasiswa[i].alamat);
    }
    printf("==============================================================================================================\n");
    
    return PROCCESS_SUCCESS;
}

int tabulateMatkul(Matkul *dataMatkul, DataSettings *dataSettings) {
    if (dataMatkul == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("========================================================\n");
    printf("|    KODE    |              Nama              |   SKS  |\n");
    printf("========================================================\n");
    for (int i = 0; i < dataSettings->structSize_Matkul; i++) {
        fprintf(stdout, "| %-10s | %-30s | %-2d SKS |\n", dataMatkul[i].kode, dataMatkul[i].nama, dataMatkul[i].sks);
    }
    printf("========================================================\n");

    return PROCCESS_SUCCESS;
}

int tabulatePesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    if (dataPesertaKuliah == NULL || dataSettings == NULL || dataMatkul == NULL || dataDosen == NULL || dataPeserta == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("============================================================================================================================================================================================\n");
    printf("|   KODE     |          Nama Matkul           |       NIP Dosen      |          Nama Dosen            |  NRP Mahasiswa  |         Nama Mahasiswa         |  ETS  |  EAS  |   AVG   | Grade |\n");
    printf("============================================================================================================================================================================================\n");
    for (int i = 0; i < dataSettings->structSize_PesertaKuliah; i++) {
        fprintf(stdout, "| %-10s | %-30s | %-20s | %-30s | %-15s | %-30s | %5d | %5d | %7.2f |   %s   |\n", dataPesertaKuliah[i].matkul->kode, dataPesertaKuliah[i].matkul->nama, dataPesertaKuliah[i].dosen->NIP, dataPesertaKuliah[i].dosen->nama, dataPesertaKuliah[i].peserta->NRP, dataPesertaKuliah[i].peserta->nama, dataPesertaKuliah[i].uts, dataPesertaKuliah[i].uas, dataPesertaKuliah[i].rerata, dataPesertaKuliah[i].grade);
    }
    printf("============================================================================================================================================================================================\n");


    return ERROR_NOMEMORY;
}