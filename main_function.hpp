#pragma once
#include <iostream>
#include "function.hpp"

void header();
void inputPilihan(int &pilih);
void menuUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void menuPkjUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void entryPkj(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);

void showListPkj(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void infoBarangIn(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);

void menuKurirUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void entryKurir(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void showListKurir(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void infoBarangOut(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void infoBarangTop(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
void keluarBarang(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry);
