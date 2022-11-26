#ifndef _UI_H
#define _UI_H

#include "Data.h"

void clearScreen(void);

int tabulateDosen(Dosen *dataDosen, DataSettings *dataSettings);
int tabulateMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings);
int tabulateMatkul(Matkul *dataMatkul, DataSettings *dataSettings);
int tabulatePesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);

#endif