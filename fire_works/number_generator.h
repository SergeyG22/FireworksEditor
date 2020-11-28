#pragma once

double number_generator(int range_min, int range_max) {
    std::random_device random;
    std::mt19937 mt(random());
    std::uniform_real_distribution<double>range(range_min, range_max);
    return range(mt);
}
