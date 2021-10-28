using System;
using System.Collections.Generic;

namespace Task4
{
    class Combinations
    {
        static int[] coins = new int[] {1, 5, 10, 20, 25, 50};
        static Dictionary<KeyValuePair<int, int>, int> cache = new Dictionary<KeyValuePair<int, int>, int>();

        /* I made a recursive function. It is not efficient, it is slow, but I made from scratch.
         * There are better ways to solve this problem, searching for knapsack problem on the internet
         * but I thought that I should implement something of my own instead of copying an algorithm.
         * I used a cache to reduce recalculation.
         */
        static int getNumberOfCombinations(int amount, int coinIndex)
        {
            if (amount < 5 || coinIndex < 1) return 1;

            // Cache check
            KeyValuePair<int, int> cacheIndex = new KeyValuePair<int, int>(amount, coinIndex);
            if (cache.ContainsKey(cacheIndex))
                return cache[cacheIndex];

            // Search for the most valuable coin we can use
            while (amount < coins[coinIndex]) --coinIndex;
            int coin = coins[coinIndex];

            int combinations = 0;

            for (int i = 0; i <= amount / coin; ++i)
            {
                combinations += getNumberOfCombinations(amount - i * coin, coinIndex - 1);
            }

            cache.Add(cacheIndex, combinations);

            return combinations;
        }

        static public int getNumberOfCombinations(int amount)
        {
            return getNumberOfCombinations(amount, coins.Length - 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Combinations.getNumberOfCombinations(40));
        }
    }
}
