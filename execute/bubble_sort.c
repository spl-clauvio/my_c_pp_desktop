void buble_sort(int arr[], int sz, int flag)
{
    int i = 0, j = 0, flag_perfect = 0, temp = 0;

    if (flag) // 1up||0down
    {
        for (i = 0; i < sz - 1; i++)
        {
            for (j = 0; j < sz - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < sz - 1; i++)
        {
            for (j = 0; j < sz - 1 - i; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}