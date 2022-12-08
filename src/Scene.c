#include <stdio.h>

#include "../include/Data.h"
#include "../include/UI.h"
#include "../include/ErrorList.h"
#include "../include/Scene.h"

int sceneLihatDataDosen(Dosen *dataDosen, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("=============================================================================\n");
        printf("|                             Lihat Data Dosen                              |\n");
        printf("=============================================================================\n\n");
        setColor(COLOR_DEFAULT);
        if (dataSettings->structSize_Dosen == 0) {
            setColor(COLOR_RED);
            printf("           Data Anda masih kosong, silakan lakukan input data!         \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateDosen(dataDosen, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS;
}

int sceneLihatDataMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Lihat Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
    
        setColor(COLOR_DEFAULT);
        if (dataSettings->structSize_Mahasiswa == 0) {
            setColor(COLOR_RED);
            printf("                               Data Anda masih kosong, silakan lakukan input data!                         \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateMahasiswa(dataMahasiswa, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}

int sceneLihatDataMatkul(Matkul *dataMatkul, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("========================================================\n");
        printf("|                Lihat Data Mata Kuliah                |\n");
        printf("========================================================\n\n");

        setColor(COLOR_DEFAULT);
        if (dataSettings->structSize_Matkul == 0) {
            setColor(COLOR_RED);
            printf("   Data Anda masih kosong, silakan lakukan input data!  \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateMatkul(dataMatkul, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}

int sceneLihatDataPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("============================================================================================================================================================================================\n");
        printf("|                                                                                   Lihat Data Peserta Kuliah                                                                              |\n");
        printf("============================================================================================================================================================================================\n\n");
    

        setColor(COLOR_DEFAULT);
        if (dataSettings->structSize_PesertaKuliah == 0) {
            setColor(COLOR_RED);
            printf("                                                                      Data Anda masih kosong, silakan lakukan input data!                                                                   \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulatePesertaKuliah(dataPesertaKuliah, dataSettings, dataMatkul, dataDosen, dataPeserta);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}