#include <iostream>
#include <vector>

const int MOD = 998244353;

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse
long long mod_inv(long long x, long long mod)
{
    return mod_exp(x, mod - 2, mod);
}

// Function to calculate winning probabilities
std::pair<long long, long long> calculateProbabilities(int a, int b)
{
    std::vector<std::vector<double>> P(a + 1, std::vector<double>(b + 1, 0.0));

    // Initialize base cases
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if (i > j)
            {
                P[i][j] = 1.0;
            }
            else if (i < j)
            {
                P[i][j] = 0.0;
            }
        }
    }

    // Fill the DP table
    for (int i = a; i >= 0; --i)
    {
        for (int j = b; j >= 0; --j)
        {
            if (i == a && j == b)
                continue; // Skip the base case
            if (i > j)
            {
                P[i][j] = 1.0;
            }
            else if (i < j)
            {
                P[i][j] = 0.0;
            }
            else
            {
                if (i + i <= a + b && j - i >= 0)
                {
                    int next_i = std::min(2 * i, a);
                    int next_j = std::max(j - i, 0);
                    P[i][j] = 0.5 * P[next_i][next_j] + 0.5 * P[i][next_j];
                }
            }
        }
    }

    long long p1_num = static_cast<long long>(P[a][b] * MOD) % MOD;
    long long p2_num = (MOD - p1_num) % MOD;

    long long p1_den_inv = mod_inv(MOD, MOD);
    long long p2_den_inv = mod_inv(MOD, MOD);

    long long result_p1 = (p1_num * p1_den_inv) % MOD;
    long long result_p2 = (p2_num * p2_den_inv) % MOD;

    return {result_p1, result_p2};
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    // Calculate the probabilities
    auto [prob_p1, prob_p2] = calculateProbabilities(a, b);

    // Print results
    std::cout << prob_p1 << " " << prob_p2 << std::endl;

    return 0;
}