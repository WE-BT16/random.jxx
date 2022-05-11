#include "random.hpp"

namespace random_generator {
    int rand_number(int min, int max) {
        int n = max - min + 1;
        int remainder = RAND_MAX % n;
        int x;
        do {
            x = rand();
        } while (x >= RAND_MAX - remainder);

        return min + x % n;
    }

    int number(int min, int max) {
        std::random_device random_device;
        std::default_random_engine eng(random_device());
        std::uniform_int_distribution<int> distr(min, max);

        int random_number = distr(eng);

        return random_number;
    }

    std::string string(int len, std::string allow_chars) {
        std::size_t length = (size_t) len;
        const std::string CHARACTERS = allow_chars;

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

        std::string random_string;

        for (std::size_t i = 0; i < length; ++i) {
            random_string += CHARACTERS[distribution(generator)];
        }

        return random_string;
    }
}