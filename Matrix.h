#ifndef BMP_TEST_MATRIX_H
#define BMP_TEST_MATRIX_H

#endif //BMP_TEST_MATRIX_H

#include <iostream>
#include <fstream>
#include <cstring>

void fillMatrix(bool *bool_matrix, uint64_t *matrix, uint16_t height, uint16_t width, const std::string& path);

void createImage(uint64_t *matrix, uint16_t height, uint16_t width, const std::string& path, int max_iter, int freq);

void despersionMatrix(bool *bool_matrix, uint64_t *matrix,  uint16_t height, uint16_t width, const std::string& path, int max_iter, int freq);

bool despersionBoolMatrix (bool *bool_matrix, uint64_t *matrix, uint16_t height, uint16_t width);



