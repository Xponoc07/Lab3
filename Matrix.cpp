#include "Matrix.h"
#include "Image.h"

void fillMatrix(bool *bool_matrix, uint64_t *matrix, uint16_t height, uint16_t width, const std::string& path) {

    memset(matrix, 0, sizeof(uint64_t) * height * width);
    memset(bool_matrix, false, sizeof(bool) * height * width);

    uint16_t x, y;
    uint64_t grain_sand;

    std::ifstream fin(path);

    while (!fin.eof()) {

        fin >> x >> y >> grain_sand;

        matrix[x * width + y] = grain_sand;

        if (grain_sand >= 4)
            bool_matrix[x * width + y] = true;
        else
            bool_matrix[x * width + y] = false;
    }

}

void createImage(uint64_t *matrix, uint16_t height, uint16_t width, const std::string &path, int max_iter, int freq) {

    Image image(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            if (matrix[y * width + x] == 0)
                image.SetColor(Color(1.0f, 1.0f, 1.0f), x, y);

            if (matrix[y * width + x] == 1)
                image.SetColor(Color(0.0f, 128.0f, 0.0f), x, y);

            if (matrix[y * width + x] == 2)
                image.SetColor(Color(128.0f, 0.0f, 128.0f), x, y);

            if (matrix[y * width + x] == 3)
                image.SetColor(Color(1.0f, 1.0f, 255.0f), x, y);

            if (matrix[y * width + x] > 3)
                image.SetColor(Color(0.0f, 0.0f, 0.0f), x, y);
        }
    }

    if(freq != 0)
        image.Export(path + std::to_string(max_iter/freq) + ".bmp");
    else
        image.Export(path + "freqZero.bmp");
}

void despersionMatrix(bool *bool_matrix, uint64_t *matrix, uint16_t height, uint16_t width, const std::string& path, int max_iter, int freq) {

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            if (matrix[i * width + j] >= 4 && bool_matrix[i * width + j]) {
                matrix[i * width + j]-= 4;

                matrix[i * width + j - 1]++;
                matrix[(i - 1) * width + j]++;
                matrix[i * width + j + 1]++;
                matrix[(i + 1) * width + j]++;

                if (j == 0)
                    matrix[i * width + j - 1]--;

                if (j == height - 1)
                    matrix[i * width + j + 1]--;

                if (freq != 0 && max_iter % freq == 0)
                    createImage(matrix, height, width, path, max_iter, freq);
            }
        }
    }

    if (freq == 0)
        createImage(matrix, height, width, path, max_iter, freq);
}

bool despersionBoolMatrix (bool *bool_matrix, uint64_t *matrix, uint16_t height, uint16_t width) {

    bool matrix_empty = false;

    for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {

                if (matrix[i * width + j] >= 4)
                    matrix_empty = true;

                if (matrix[i * width + j] >= 4 && !bool_matrix[i * width + j])
                    bool_matrix[i * width + j] = true;

                if (matrix[i * width + j] < 4 && bool_matrix[i * width + j])
                    bool_matrix[i * width + j] = false;
            }
        }

    return matrix_empty;

}

