#include "Image.h"
#include "Matrix.h"

int main() {

    uint16_t height, width;
    int max_iter, freq;
    std::string path_input, path_output;

    std::cin >> height >> width >> max_iter >> freq;
    std::cin >> path_input >> path_output;

    uint64_t *matrix = new uint64_t[height * width];
    bool *bool_matrix = new bool[height * width];

    fillMatrix(bool_matrix, matrix, height, width, path_input);

    for (int i = max_iter; i != 0; --i) {
        despersionMatrix(bool_matrix, matrix, height, width, path_output, i, freq);

        if(!despersionBoolMatrix(bool_matrix, matrix, height, width))
            break;
    }

//    despersionMatrix(bool_matrix, matrix, height, width, path_output, max_iter, freq);

    delete[] matrix;
    delete[] bool_matrix;

    return 0;
}
