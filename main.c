#include <stdio.h>
#include <malloc.h>
#include "include/UI.h"
#include "include/Data.h"
#include "include/Debug.h"
#include "include/Storage.h"
#include "include/Scene.h"

#include <string.h>

int main() {
    DataSettings dataSettings;

    Dosen *dataDosen = initializeEmptyData();
    Mahasiswa *dataMahasiswa = initializeEmptyData();
    Matkul *dataMatkul = initializeEmptyData();
    PesertaKuliah *dataPesertaKuliah = initializeEmptyData();

    loadSettings("bin/d_settings.dat", &dataSettings);
    dataDosen = realloc(dataDosen, dataSettings.structSize_Dosen * sizeof(Dosen));
    dataMahasiswa = realloc(dataMahasiswa, dataSettings.structSize_Mahasiswa * sizeof(Mahasiswa));
    dataMatkul = realloc(dataMatkul, dataSettings.structSize_Matkul * sizeof(Matkul));
    dataPesertaKuliah = realloc(dataPesertaKuliah, dataSettings.structSize_PesertaKuliah * sizeof(PesertaKuliah));
    loadData("bin/d_dosen.dat", dataDosen, sizeof(Dosen), dataSettings.structSize_Dosen);
    loadData("bin/d_mahasiswa.dat", dataMahasiswa, sizeof(Mahasiswa), dataSettings.structSize_Mahasiswa);
    loadData("bin/d_matkul.dat", dataMatkul, sizeof(Matkul), dataSettings.structSize_Matkul);
    loadData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
    forceReadjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);

    int menuSelection;
    int invalidSelection = 0;
    while (1) {
        printMainMenu();
        if (invalidSelection) {
            setColor(COLOR_RED);
            printf("MOHON HANYA MEMASUKKAN ANGKA YANG VALID!\n");
            setColor(COLOR_DEFAULT);
            invalidSelection = 0;
        }
        printf("Silakan pilih angka pada menu: ");
        scanf("%d", &menuSelection);

        // (1) Lihat Data Dosen
        if (menuSelection == 1) {
            sceneLihatDataDosen(dataDosen, &dataSettings);
        }

        // (2) Input Data Dosen
        else if (menuSelection == 2) {
            sceneInputDataDosen(&dataDosen, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_dosen.dat", dataDosen, sizeof(Dosen), dataSettings.structSize_Dosen);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (3) Hapus Data Dosen
        else if (menuSelection == 3) {
            sceneDeleteDataDosen(&dataDosen, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_dosen.dat", dataDosen, sizeof(Dosen), dataSettings.structSize_Dosen);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (4) Lihat Data Mahasiswa
        else if (menuSelection == 4) {
            sceneLihatDataMahasiswa(dataMahasiswa, &dataSettings);
        }

        // (5) Input Data Mahasiswa
        else if (menuSelection == 5) {
            sceneInputDataMahasiswa(&dataMahasiswa, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_mahasiswa.dat", dataMahasiswa, sizeof(Mahasiswa), dataSettings.structSize_Mahasiswa);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (6) Hapus Data Mahasiswa
        else if (menuSelection == 6) {
            sceneDeleteDataMahasiswa(&dataMahasiswa, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_mahasiswa.dat", dataMahasiswa, sizeof(Mahasiswa), dataSettings.structSize_Mahasiswa);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (7) Lihat Data Matkul
        else if (menuSelection == 7) {
            sceneLihatDataMatkul(dataMatkul, &dataSettings);
        }

        // (8) Input Data Matkul
        else if (menuSelection == 8) {
            sceneInputDataMatkul(&dataMatkul, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_matkul.dat", dataMatkul, sizeof(Matkul), dataSettings.structSize_Matkul);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (9) Hapus Data Matkul
        else if (menuSelection == 9) {
            sceneDeleteDataMatkul(&dataMatkul, &dataSettings);
            readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_matkul.dat", dataMatkul, sizeof(Matkul), dataSettings.structSize_Matkul);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);
        }

        // (10) Lihat Data Peserta Kuliah
        else if (menuSelection == 10) {
            sceneLihatDataPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
        }

        // (11) Input Data Peserta Kuliah
        else if (menuSelection == 11) {
            sceneInputDataPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);            
        }

        // (12) Hapus Data Peserta Kuliah
        else if (menuSelection == 12) {

        }

        // (13) Input Nilai Peserta Kuliah
        else if (menuSelection == 13) {
            sceneInputNilaiPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
            saveSettings("bin/d_settings.dat", &dataSettings);
            saveData("bin/d_pesertakuliah.dat", dataPesertaKuliah, sizeof(PesertaKuliah), dataSettings.structSize_PesertaKuliah);            
        }

        // (14) Informasi Data
        else if (menuSelection == 14) {

        }

        // (15) Simpan Paksa Data
        else if (menuSelection == 15) {

        }

        // (16) Informasi Perangkat Lunak
        else if (menuSelection == 16) {

        }

        // (16) Keluar
        else if (menuSelection == 17) {
            
        }

        // Default case
        else {
            invalidSelection = 1;
        }
    }
    

    // tabulateDosen(dataDosen, &dataSettings);
    // printf("\n");
    // tabulateMahasiswa(dataMahasiswa, &dataSettings);
    // printf("\n");
    // tabulateMatkul(dataMatkul, &dataSettings);
    // printf("\n");
    // tabulatePesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
    // printf("\n");

    // printf("PES KUL: %d\n", dataSettings.structSize_PesertaKuliah);
    // printf("\n");

    // int deletePos = searchPesertaKuliah(dataPesertaKuliah, &dataSettings, "IF184101", "196005271987011001", "5025221002");
    // deletePesertaKuliah(&dataPesertaKuliah, &dataSettings, deletePos);
    // printf("DEL POS:%d \n", deletePos);
    // readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);

    // inputNilai(dataPesertaKuliah, &dataSettings, 0, 100, 50);
    // tabulatePesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
    // printf("\n");

    // deletePos = searchMahasiswa(dataMahasiswa, &dataSettings, "5025221042");
    // deleteMahasiswa(&dataMahasiswa, &dataSettings, deletePos);
    // readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);

    // printf("\n");
    // tabulatePesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
    // printf("\n");

    // printf("PES KUL: %d\n", dataSettings.structSize_PesertaKuliah);

    return 0;
} 