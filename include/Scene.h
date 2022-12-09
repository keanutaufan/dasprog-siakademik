#include "Data.h"

int sceneLihatDataDosen(Dosen *dataDosen, DataSettings *dataSettings);
int sceneLihatDataMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings);
int sceneLihatDataMatkul(Matkul *dataMatkul, DataSettings *dataSettings);
int sceneLihatDataPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);

int sceneInputDataDosen(Dosen **dataDosen, DataSettings *dataSettings);
int sceneInputDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings);