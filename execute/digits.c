int digits(int num)
{
    int digit = 1;

    while (num /= 10)
    {
        digit++;
    }
    return digit;
}