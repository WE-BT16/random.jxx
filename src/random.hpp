#include <random>
#include <string>
#include <unistd.h>

namespace random_generator {
    /**
     * @brief Generates a random number using rand
     * @param min min number
     * @param max max number
     * @return int the generated random number
     */
    int rand_number(int min, int max);
    
    /**
     * @brief Generates a random number
     * @param min min number
     * @param max max number
     * @return int the generated number
     */
    int number(int min, int max);

    /**
     * @brief Generates a random string
     * @param len how long to generate the string
     * @param allow_chars allowed chars to work with
     * @return std::string the generated string
     */
    std::string string(int len, std::string allow_chars);
}