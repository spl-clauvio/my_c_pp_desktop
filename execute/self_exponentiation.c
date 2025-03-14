int self_exponentiation(int num, int digit)
{
    if (!num)
    {
        return 0;
    }
    int i = 0, j = 0;
    int sum = 0;
    int index = 0;
    int remainder = 0;
    int remainder_copy = 0;
    int num_copy = num;
    for (i = 0; i < digit; i++)
    {

        remainder = num % 10;
        remainder_copy = remainder;

        for (j = 1; j < digit; j++)
        {
            remainder *= remainder_copy;
        }

        sum += remainder;
        num /= 10;

        while (!num)
        {
            if (sum == num_copy)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}