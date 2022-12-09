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

int sceneInputDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferNRP[20];
    char bufferNama[50];
    char bufferAlamat[50];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("NRP Mahasiswa       : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }

        fflush(stdin);
        printf("Nama Mahasiswa      : ");
        fgets(bufferNama, 50, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }

        fflush(stdin);
        printf("Alamat Mahasiswa    : ");
        fgets(bufferAlamat, 50, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferAlamat) > 0) {
            bufferAlamat[strlen(bufferAlamat)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchMahasiswa(*dataMahasiswa, dataSettings, bufferNRP);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data mahasiswa baru dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa       : %s\n", bufferNRP);
            printf("Nama Mahasiswa      : %s\n", bufferNama);
            printf("Alamat Mahasiswa    : %s\n\n", bufferAlamat);
        }
        else {
            printf("Anda akan memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa               : %s\n", bufferNRP);
            printf("Nama Mahasiswa (Lama)       : %s\n", (*dataMahasiswa)[modifyPosition].nama);
            printf("Nama Mahasiswa (Baru)       : %s\n", bufferNama);
            printf("Alamat Mahasiswa (Lama)     : %s\n", (*dataMahasiswa)[modifyPosition].alamat);
            printf("Alamat Mahasiswa (Baru)     : %s\n", bufferAlamat);
            printf("Sebagai catatan, NRP tidak dapat dimodifikasi!\n\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputMahasiswa(dataMahasiswa, dataSettings, bufferNRP, bufferNama, bufferAlamat);
            }
            else {
                strcpy((*dataMahasiswa)[modifyPosition].nama, bufferNama);
                strcpy((*dataMahasiswa)[modifyPosition].alamat, bufferAlamat);
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("NRP Mahasiswa       : %s\n", bufferNRP);
                printf("Nama Mahasiswa      : %s\n", bufferNama);
                printf("Alamat Mahasiswa    : %s\n\n", bufferAlamat);
            }
            else {
                printf("Berikut adalah rincian data yang telah berhasil Anda modifikasi:\n");
                printf("NRP Mahasiswa               : %s\n", bufferNRP);
                printf("Nama Mahasiswa (Baru)       : %s\n", bufferNama);
                printf("Alamat Mahasiswa (Baru)     : %s\n", bufferAlamat);
                printf("Sebagai catatan, NRP tidak dapat dimodifikasi!\n\n");
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

int sceneInputDataMatkul(Matkul **dataMatkul, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNama[30];
    int bufferSKS;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("Nama Mata Kuliah            : ");
        fgets(bufferNama, 30, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }
        fflush(stdin);

        printf("Jumlah SKS Mata Kuliah      : ");
        scanf("%d", &bufferSKS);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchMatkul(*dataMatkul, dataSettings, bufferKode);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data mata kuliah baru dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah            : %s\n", bufferKode);
            printf("Nama Mata Kuliah            : %s\n", bufferNama);
            printf("Jumlah SKS Mata Kuliah      : %d\n\n", bufferSKS);
        }
        else {
            printf("Anda akan memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah            : %s\n", bufferKode);
            printf("Nama Mata Kuliah (Lama)     : %s\n", (*dataMatkul)[modifyPosition].nama);
            printf("Nama Mata Kuliah (Baru)     : %s\n", bufferNama);
            printf("Jumlah SKS (Lama)           : %d\n", (*dataMatkul)[modifyPosition].sks);
            printf("Jumlah SKS (Baru)           : %d\n", bufferSKS);
            printf("Sebagai catatan, kode mata kuliah tidak dapat dimodifikasi!\n\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputMatkul(dataMatkul, dataSettings, bufferKode, bufferNama, bufferSKS);
            }
            else {
                strcpy((*dataMatkul)[modifyPosition].nama, bufferNama);
                (*dataMatkul)[modifyPosition].sks = bufferSKS;
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("Kode Mata Kuliah            : %s\n", bufferKode);
                printf("Nama Mata Kuliah            : %s\n", bufferNama);
                printf("Jumlah SKS Mata Kuliah      : %d\n\n", bufferSKS);
            }
            else {
                printf("Anda akan memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
                printf("Kode Mata Kuliah            : %s\n", bufferKode);
                printf("Nama Mata Kuliah (Baru)     : %s\n", bufferNama);
                printf("Jumlah SKS (Baru)           : %d\n", bufferSKS);
                printf("Sebagai catatan, kode mata kuliah tidak dapat dimodifikasi!\n\n");
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

int sceneInputDataPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta) {
    int modifyPosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNIP[30];
    char bufferNRP[30];
    int matkulPosition, dosenPosition, mahasiswaPosition;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen Pengampu          : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }

        fflush(stdin);
        printf("NRP Peserta Kuliah          : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        matkulPosition = searchMatkul(matkul, dataSettings, bufferKode);
        dosenPosition = searchDosen(dosen, dataSettings, bufferNIP);
        mahasiswaPosition = searchMahasiswa(peserta, dataSettings, bufferNRP);
        modifyPosition = searchPesertaKuliah(*dataPesertaKuliah, dataSettings, bufferKode, bufferNIP, bufferNRP);
        if (matkulPosition == NOT_FOUND || dosenPosition == NOT_FOUND || mahasiswaPosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Anda berusaha memasukkan data yang belum terdaftar dalam sistem: \n\n");
            setColor(COLOR_DEFAULT);

            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            if (matkulPosition == NOT_FOUND) {
                printf("Nama Mata Kuliah        : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
                printf("Bobot SKS               : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
                printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            }

            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            if (dosenPosition == NOT_FOUND) {
                printf("Nama Dosen Pengampu     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            }


            printf("NRP Peserta Kuliah      : %s\n", bufferNRP);
            if (mahasiswaPosition == NOT_FOUND) {
                printf("Nama Peserta Kuliah     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            }

            printf("\nPeriksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }

        if (modifyPosition == NOT_FOUND) {
            printf("Anda akan mendaftarkan peserta kuliah dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Sebagai catatan, input nilai dilakukan dengan menu (13) Input Nilai Peserta Kuliah!\n\n");
        }
        else {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Peserta dengan data tersebut sudah terdaftar pada sistem dengan informasi sebagai berikut: \n\n");
            setColor(COLOR_DEFAULT);
            printf("Kode Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->kode);
            printf("Nama Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->nama);
            printf("Bobot SKS               : %d\n", (*dataPesertaKuliah)[modifyPosition].matkul->sks);
            printf("NIP Dosen Pengampu      : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->NIP);
            printf("Nama Dosen Pengampu     : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->nama);
            printf("NRP Peserta Kuliah      : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->NRP);
            printf("Nama Peserta Kuliah     : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->nama);

            if ((*dataPesertaKuliah[modifyPosition]).uts == SCORE_EMPTY) {
                printf("Nilai UTS               : Belum diinput\n");
            }
            else {
                printf("Nilai UTS               : %d\n", (*dataPesertaKuliah)[modifyPosition].uts);
            }

            if ((*dataPesertaKuliah[modifyPosition]).uas == SCORE_EMPTY) {
                printf("Nilai UAS               : Belum diinput\n");
            }
            else {
                printf("Nilai UAS               : %d\n", (*dataPesertaKuliah)[modifyPosition].uas);
            }

            if ((*dataPesertaKuliah[modifyPosition]).rerata == AVG_EMPTY) {
                printf("Nilai UAS               : Belum diinput\n");
            }
            else {
                printf("Nilai UAS               : %.2f\n\n", (*dataPesertaKuliah)[modifyPosition].rerata);
            }

            setColor(COLOR_RED);
            printf("Menu ini hanya digunakan untuk mendaftarkan peserta kuliah baru.\n");
            printf("Untuk melakukan input/ralat nilai, gunakan menu (13) Input Nilai Peserta Kuliah\n\n");
            setColor(COLOR_DEFAULT);

            printf("Tekan (1) untuk mencoba ulang proses input data atau tekan angka selain (1)\n");
            printf("untuk membatalkan input data dan kembali ke menu awal.\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                break;
            }
            else {
                continue;
            }
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            inputPesertaKuliah(dataPesertaKuliah, dataSettings, matkul+matkulPosition, dosen+dosenPosition, peserta+mahasiswaPosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input data peserta kuliah\n");
        }
        else {
            printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Sebagai catatan, input nilai dilakukan dengan menu (13) Input Nilai Peserta Kuliah!\n\n");
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