#include <iostream>

#include <common.hpp>

utils::Matrix SequentialProductNaive(const utils::Matrix &lhs, const utils::Matrix &rhs)
{
    utils::Matrix res = utils::zero_matrix<utils::MatrixDataType>(lhs.size1(), rhs.size2());
    assert(lhs.size2() == rhs.size1());

    for (size_t i = 0; i < res.size1(); ++i)
    {
        for (size_t j = 0; j < res.size2(); ++j)
        {
            for (size_t p = 0; p < rhs.size1(); ++p)
            {
                res(i, j) += lhs(i, p) * rhs(p, j);
            }
        }
    }

    return res;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Wrong usage, should be 2 parameters\n";
        return 1;
    }

    auto a = utils::ReadMatrixFromFile<utils::MatrixDataType>(argv[1]);
    auto b = utils::ReadMatrixFromFile<utils::MatrixDataType>(argv[2]);

    utils::Benchmark benchmark("Naive");
    const auto res = SequentialProductNaive(a, b);

    return 0;
}
