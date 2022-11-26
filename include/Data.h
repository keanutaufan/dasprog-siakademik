#ifndef _DATA_H
#define _DATA_H

#define SCORE_EMPTY -1
#define AVG_EMPTY -1.0

#define NOT_FOUND -1

typedef struct {
    int structSize_Dosen;
    int structSize_Mahasiswa;
    int structSize_Matkul;
    int structSize_PesertaKuliah;
} DataSettings;

typedef struct {
    char NIP[20];
    char nama[50];
} Dosen;

typedef struct {
    char NRP[20];
    char nama[50];
    char alamat[50];
} Mahasiswa;

typedef struct {
    char kode[10];
    char nama[30];
    int sks;
} Matkul;

typedef struct {
    Matkul *matkul;
    Dosen *dosen;
    Mahasiswa *peserta;
    int uts;
    int uas;
    float rerata;
    char grade;
    char key_kode[20];
    char key_NIP[20];
    char key_NRP[20];
} PesertaKuliah;

// Functions related to memory
void *initializeEmptyData(void);

// Functions related to data input
int inputDosen(Dosen **dataDosen, DataSettings *dataSettings, const char *NIP, const char *nama);
int inputMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings, const char *NRP, const char *nama, const char *alamat);
int inputMatkul(Matkul **dataMatkul, DataSettings *dataSettings, const char *kode, const char *nama, int sks);
int inputPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings* dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta);
void inputNilai(PesertaKuliah **dataPesertaKuliah, DataSettings* dataSettings, PesertaKuliah *pesertaKuliah, int uts, int uas);

// Functions related to data search
int searchDosen(Dosen *dataDosen, DataSettings *dataSettings, char NIP[]);
int searchMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings, char NRP[]);
int searchMatkul(Matkul *dataMatkul, DataSettings *dataSettings, char kode[]);

int readjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);
int forceReadjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);


#endif