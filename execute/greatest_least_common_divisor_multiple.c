int greatest_least_common_divisor1_multiple0(int a, int b, int flag)
{
    int max = b;
    int max_copy = 0;
    int min = a;
    int min_copy = 0;

    int remainder = 0;
    if (a > b)
    {
        max = a;
        min = b;
    }
    max_copy = max;
    min_copy = min;
    do
    {
        remainder = max % min;
        max = min;
        min = remainder;
    } while (min);
    if (flag)
    {
        return max;
    }
    else
    {
        return max_copy / max * min_copy;
    }
}