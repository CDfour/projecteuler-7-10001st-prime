#include "_10001st_prime.h"

#include <vector>

// answer = 104743
int _10001st_prime() {

    const int SIZE = 10001;

    std::vector<bool> nums(SIZE);
    std::vector<int> primeNums(SIZE);

    int foundPrimes = 0;

    for (int i = 2; i < SIZE; i++)
        nums[i] = true;

    bool addition = false;
    int adder = 0;

    while (true)
    {
        if (addition)
        {
            nums.resize(nums.size() + SIZE, true);

            for (int i = 0; i < foundPrimes; i++)
            {
                int cur_num = primeNums[i];
                if ((SIZE + ((nums.size() - SIZE) % cur_num)) < cur_num)
                    continue;
                for (int j = ((nums.size() - SIZE) / cur_num) * cur_num; j < nums.size(); j += cur_num)
                    nums[j] = false;
            }
        }
        else
            addition = true;

        int iter;
        if (foundPrimes == 0)
            iter = 2;
        else
            iter = primeNums[foundPrimes - 1] + 2;

        for (; iter < nums.size(); iter++)
        {

            if (nums[iter])
            {
                primeNums[foundPrimes] = iter;
                foundPrimes++;
                if (foundPrimes == SIZE)
                    break;

                for (int j = iter + iter; j < nums.size(); j += iter)
                    nums[j] = false;
            }
            else
                continue;

        }
        if (foundPrimes == SIZE)
            break;
    }

    return primeNums[SIZE - 1];
}