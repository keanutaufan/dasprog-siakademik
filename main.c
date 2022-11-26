#include <stdio.h>
#include <malloc.h>
#include "include/UI.h"
#include "include/Data.h"
#include "include/Debug.h"
#include "Storage.h"

#include <string.h>

int main() {
    DataSettings dataSettings;

    Dosen *dataDosen = initializeEmptyData();
    Mahasiswa *dataMahasiswa = initializeEmptyData();
    Matkul *dataMatkul = initializeEmptyData();
    PesertaKuliah *dataPesertaKuliah = initializeEmptyData();

    // inputDosen(&dataDosen, &dataSettings, "198210202008121003", "Malik Anjelh Baqiya");
    // inputDosen(&dataDosen, &dataSettings, "196005271987011001", "Sentot Didik Surjanto");
    // inputDosen(&dataDosen, &dataSettings, "197106161997031002", "Didik Prasetyoko");
    // inputDosen(&dataDosen, &dataSettings, "198703042014042003", "Eka Dian Savitri");
    // inputDosen(&dataDosen, &dataSettings, "9900008143", "Mirza Fathima Jauhar K.");
    // inputDosen(&dataDosen, &dataSettings, "197205281997021001", "Dwi Sunaryono");

    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221049", "Yanuar Eka Pramudya", "Jl. Kenjeran No. 49 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221047", "Muhammad Arifin Ilham", "Jl. Kenjeran No. 47 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221044", "Wildan Fauzy Maulana Hasyim", "Jl. Kenjeran No. 44 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221043", "Tunas Abdi Pranata", "Jl. Kenjeran No. 43 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221042", "Keanu Fortuna Taufan", "Jl. Kenjeran No. 42 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221040", "Genta Putra Prayoga", "Jl. Kenjeran No. 40 Surabaya");
    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221050", "Lucky Santoso", "Jl. Kenjeran No. 50 Surabaya");

    // inputMatkul(&dataMatkul, &dataSettings, "UG184912", "Bahasa Indonesia", 2);
    // inputMatkul(&dataMatkul, &dataSettings, "IF184101", "Dasar Pemrograman", 4);
    // inputMatkul(&dataMatkul, &dataSettings, "SF184101", "Fisika 1", 4);
    // inputMatkul(&dataMatkul, &dataSettings, "SK184101", "Kimia 1", 3);
    // inputMatkul(&dataMatkul, &dataSettings, "KM184101", "Matematika 1", 4);
    // inputMatkul(&dataMatkul, &dataSettings, "UG184911", "Pancasila", 2);

    // inputPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen+2, dataMahasiswa);

    // inputMahasiswa(&dataMahasiswa, &dataSettings, "5025221002", "Iftala Zahri Sukmana", "Jl. Kenjeran No. 2 Surabaya");
    // readjustPesertaKuliah(dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen, dataMahasiswa);

    // inputPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen+2, dataMahasiswa);
    // inputPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen+2, dataMahasiswa+2);
    // inputPesertaKuliah(&dataPesertaKuliah, &dataSettings, dataMatkul, dataDosen+2, dataMahasiswa+3);

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
    
    return 0;
} 