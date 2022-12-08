#include <stdio.h>
#include <string.h>

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


int sceneInputDataDosen(Dosen **dataDosen, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferNama[50];
    char bufferNIP[20];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Nama Dosen      : ");
        fgets(bufferNama, 50, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen       : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchDosen(*dataDosen, dataSettings, bufferNIP);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data dosen baru dengan rincian sebagai berikut:\n");
            printf("Nama Dosen      : %s\n", bufferNama);
            printf("NIP Dosen       : %s\n", bufferNIP);
        }
        else {
            printf("Anda akan memodifikasi data dosen yang telah ada dengan rincian sebagai berikut:\n");
            printf("Nama Dosen (Lama)   : %s\n", (*dataDosen)[modifyPosition].nama);
            printf("Nama Dosen (Baru)   : %s\n", bufferNama);
            printf("NIP Dosen           : %s\n\n", bufferNIP);
            printf("Sebagai catatan, NIP tidak dapat dimodifikasi!\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputDosen(dataDosen, dataSettings, bufferNIP, bufferNama);
            }
            else {
                strcpy((*dataDosen)[modifyPosition].nama, bufferNama);
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("Nama Dosen      : %s\n", bufferNama);
                printf("NIP Dosen       : %s\n\n", bufferNIP);
            }
            else {
                printf("Berikut adalah rincian data yang telah berhasil Anda modifikasi:\n");
                printf("Nama Dosen (Baru)   : %s\n", bufferNama);
                printf("NIP Dosen           : %s\n\n", bufferNIP);
                printf("Sebagai catatan, NIP tidak dapat dimodifikasi!\n\n");
            }
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}