#include <stdio.h>
#include <malloc.h>
#include "include/UI.h"
#include "include/Data.h"
#include "include/Debug.h"
#include "include/Storage.h"

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

    tabulateDosen(dataDosen, &dataSettings);
    printf("\n");
    tabulateMahasiswa(dataMahasiswa, &dataSettings);
    printf("\n");
    tabulateMatkul(dataMatkul, &dataSettings);
    printf("\n");
    tabulatePesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
    printf("\n");

    printf("\n");

    int deletePos = searchPesertaKuliah(dataPesertaKuliah, &dataSettings, "IF184101", "196005271987011001", "5025221042");
    deletePesertaKuliah(&dataPesertaKuliah, &dataSettings, deletePos);
    printf("DEL POS:%d \n", deletePos);
    readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);

    inputNilai(dataPesertaKuliah, &dataSettings, 0, 100, 50);

    printf("\n");
    tabulatePesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);
    printf("\n");

    return 0;
} 