#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pause()
{
    system("pause");
}

double real_need(double a)
{
    if (a > 20000)
    {
        a = 20000;
    }
    return a;
}
double plus_need(double a)
{
    if (a > 20000)
    {
        a -= 20000;
    }
    return a;
}
double sum_vcost(int year, int way, double rate1, double rate2)
{
    int i, j;
    double vcost_rate1[9] = {0.1, 0.05, 0.015, 0.23, 0.20, 0.09, 0.35, 0.38, 0.1};
    double vcost_rate2[3][3] = {0};
    double sum = 0;
    for (i = 0; i < 3; i++) // 给可变成本赋值
    {
        for (j = 0; j < 3; j++)
        {
            vcost_rate2[i][j] = vcost_rate1[i * 3 + j];
        }
    }
    vcost_rate2[way][0] *= pow(rate1 + 1, year - 2.0);
    vcost_rate2[way][1] *= pow(rate2 + 1, year - 2.0);
    for (i = 0; i < 3; i++)
    {
        sum += vcost_rate2[way][i];
    }
    return sum;
}

int main()
{
    int i, j, k, l, m, n;

    double f_need, sale, returned, price, produce, vcost_rate, raw_uprate, labor_uprate, vcost_sum, npv, sum_npv;
    double cvt[16] = {0};
    double cft[16] = {0};
    double cit[16] = {0};
    double cot[16] = {0};
    double sum_produce = 0;
    double exp_npv[3][3] = {0};
    double npv_list[3][3][3][3] = {0};
    double produce2[3][14] = {0};
    double vcost_rate2[3][3] = {0};
    double raw_uprate1[3] = {0.025, 0.015, 0.0025};
    double labor_uprate1[3] = {0.03, 0.015, 0.0};
    double investment[3][3] = {0};
    double possibility[3][3];
    double possibility_raw[3] = {0.5, 0.3, 0.2};
    double possibility_labor[3] = {0.4, 0.3, 0.3};

    double discount_rate1[3] = {0.05, 0.08, 0.11};
    double investment1[9] = {900, 300, 180000, 1000, 400, 42000, 1000, 1500, 9000};
    double vcost_rate1[9] = {0.1, 0.05, 0.015, 0.23, 0.20, 0.09, 0.35, 0.38, 0.1};
    double produce1[42] = {270, 270, 280, 280, 280, 280, 280, 280, 280, 280, 280, 270, 270, 260, 90, 100, 110, 110, 110, 110, 105, 102, 100, 99, 98, 98, 95, 90, 55, 55, 55, 55, 60, 60, 60, 60, 60, 60, 55, 55, 55, 55};

    for (i = 0; i < 42; i++)
    {
        produce1[i] = produce1[i] * 100;
    }
    for (i = 0; i < 3; i++) // 给投入赋值
    {
        for (j = 0; j < 3; j++)
        {
            investment[i][j] = investment1[i * 3 + j];
        }
    }
    for (i = 0; i < 3; i++) // 给可变成本赋值
    {
        for (j = 0; j < 3; j++)
        {
            vcost_rate2[i][j] = vcost_rate1[i * 3 + j];
        }
    }
    for (i = 0; i < 3; i++) // 给计划产能赋值
    {
        for (j = 0; j < 14; j++)
        {
            produce2[i][j] = produce1[i * 14 + j];
        }
    }
    for (i = 0; i < 3; i++) // 给概率赋值
    {
        for (j = 0; j < 3; j++)
        {
            possibility[i][j] = possibility_raw[i] * possibility_labor[j];
        }
    }
    printf("概率\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%10.2f", possibility[i][j]);
        }
        printf("\n");
    }
    printf("\n计划产能\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 14; j++)
        {
            printf("%10.2f", produce2[i][j]);
        }
        printf("\n");
    }
    printf("\n可变成本\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%8.3f", vcost_rate2[i][j]);
        }
        printf("\n");
    }
    printf("\n投资\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%10.2f", investment[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;

    for (i = 0; i < 3; i++) // 三种折现率
    {
        printf("折现率%d号\n", i + 1);

        for (j = 0; j < 3; j++) // 三种方案
        {
            for (n = 0, sum_produce = 0; n < 14; n++)
            {
                sum_produce += produce2[j][n];
            }
            exp_npv[i][j] = 0;
            for (k = 0; k < 3; k++) // 三种原材料价格变动
            {
                for (l = 0; l < 3; l++) // 三种劳动价格变动
                {
                    sum_npv = 0;
                    for (m = 0; m < 16; m++) // 16年
                    {
                        npv = 0;
                        sale = 0;
                        if (m < 2)
                        {
                            cit[m] = 0;
                            cvt[m] = 0;
                            if (m < 1)
                            {
                                cft[m] = (investment[j][0] + investment[j][1]) / 16 / pow(1 + discount_rate1[i], m + 1);
                            }
                            else
                            {
                                cft[m] = (investment[j][0] + investment[j][1]) / 16 / pow(1 + discount_rate1[i], m + 1) + investment[j][2] / 15 / pow(1 + discount_rate1[i], m + 1);
                            }
                            cot[m] = cvt[m] + cft[m];
                        }
                        else
                        {
                            for (n = 0; n < 2; n++)
                            {
                                vcost_rate2[j][n] *= 0;
                            }
                            sale = real_need(produce2[j][m - 2]);
                            f_need = plus_need(produce2[j][m - 2]);

                            cit[m] = (sale * 5 + f_need * 0.3) / pow(1 + discount_rate1[i], m + 1);
                            cvt[m] = sale * 5 * (sum_vcost(m, j, raw_uprate1[k], labor_uprate1[l])) / pow(1 + discount_rate1[i], m + 1);
                            cft[m] = (investment[j][0] + investment[j][1]) / 16 / pow(1 + discount_rate1[i], m + 1) + investment[j][2] / 15 / pow(1 + discount_rate1[i], m + 1) + sale * 5 * (1 - sum_vcost(m, j, raw_uprate1[k], labor_uprate1[l]) / pow(1 + discount_rate1[i], m + 1));
                            cot[m] = cvt[m] + cft[m];
                        }
                        npv = cit[m] - cvt[m] - cft[m];
                        sum_npv += npv;
                        // printf("%f  %f  %f  %f  %f\n", sum_npv, npv, cit[m], cot[m], sale);
                    }
                    npv_list[i][j][k][l] = sum_npv;
                    exp_npv[i][j] += possibility[k][l] * sum_npv;
                }
            }
            printf("\n");
            printf("在方案%d号 情况下,净现值期望为%f\n", j + 1, exp_npv[i][j]);
            printf("\n总计计划生产子弹为  %.2f  万发,平均每万发子弹净值  %f  万元\n", sum_produce, exp_npv[i][j] / sum_produce);
        }
        printf("\n\n\n");
    }
    pause();
    return 0;
}