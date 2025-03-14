#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <my_math.h>
#include <Windows.h>
#include <string.h>
#include <my_sort.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdbool.h>

// #include <SDL2/SDL.h>

static int hang_set = 5;
static int line_spacing = 0;
static int hanoi_column_num = 1;
static int hanoi_plate_number, hanoi_column_check, hanoi_line_spacing = 0;
static char hanoi_beginning_pole = 'A';
static char hanoi_endding_pole = 'C';
static char hanoi_transit_pole = 'B';

struct person
{
    char name[20];
    char sex[5];
    char tele[12];
    int height;
};

void clear()
{
    system("cls");
}

void pause()
{
    system("pause");
}

int is_prime(int num)
{
    int i = 0;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void prime_single()
{
    clear();

    int single_n = 0;
    printf("Please enter a number\n");
    scanf("%d", &single_n);

    clear();

    if (is_prime(single_n))
        printf("%d is a prime number!\n\n", single_n);
    else
        printf("Error! %d is not a prime number!\n\n", single_n);
}

void prime_main_menu()
{
    printf("#####   Welcome!   #####\n");
    printf("#####   1.Single   #####\n");
    printf("#####   2.Range    #####\n");
    printf("#####   3.Settings #####\n");
    printf("#####   4.Guide    #####\n");
    printf("#####   0.Exit     #####\n");
}

void prime_check_over()
{
    int over = 0;
    printf("\n#####  1.Prime main menu  #####\n");
    scanf("%d", &over);
}

void hanoi_check_over()
{
    int over = 0;
    printf("\n#####  1.Hanoi main menu  #####\n");
    scanf("%d", &over);
}

void Fibonacci_sequence_return_menu()
{
    int over = 0;
    printf("\n#####  1.Fibonacci main menu  #####\n");
    scanf("%d", &over);
}

void self_exponentiation_return_menu()
{
    int over = 0;
    printf("\n#####  1.Self exponentiation main menu  #####\n");
    scanf("%d", &over);
}

void number_counter_return_menu()
{
    int over = 0;
    printf("\n#####  1.Number counter main menu  #####\n");
    scanf("%d", &over);
}

void normal_return_menu()
{
    int over = 0;
    printf("\n#####  1.Main menu  #####\n");
    scanf("%d", &over);
}

void game_return_menu()
{
    int over = 0;
    printf("\n#####  1.Game menu  #####\n");
    scanf("%d", &over);
}

void trimoku_return_menu()
{
    int over = 0;
    printf("\n#####  1.Trimoku menu  #####\n");
    scanf("%d", &over);
}

void prime_setting_menu_hang_set()
{
    int flag_setting_menu_hang_set, hang_set_copy = 0;
    hang_set_copy = hang_set;
    clear();
    printf("Please enter a columns num you like.Default is 5\n");
    do
    {
        if (flag_setting_menu_hang_set == 0)
            printf("Enter any int type number smaller than 1 twice will cancel the operation.\n\n");
        else
            printf("Enter any int type number smaller than 1 again will cancel the operation.\n\n");

        scanf("%d", &hang_set);
        clear();
        if (hang_set > 0)
            break;
        else
        {
            flag_setting_menu_hang_set++;
            if (flag_setting_menu_hang_set == 2)
            {
                hang_set = hang_set_copy;
                break;
            }
        }
    } while (1);
    clear();

    if (hang_set > 1)
        printf("Column num set successfully!\n\nResults will display in %d columns.\n", hang_set);
    else
        printf("Column num set successfully!\n\nResults will display in %d column.\n", hang_set);
}

void prime_setting_menu_line_spacing()
{
    clear();
    printf("Please enter a line spacing num you like.Default is 0\n");

    scanf("%d", &line_spacing);
    clear();

    printf("Line spacing set successfully!\n\n%d lines will be between results.\n", line_spacing);
}

void prime_setting_menu()
{
    int numseen = 0;
    int prime_setting_menu_input = 0;
    clear();
    printf("#####    1.Column set    #####\n");
    printf("##### 2.Line spacing set #####\n");
    printf("#####       0.Exit       #####\n");
    scanf("%d", &prime_setting_menu_input);

    switch (prime_setting_menu_input)
    {
    case 1:
        prime_setting_menu_hang_set();
        break;
    case 2:
        prime_setting_menu_line_spacing();
        break;
    case 0:
        clear();
        break;
    default:
        break;
    }
}

void prime_range_menu()
{
    int i_line_spacing = 0;
    clear();

    int left, right, prime_check, hang_num, prime_num = 0;
    printf("Please enter the min number.\n");
    scanf("%d", &left);

    clear();

    printf("Left set %d successfully! Please enter the max number.\n", left);

    scanf("%d", &right);
    clear();
    printf("Prime numbers from %d to %d:\n\n", left, right);

    for (prime_check = left; prime_check <= right; prime_check++)
    {
        if (is_prime(prime_check))
        {
            printf("%8d", prime_check);
            prime_num++;
            hang_num++;
        }
        if (hang_num == hang_set)
        {
            for (i_line_spacing = 0; i_line_spacing <= line_spacing; i_line_spacing++)
            {
                printf("\n");
            }
            hang_num = 0;
        }
    }
    printf("\n%d\n", prime_num);
}

void prime_guide_menu()
{
    clear();
    printf("Developed by spl-clauvio\n");
    printf("Copyright by spl-clauvio\n");
    printf("\n\n");
}

void prime_main()
{
    int prime_input = 0;
    do
    {
        clear();
        prime_main_menu();
        scanf("%d", &prime_input);
        switch (prime_input)
        {
        case 1:
            prime_single();
            prime_check_over();
            break;
        case 2:
            prime_range_menu();
            prime_check_over();
            break;
        case 3:
            prime_setting_menu();
            prime_check_over();
            break;
        case 4:
            prime_guide_menu();
            prime_check_over();
            break;
        default:
            clear();
            break;
        }
    } while (prime_input);
}

void hanoi_main_menu()
{
    printf("#####     Welcome!     #####\n");
    printf("##### 1.Hanoi solution #####\n");
    printf("##### 2.Hanoi settings #####\n");
    printf("#####     3.Guide      #####\n");
    printf("#####     0.Exit       #####\n");
}

void hanoi_setting_column_set()
{
    hanoi_column_check = 0;
    printf("Please enter a column num.\n");
    scanf("%d", &hanoi_column_num);
    clear();
    printf("Column num %d set seccessfully.\n", hanoi_column_num);
}

void hanoi_setting_line_spacing_set()
{
    printf("Please enter a line spacing num.\n");
    scanf("%d", &hanoi_line_spacing);
    clear();
    printf("Line spacing num %d set seccessfully.\n", hanoi_column_num);
}

void hanoi_setting_menu()
{
    int hanoi_setting_menu_input = 0;
    printf("#####   1.Column set   #####\n");
    printf("#####  2.Line spacing  #####\n");
    printf("#####      0.Exit      #####\n");

    scanf("%d", &hanoi_setting_menu_input);

    switch (hanoi_setting_menu_input)
    {
    case 1:
        hanoi_setting_column_set();
        break;
    case 2:
        hanoi_setting_line_spacing_set();
        break;
    default:
        break;
    }
}
void hanoi_move(char wood_pole1, char wood_pole2)
{
    int i = 0;
    printf("%c -> %c    ", wood_pole1, wood_pole2);
    hanoi_column_check++;
    if (hanoi_column_check >= hanoi_column_num)
    {
        for (i = 0; i <= hanoi_line_spacing; i++)
            printf("\n");
        hanoi_column_check = 0;
    }
}

void hanoi_solution_1(int plate_number, char p1, char p2, char p3)
{
    if (plate_number == 1)
        hanoi_move(p1, p3);
    else
    {
        hanoi_solution_1(plate_number - 1, p1, p3, p2);

        hanoi_move(p1, p3);

        hanoi_solution_1(plate_number - 1, p2, p1, p3);
    }
}

void hanoi_solution()
{

    printf("Please enter the number of plate you want to move.\n");
    hanoi_column_check = 0;

    do
    {
        scanf("%d", &hanoi_plate_number);
    } while (hanoi_plate_number < 1);
    clear();
    switch (hanoi_plate_number)
    {
    case 1:
        printf("%d plate solution:\n", hanoi_plate_number);
        hanoi_move(hanoi_beginning_pole, hanoi_endding_pole);
        break;
    default:
        printf("%d plates solution:\n", hanoi_plate_number);
        hanoi_solution_1(hanoi_plate_number, hanoi_beginning_pole, hanoi_transit_pole, hanoi_endding_pole);
        break;
    }
}

void hanoi_guide_menu()
{
    clear();
    printf("Developed by spl-clauvio\n");
    printf("Copyright by spl-clauvio\n");
    printf("\n\n");
}

void hanoi_main()
{
    int hanoi_input = 0;
    do
    {
        clear();
        hanoi_main_menu();
        scanf("%d", &hanoi_input);
        clear();

        switch (hanoi_input)
        {
        case 1:
            hanoi_solution();
            hanoi_check_over();
            break;
        case 2:
            hanoi_setting_menu();
            hanoi_check_over();

            break;
        case 3:
            hanoi_guide_menu();
            hanoi_check_over();
            break;
        default:
            break;
        }
    } while (hanoi_input);
}

int fibonacci_list_member_maker(int n)
{
    int i, ret = 0;
    int l = 1;
    int r = 1;

    if (n <= 0)
        return 0;
    else if (n <= 2)
        return 1;
    else
    {
        for (i = 2; i < n; i++)
        {
            ret = l + r;
            l = r;
            r = ret;
        }
        return ret;
    }
}

void fibonacci_sequence_main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####   1.List fibonacci   #####\n");
    printf("#####    2.Member check    #####\n");
    // printf("#####     3.Find place     #####\n");
    printf("#####       5.Guide        #####\n");
    printf("#####        0.Exit        #####\n");
}

void fibonacci_sequence_list_maker()
{
    int length, i = 0;
    printf("Please enter the length of fibonacci sequence you want\n");
    scanf("%d", &length);
    clear();

    printf("Here are the fibonacci sequence you want:\n");
    for (i = 0; i < length; i++)
    {
        printf("%8d", fibonacci_list_member_maker(i + 1));
    }
}

void fibonacci_sequence_member_check()
{
    int member_to_check = 0;
    int member_indeed = -1;
    int member_place = 1;
    printf("Please enter a number that you want to check\n");
    scanf("%d", &member_to_check);
    clear();

    do
    {
        member_indeed = fibonacci_list_member_maker(member_place);

        if (member_indeed == member_to_check)
        {
            if (member_place % 10 > 3)
                printf("%d is the %dth of fibonacci sequence.\n", member_to_check, member_place);
            else if (member_place % 10 == 3)
                printf("%d is the %drd of fibonacci sequence.\n", member_to_check, member_place);
            else if (member_place > 10 && member_place % 10 == 1)
                printf("%d is the %dst of fibonacci sequence.\n", member_to_check, member_place);
            else if (member_place > 10 && member_place % 10 == 2)
                printf("%d is the %dnd of fibonacci sequence.\n", member_to_check, member_place);
            else
                printf("%d is the 1st or 2nd of fibonacci sequence.\n", member_to_check);
            break;
        }
        member_place++;
    } while (member_to_check > member_indeed);

    if (member_to_check < member_indeed)
    {
        printf("%d is not a fibonacci number.\n", member_to_check);
    }
}

void fibonacci_sequence_main()
{
    int fibonacci_input = 0;

    do
    {
        clear();
        fibonacci_sequence_main_menu();

        scanf("%d", &fibonacci_input);
        clear();
        switch (fibonacci_input)
        {
        case 1:
            fibonacci_sequence_list_maker();
            Fibonacci_sequence_return_menu();
            break;
        case 2:
            fibonacci_sequence_member_check();
            Fibonacci_sequence_return_menu();
            break;
        case 3:
            Fibonacci_sequence_return_menu();
            break;
        case 4:
            Fibonacci_sequence_return_menu();
            break;
        default:
            break;
        }
    } while (fibonacci_input);
}

void number_counter_main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####       1.Count        #####\n");
    printf("#####        0.exit        #####\n");
}

int number_counter_single_counter(int input, int check)
{
    int count = 0;
    int remainder = 0;
    input = abs(input);

    do
    {
        remainder = input % 10;
        input = input / 10;
        if (remainder == check)
        {
            count++;
        }
    } while (input);

    return count;
}
void number_counter_count()
{
    int l = 0;
    int r = 0;
    int i = 0;
    int single_return = 0;
    int sum = 0;
    int number_counter_count_input = 0;

    printf("Please enter the beginning of a continuous arroy.\n");
    scanf("%d", &l);
    clear();

    printf("Please enter the end of a continuous arroy.\n");
    scanf("%d", &r);
    clear();

    printf("Please enter the number to count\n");
    scanf("%d", &number_counter_count_input);
    clear();

    for (i = l; i <= r; i++)
    {
        single_return = number_counter_single_counter(i, number_counter_count_input);

        sum += single_return;

        printf("%8d has %d \'%d\'.\n", i, single_return, number_counter_count_input);
    }
    printf("%d\n", sum);
}

void number_counter_main()
{
    int number_counter_input = 0;

    do
    {
        clear();
        number_counter_main_menu();
        scanf("%d", &number_counter_input);
        clear();

        switch (number_counter_input)
        {
        case 1:
            number_counter_count();
            number_counter_return_menu();
            break;
        default:
            break;
        }
    } while (number_counter_input);
}

void sort_arroy_main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####       1.Bubble       #####\n");
    printf("#####        0.Exit        #####\n");
}

void sort_arroy_bubble_sort()
{
    int i = 0;
    int arr[256] = {0};
    int sz = 0;
    int flag = 1;
    int flag_flag = 0;
    printf("Enter an arroy(at most 256 members)\nSeparate members by ',' or blankspace.\nUse 'enter' to end.\n");
    do
    {
        scanf("%d", &arr[sz]);
        sz++;
        if (sz > 256)
        {
            break;
        }
    } while (getchar() != '\n');

    printf("1->up , 0->down\n");
    do
    {
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("The arroy will be list \'up\'.\n");
            flag_flag = 1;
        }
        if (flag == 0)
        {
            printf("The arroy will be list \'down\'.\n");
            flag_flag = 1;
        }
    } while (!flag_flag);

    buble_sort(arr, sz, flag);

    for (i = 0; i < sz; i++)
    {
        printf("%-4d", arr[i]);
    }
}

void sort_arroy_main()
{
    int sort_arroy_main_input = 0;
    do
    {
        clear();
        sort_arroy_main_menu();
        scanf("%d", &sort_arroy_main_input);
        clear();

        switch (sort_arroy_main_input)
        {
        case 1:
            sort_arroy_bubble_sort();
            normal_return_menu();
        default:
            break;
        }
    } while (sort_arroy_main_input);
}

void size_of_types()
{
    clear();
    printf("int:    %-2d byte\n", sizeof(int));
    printf("char:   %-2d byte\n", sizeof(char));
    printf("long:   %-2d byte\n", sizeof(long));
    printf("long2:  %-2d byte\n", sizeof(long long));
    printf("float:  %-2d byte\n", sizeof(float));
    printf("double: %-2d byte\n", sizeof(double));

    normal_return_menu();
    clear();
}

void daffodil_main_menu()
{
    printf("#####        1.Single         #####\n");
    printf("#####         2.Range          #####\n");
    printf("#####         0.Exit          #####\n");
}

void daffodil_single()
{
    printf("Enter a num.\n");
    int input = 0;
    scanf("%d", &input);

    if (self_exponentiation(input, digits(input)))
    {
        printf("%d is a self exponentiation number.\n", input);
    }
    else
    {
        printf("%d is not a self exponentiation number.\n", input);
    }
}

void daffodil_range()
{
    int left = 0, right = 0;
    do
    {

        printf("Enter the min num.\n");
        scanf("%d", &left);
        printf("Enter the max num.\n");
        scanf("%d", &right);

    } while (left >= right);

    printf("List:\n\n");

    for (; left <= right; left++)
    {
        if (self_exponentiation(left, digits(left)))
        {
            printf("%d\n", left);
        }
    }
}

void daffodil_main()
{
    int input = 0;
    do
    {
        clear();
        daffodil_main_menu();
        scanf("%d", &input);
        clear();

        switch (input)
        {
        case 1:
            daffodil_single();
            self_exponentiation_return_menu();
            break;
        case 2:
            daffodil_range();
            self_exponentiation_return_menu();
            break;
        default:
            break;
        }
    } while (input);
}

void trimoku_main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####        1.PVE         #####\n");
    printf("#####        2.PVP         #####\n");
    printf("#####      3.Settings      #####\n");
    printf("#####       4 Guide        #####\n");
    printf("#####        0.Exit        #####\n");
}

void trimoku_stdtrans(int arroy[], int line, int column)
{
    int a = arroy[0], b = arroy[1];
    arroy[1] = a - 1;
    arroy[0] = line - b;
}

void trimoku_chessboard_init(char chessboard[256][256], int line, int column)
{
    int i = 0, j = 0;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
        {
            chessboard[i][j] = ' ';
        }
    }
}

void trimoku_chessboard_displayer(int line, int column, char chessboard[256][256])
{
    int i = 0, j = 0;
    for (i = 0; i < line - 1; i++)
    {
        for (j = 0; j < column - 1; j++)
        {
            printf(" %c |", chessboard[i][j]);
        }
        printf(" %c \n", chessboard[i][j]);
        for (j = 0; j < column - 1; j++)
        {
            printf("---+", chessboard[i][j]);
        }
        j++;
        printf("---\n");
    }

    for (j = 0; j < column - 1; j++)
    {
        printf(" %c |", chessboard[i][j]);
    }
    printf(" %c \n", chessboard[i][j]);
}

void trimoku_chessboard(int line, int column, char chessboard[256][256])
{
    int i = 0, j = 0; // line-1 sets
}

int trimoku_transboard_judgement(int line, int column, int a, int b)
{
    if (a >= line)
        return 1;
    if (a < 0)
        return 1;
    if (b >= column)
        return 1;
    if (b < 0)
        return 1;
    return 0;
}

int trimoku_gg_flag_maker(char arroy[256][256], int num, int a, int b, int line, int column, char player)
{
    int i = 0, j = 0;
    int flag = 0;

    // x check
    for (i = 0; i < num; i++)
    {
        if (trimoku_transboard_judgement(line, column, a, b - i))
        {
            continue;
        }
        if (trimoku_transboard_judgement(line, column, a, b + num - 1 - i))
        {
            continue;
        }
        flag = 1;
        for (j = 0; j <= i; j++)
        {
            if (arroy[a][b - j] != arroy[a][b])
            {
                flag = 0;
            }
        } //-x side check
        for (j = 0; j < num - i; j++)
        {
            if (arroy[a][b] != arroy[a][b + j])
            {
                flag = 0;
            }
        } //+x side check
        // Finish 1 check
        if (flag)
        {
            return flag;
        }
    }
    if (arroy[2][0] == '*')
    {
        i = 0;
    }
    // y check
    for (i = 0; i < num; i++)
    {
        if (trimoku_transboard_judgement(line, column, a - i, b))
        {
            continue;
        }
        if (trimoku_transboard_judgement(line, column, a + num - 1 - i, b))
        {
            continue;
        }
        flag = 1;
        for (j = 0; j <= i; j++)
        {
            if (arroy[a - j][b] != arroy[a][b])
            {
                flag = 0;
            }
        } //-y side check
        for (j = 0; j < num - i; j++)
        {
            if (arroy[a][b] != arroy[a + j][b])
            {
                flag = 0;
            }
        } //+y side check
        // Finish 1 check
        if (flag)
        {
            return flag;
        }
    }

    // '/' check
    for (i = 0; i < num; i++)
    {
        if (trimoku_transboard_judgement(line, column, a - i, b - i))
        {
            continue;
        }
        if (trimoku_transboard_judgement(line, column, a + num - 1 - i, b + num - 1 - i))
        {
            continue;
        }
        flag = 1;
        for (j = 0; j <= i; j++)
        {
            if (arroy[a - j][b - j] != arroy[a][b])
            {
                flag = 0;
            }
        } //-y side check
        for (j = 0; j < num - i; j++)
        {
            if (arroy[a][b] != arroy[a + j][b + j])
            {
                flag = 0;
            }
        } //+y side check
        // Finish 1 check
        if (flag)
        {
            return flag;
        }
    }

    // '\' check
    for (i = 0; i < num; i++)
    {
        if (trimoku_transboard_judgement(line, column, a - i, b + i))
        {
            continue;
        }
        if (trimoku_transboard_judgement(line, column, a + num - 1 - i, b - num + 1 + i))
        {
            continue;
        }
        flag = 1;
        for (j = 0; j <= i; j++)
        {
            if (arroy[a - j][b + j] != arroy[a][b])
            {
                flag = 0;
            }
        } //-y side check
        for (j = 0; j < num - i; j++)
        {
            if (arroy[a][b] != arroy[a + j][b - j])
            {
                flag = 0;
            }
        } //+y side check
        // Finish 1 check
        if (flag)
        {
            return flag;
        }
    }
    return flag;
}

int trimoku_draw_judgement(char chessboard[256][256], int line, int column)
{
    int i = 0, j = 0;
    int flag = 1;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (chessboard[i][j] == ' ')
            {
                flag = 0;
                return flag;
            }
        }
    }
    return flag;
}

void trimoku_play(int flag, int line, int column, int player_flag, int *win_num)
{
    int draw_flag = 0;
    char trimoku_chessboard[256][256];
    int end_flag = 1;
    int filter = 0;
    int ai_flag = 0;
    int input_check = 1;
    char ch = 1;
    char a = ' ', b = ' ';
    int arroy[2] = {0, 0};
    int arroy_copy[2] = {0, 0};
    int step = 0;

    filter = rand();

    if (flag == 1)
    {
        ai_flag = 1;
    }
    trimoku_chessboard_init(trimoku_chessboard, line, column);

    if (ai_flag) // PVE
    {
        do
        {
            if (trimoku_draw_judgement(trimoku_chessboard, line, column))
            {
                printf("Five even!\n");
                draw_flag = 1;
            }
            if (player_flag > 0)
                printf("P%d:\n\n", 1);
            else
                printf("P%d:\n\n", 2);

            player_flag = -player_flag;

            trimoku_chessboard_displayer(line, column, trimoku_chessboard);
            if (step)
            {
                if (trimoku_gg_flag_maker(trimoku_chessboard, *win_num, arroy[0], arroy[1], line, column, player_flag))
                {
                    printf("Game over!\n");
                    if (player_flag > 0)
                        printf("P%d win!\n\n", 1);
                    else
                        printf("P%d win!\n\n", 2);
                    break;
                }
                if (draw_flag)
                {
                    break;
                }
            }

            if (player_flag < 0)
            {
                do
                {
                    do
                    {
                        input_check = 1;
                        if (2 == scanf("%d,%d", &arroy[0], &arroy[1]))
                        {
                            input_check = 0;
                        }
                        else
                        {
                            while ((ch = getchar()) != '\n')
                            {
                                ;
                            }
                        }

                    } while (input_check);

                    arroy_copy[0] = arroy[0];
                    arroy_copy[1] = arroy[1];

                    trimoku_stdtrans(arroy, line, column);
                    printf("(%d,%d) already has a chessman!\n", arroy_copy[0], arroy_copy[1]);
                } while (' ' != (trimoku_chessboard[arroy[0]][arroy[1]]));
            }
            else
            {
                do
                {
                    do
                    {
                        arroy[0] = rand() % (line + 1);
                        arroy[1] = rand() % (column + 1);
                    } while ((arroy[0] < 0) || (arroy[1] < 0));

                    arroy_copy[0] = arroy[0];
                    arroy_copy[1] = arroy[1];

                    trimoku_stdtrans(arroy, line, column);
                    printf("(%d,%d) already has a chessman!\n", arroy_copy[0], arroy_copy[1]);
                } while (' ' != (trimoku_chessboard[arroy[0]][arroy[1]]));
            }

            clear();
            step++;

            if (player_flag > 0)
                trimoku_chessboard[arroy[0]][arroy[1]] = '#';
            else
                trimoku_chessboard[arroy[0]][arroy[1]] = '*';

        } while (end_flag);
    }

    else // PVP
    {
        do
        {
            if (trimoku_draw_judgement(trimoku_chessboard, line, column))
            {
                printf("Five even!\n");
                draw_flag = 1;
            }
            if (player_flag > 0)
                printf("P%d:\n\n", 1);
            else
                printf("P%d:\n\n", 2);

            player_flag = -player_flag;

            trimoku_chessboard_displayer(line, column, trimoku_chessboard);
            if (step)
            {
                if (trimoku_gg_flag_maker(trimoku_chessboard, *win_num, arroy[0], arroy[1], line, column, player_flag))
                {
                    printf("Game over!\n");
                    if (player_flag > 0)
                        printf("P%d win!\n\n", 1);
                    else
                        printf("P%d win!\n\n", 2);
                    break;
                }
                if (draw_flag)
                {
                    break;
                }
            }

            do
            {
                do
                {
                    input_check = 1;
                    if (2 == scanf("%d,%d", &arroy[0], &arroy[1]))
                    {
                        input_check = 0;
                    }
                    else
                    {
                        while ((ch = getchar()) != '\n')
                        {
                            ;
                        }
                    }

                } while (input_check);
                arroy_copy[0] = arroy[0];
                arroy_copy[1] = arroy[1];

                trimoku_stdtrans(arroy, line, column);
                printf("(%d,%d) already has a chessman!\n", arroy_copy[0], arroy_copy[1]);
            } while (' ' != (trimoku_chessboard[arroy[0]][arroy[1]]));

            clear();
            step++;

            if (player_flag > 0)
                trimoku_chessboard[arroy[0]][arroy[1]] = '#';
            else
                trimoku_chessboard[arroy[0]][arroy[1]] = '*';

        } while (end_flag);
    }
}

void trimoku_setting_menu()
{
    printf("#####  1.Sequential order  #####\n");
    printf("#####   2.Chessboard size  #####\n");
    printf("#####   3.Victory number   #####\n");
    printf("#####        0.Exit        #####\n");
}

int trimoku_setting_size_set(int *line, int *column)
{
    int input = 0;
    clear();
    printf("Set the row number of chessboard.\n");
    printf("Enter 0 to cancel.\n");

    scanf("%d", &input);
    if (!input)
    {
        return 0;
    }
    *line = input;
    printf("Set the column number of chessboard.\n");
    printf("Enter 0 to cancel.\n");

    scanf("%d", &input);
    if (!input)
    {
        return 0;
    }
    *column = input;
    return 0;
}

void trimoku_victory_number_set(int *victory_num)
{
    int vn = 3;
    printf("Enter the victory num.\n");
    scanf("%d", &vn);
    *victory_num = vn;
}

void trimoku_guide_menu()
{
    clear();
    printf("Developed by spl-clauvio\n");
    printf("Copyright by spl-clauvio\n");
    printf("\n\n");
}

void trimoku_setting(int *place, int *line, int *column, int *victory_num)
{
    int input = 0;
    clear();
    trimoku_setting_menu();
    scanf("%d", &input);
    clear();

    switch (input)
    {
    case 1:
        clear();
        printf("1:player first\n-1:computer first\n");
        scanf("%d", place);
    case 2:
        trimoku_setting_size_set(line, column);
        break;
    case 3:
        trimoku_victory_number_set(victory_num);
        break;
    default:
        break;
    }
}

void trimoku_main()
{
    int player_flag = 1;
    int victory_num = 3;
    int trmoku_main_input = 0;
    int line = 3, column = 3;
    do
    {
        clear();
        trimoku_main_menu();
        scanf("%d", &trmoku_main_input);
        clear();

        switch (trmoku_main_input)
        {
        case 1:
            trimoku_play(trmoku_main_input, line, column, player_flag, &victory_num);
            game_return_menu();
            break;
        case 2:
            trimoku_play(trmoku_main_input, line, column, player_flag, &victory_num);
            game_return_menu();
            break;
        case 3:
            trimoku_setting(&player_flag, &line, &column, &victory_num);
            trimoku_return_menu();
            break;
        case 4:
            trimoku_guide_menu();
            trimoku_return_menu();
            break;
        default:
            break;
        }

    } while (trmoku_main_input);
}

void minesweeper_main_menu()
{
    printf("#####         Welcome!       #####\n");
    printf("#####          1.Play        #####\n");
    printf("#####        2.Settings      #####\n");
    printf("#####         3.Guide        #####\n");
    printf("#####          0.Exit        #####\n");
}

void minesweeper_guide()
{
    clear();
    printf("Developed by spl-clauvio\n");
    printf("Copyright by spl-clauvio\n");
    printf("\n\n");
}

void minesweeper_return_menu()
{
    int over = 0;
    printf("\n#####  1.Minesweeper menu  #####\n");
    scanf("%d", &over);
}

void minesweeper_stdtrans(int input[], int line, int column)
{
    int a = input[0], b = input[1];
    input[1] = a - 1;
    input[0] = line - b;
}

int minesweeper_mine_number_return(int line, int column, int a, int b, int mine_layer[100][100])
{
    int i = 0, j = 0, ret = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((a - 1 + i >= 0 && a - 1 + i < line) && (b - 1 + j >= 0 && b - 1 + j < column))
            {
                if (mine_layer[a - 1 + i][b - 1 + j])
                {
                    ret++;
                }
            }
        }
    }
    return ret;
}

void minesweeper_num_layer_generator(int line, int column, int mine_layer[100][100], int num_layer[100][100])
{
    int i = 0, j = 0;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
        {
            num_layer[i][j] = minesweeper_mine_number_return(line, column, i, j, mine_layer);
        }
    }
}

void minesweeper_mine_generator(int line, int column, int mine, int mine_layer[100][100])
{
    int i = 0, j = 0, count = 0, check = 0, check_flag = 0, filter = 0;
    int rand_line = 0, rand_column = 0;
    int rand_check_arroy[100][101] = {0};
    filter = rand();

    for (count = 0; count < mine; count++)
    {
        do
        {
            check_flag = 0;
            rand_line = rand() % (line);
            rand_column = rand() % (column);

            rand_check_arroy[rand_line][rand_check_arroy[rand_line][0] + 1] = rand_column;

            for (check = 0; check < rand_check_arroy[rand_line][0]; check++)
            {
                if (rand_check_arroy[line][check + 1] == rand_column)
                {
                    check_flag = 1;
                }
            }
        } while (check_flag);

        rand_check_arroy[rand_line][0]++; // count line members

        mine_layer[rand_line][rand_column] = 1;
    }
}

void minesweeper_board_displayer(int flag, int line, int column, int num_layer[100][100], int display_chose_layer[100][100], int sign_layer[100][100], int mine_layer[100][100])
{
    int i = 0, j = 0;
    for (i = 0; i < line; i++)
    {
        printf("   ");
        for (j = 0; j < column; j++)
        {
            printf("+---");
        }
        printf("+\n");
        printf("%-3d", line - i);

        for (j = 0; j < column; j++)
        {
            if (flag)
            {
                if (mine_layer[i][j])

                    printf("|***");
                else if (display_chose_layer[i][j])
                {
                    if (num_layer[i][j])
                        printf("| %d ", num_layer[i][j]);
                    else
                        printf("| %c ", ' ');
                }
                else if (sign_layer[i][j])
                {
                    printf("|!!!");
                }
                else
                    printf("| %c ", '#');
            }
            else
            {
                if (display_chose_layer[i][j])
                {
                    if (num_layer[i][j])
                        printf("| %d ", num_layer[i][j]);
                    else
                        printf("| %c ", ' ');
                }
                else if (sign_layer[i][j])
                {
                    printf("|!!!");
                }
                else
                    printf("| %c ", '#');
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (j = 0; j < column; j++)
    {
        printf("+---");
    }
    printf("+\n");
    printf("y/x ");
    for (j = 0; j < column; j++)
    {
        printf(" %-3d", j + 1);
    }
    printf("\n");
}

void minesweeper_0_spread(int *demining_num, int line, int column, int x, int y, int num_layer[100][100], int display_chose_layer[100][100])
{
    int i = 0, j = 0;
    if (!num_layer[x][y])
    {
        (*demining_num)++;
        display_chose_layer[x][y] = 1;
        for (i = x - 1; i < x + 2; i++)
        {
            for (j = y - 1; j < y + 2; j++)
            {
                if ((i >= 0 && i < line) && (j >= 0 && j < column))
                {
                    if (!display_chose_layer[i][j])
                    {
                        minesweeper_0_spread(demining_num, line, column, i, j, num_layer, display_chose_layer);
                    }
                }
            }
        }
    }
    else
    {
        (*demining_num)++;
        display_chose_layer[x][y] = 1;
    }
}

void minesweeper_play(int line, int column, int mine)
{
    int mine_layer[100][100] = {0};
    int num_layer[100][100] = {0};
    int display_chose_layer[100][100] = {0};
    int sign_layer[100][100] = {0};
    int ch = 1;
    int input[2] = {0};

    int first_input_flag = 1, i = 0, j = 0;
    int reinit_i = 0, reinit_j = 0;
    int first_expload_flag = 0;
    int victory_flag = 1;
    int demining_num = 0;
    int op_check = 0;
    int op_check_finish_flag = 1;
    int exit_flag = 0;
    int input_check = 1;

    minesweeper_mine_generator(line, column, mine, mine_layer);

    minesweeper_num_layer_generator(line, column, mine_layer, num_layer);

    do
    {
        clear();

        if (!first_input_flag)
        {
            minesweeper_0_spread(&demining_num, line, column, input[0], input[1], num_layer, display_chose_layer);
            first_input_flag = 0;
        }

        // minesweeper_board_displayer(1, line, column, mine_layer, display_chose_layer);
        minesweeper_board_displayer(0, line, column, num_layer, display_chose_layer, sign_layer, mine_layer);

        if (demining_num == line * column - mine)
        {
            victory_flag = 0;
            printf("Victory!\n");
            break;
        }

        do
        {
            op_check_finish_flag = 1;

            printf("Enter a coordinate(x,y),use blankspace to separate x from y.\n");
            printf("Exit the game by entering (0,0)\n");

            do
            {
                do
                {
                    input_check = 1;
                    if (2 == scanf("%d %d", &input[0], &input[1]))
                    {
                        input_check = 0;
                    }
                    else
                    {
                        while ((ch = getchar()) != '\n')
                        {
                            ;
                        }
                    }

                } while (input_check);
            } while (input[0] < 0 || input[0] > column || input[1] < 0 || input[1] > line);

            if ((input[0] == 0) && (input[1] == 0))
            {
                exit_flag = 1;
                break;
            }

            minesweeper_stdtrans(input, line, column);

            printf("Comfirm your oparation.\n");
            printf("\'0\' -> check the coordinate.\n");
            printf("\'1\' -> put/remove a sign.\n");
            printf("Enter any other num to cancel.\n");
            scanf("%d", &op_check);

            switch (op_check)
            {
            case 0:
                op_check_finish_flag = 0;
                break;
            case 1:
                if (sign_layer[input[0]][input[1]])
                {
                    sign_layer[input[0]][input[1]] = 0;
                }
                else
                {
                    sign_layer[input[0]][input[1]] = 1;
                }
                clear();
                minesweeper_board_displayer(0, line, column, num_layer, display_chose_layer, sign_layer, mine_layer);
                break;
            default:
                break;
            }

        } while (op_check_finish_flag);

        if (exit_flag)
        {
            break;
        }

        if (first_input_flag)
        {

            do
            {
                first_expload_flag = 0;
                if (num_layer[input[0]][input[1]])
                {
                    first_expload_flag = 1;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if ((input[0] - 1 + i >= 0 && input[0] - 1 + i < line) && (input[1] - 1 + j >= 0 && input[1] - 1 + j < column))
                            {
                                if (mine_layer[input[0] - 1 + i][input[1] - 1 + j])
                                {
                                    for (reinit_i = 0; reinit_i < line; reinit_i++)
                                    {
                                        for (reinit_j = 0; reinit_j < column; reinit_j++)
                                        {
                                            mine_layer[reinit_i][reinit_j] = 0;
                                            num_layer[reinit_i][reinit_j] = 0;
                                        } // reinit
                                    }
                                    minesweeper_mine_generator(line, column, mine, mine_layer);

                                    minesweeper_num_layer_generator(line, column, mine_layer, num_layer);
                                }
                            }
                        }
                    }
                }
            } while (first_expload_flag);
            first_input_flag = 0;
        }
        else
        {
            if (mine_layer[input[0]][input[1]])
            {
                clear();
                printf("\aEXplosion!\n");
                minesweeper_board_displayer(1, line, column, num_layer, display_chose_layer, sign_layer, mine_layer);

                break;
            }
        }

    } while (victory_flag);
    char ch_clear = 0;
    while (ch_clear = getchar() != '\n')
    {
        ;
    }
}

void minesweeper_setting_menu()
{
    printf("#####      1.Difficulty set      #####\n");
    printf("#####      2.Minefilds size      #####\n");
    printf("#####           0.Exit           #####\n");
}

void minesweeper_difficulty_set(int *line, int *column, int *mine)
{
    int default_difficulty_levels = 1;
    printf("#####          1.Easy          #####\n");
    printf("#####       2.Middle set       #####\n");
    printf("#####      3.Professional      #####\n");
    printf("#####         0.Cancel         #####\n");

    scanf("%d", &default_difficulty_levels);

    switch (default_difficulty_levels)
    {
    case 1:
        *line = 9, *column = 9, *mine = 10;
        break;
    case 2:
        *line = 16, *column = 16, *mine = 40;
        break;
    case 3:
        *line = 16, *column = 30, *mine = 99;
        break;
    case 0:
        printf("Operation is canceled.\n");
        pause();
        break;
    default:
        printf("Err input,operation is canceled.\n");
        pause();

        break;
    }
}

void minesweeper_broad_set(int *a, int *b)
{
    int err_flag = 0;
    do
    {

        printf("Enter the row number.\n");
        scanf("%d", a);
        printf("Enter the column number.\n");
        scanf("%d", b);
        if (*a < 0 || *b < 0)
        {
            err_flag = 1;
        }
        else
        {
            err_flag = 0;
        }

    } while (err_flag);
}

void minesweeper_setting(int *a, int *b, int *c)
{
    int input = 0;
    do
    {
        clear();
        minesweeper_setting_menu();
        scanf("%d", &input);
        clear();

        switch (input)
        {
        case 1:
            minesweeper_difficulty_set(a, b, c);
            break;
        case 2:
            minesweeper_broad_set(a, b);
            break;
        default:
            break;
        }
    } while (input);
}

void minesweeper_main()
{
    int input = 0;
    int line = 9, column = 9, mine = 10;

    do
    {
        clear();
        minesweeper_main_menu();
        scanf("%d", &input);
        clear();

        switch (input)
        {
        case 1:
            minesweeper_play(line, column, mine);
            minesweeper_return_menu();
            break;
        case 2:
            minesweeper_setting(&line, &column, &mine);
            break;
        case 3:
            minesweeper_guide();
            minesweeper_return_menu();
            break;
        default:
            break;
        }
    } while (input);
}

void game_main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####      1.Trimoku       #####\n");
    printf("#####     2.Minesweep      #####\n");
    printf("#####        0.Exit        #####\n");
}

void myth_main_menu()
{
    printf("#####      1.Prime number      #####\n");
    printf("#####     2.Tower of Hanoi     #####\n");
    printf("#####   3.Fibonacci sequence   #####\n");
    printf("#####     4.Number counter     #####\n");
    printf("#####     5.Size of types      #####\n");
    printf("#####     6.Sort an arroy      #####\n");
    printf("#####   7.Slef expontiation    #####\n");
    printf("#####          0.Exit          #####\n");
}

void binary_return_menu()
{
    int over = 0;
    printf("\n#####  1.Binary menu  #####\n");
    scanf("%d", &over);
}

void binary_1_num()
{
    unsigned int input = 0;
    int num = 0, i = 0;
    int binary[32] = {0};

    printf("Enter a num(10)\n");
    scanf("%d", &input);

    int count = 0;

    printf("\nThe binary of %d in memory is ", input);

    while (input)
    {
        if (input % 2)
        {
            count++;
            binary[i] = 1;
        }
        else
        {
            binary[i] = 0;
        }
        input /= 2;
        i++;
    }
    i--;

    while (i + 1)
    {
        printf("%d", binary[i]);
        i--;
    }

    printf("\n%d num 1 is in it\n", count);
}

int binary_1_num1()
{
    int input = 0;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((input >> i) & 1)
        {
            count++;
        }
    }
    return count;
}

int binary_1_num_0(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1); // 每次消掉右侧一个1;
        count++;
    }
    return count;
}

int binary_difference_inside(int input[2])
{
    int num = 0;
    num = input[0] ^ input[1];

    return binary_1_num_0(num);
}

int binary_difference()
{
    int input_check = 1;
    int input[2] = {0};

    do
    {
        printf("Enter 2 numbers\n");
        if (2 == scanf("%d %d", &input[0], &input[1]))
        {
            input_check = 0;
        }
    } while (input_check);

    printf("%d\n", binary_difference_inside(input));
    return 0;
}

void binary_is2power()
{
    int input = 0;
    int input_check = 0;
    int input_check1 = 0;
    int i = 0;
    printf("Enter a positive number\n");
    do
    {
        input_check = scanf("%d", &input);
        if (input_check)
        {
            if (input > 0)
            {
                input_check1 = 1;
            }
        }
    } while (!input_check1);

    if (input - 1)
    {
        if (!(input & (input - 1)))
        {
            for (i = 1; i < 32; i++)
            {
                if ((input >> i) == 1)
                    break;
            }
            printf("%d is the %d power of 2\n", input, i);
        }
        else
        {
            printf("%d is not power of 2\n", input);
        }
    }
    else
    {
        printf("%d is not power of 2\n", input);
    }
}

void binary_main_menu()
{
    printf("#####       1.Difference       #####\n");
    printf("#####         2.'1' num        #####\n");
    printf("#####       3.Power of 2       #####\n");
    printf("#####          0.Exit          #####\n");
}

void myth_main()
{
    int myth_main_input = 0;
    int input = 0;

    do
    {
        clear();
        myth_main_input = 0;
        myth_main_menu();
        initgraph(800, 800, 1);
        IMAGE math;
        loadimage(&math, _T("./picture/mix/math_menu.png"));
        putimage(0, 0, &math);

        ExMessage mymouse;
        while (1)
        {
            while (peekmessage(&mymouse))
            {
                switch (mymouse.message)
                {
                case WM_LBUTTONDOWN:
                    clear();
                    if (mymouse.x > 16 && mymouse.x < 256)
                    {
                        if (mymouse.y > 220 && mymouse.y < 280)
                        {
                            input = 2;
                        }
                        else if (mymouse.y > 291 && mymouse.y < 351)
                        {
                            input = 3;
                        }
                        else if (mymouse.y > 362 && mymouse.y < 422)
                        {
                            input = 4;
                        }

                        else if (mymouse.y > 433 && mymouse.y < 493)
                        {
                            input = 5;
                        }
                        else if (mymouse.y > 504 && mymouse.y < 564)
                        {
                            input = 6;
                        }
                        else if (mymouse.y > 575 && mymouse.y < 635)
                        {
                            input = 7;
                        }
                        else if (mymouse.y > 646 && mymouse.y < 706)
                        {
                            input = 8;
                        }
                        else if (mymouse.y > 717 && mymouse.y < 777)
                        {
                            input = 1;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            if (input)
            {
                break;
            }
        }
        input--;
        // scanf("%d", &myth_main_input);
        clear();

        closegraph();

        switch (input)
        {
        case 1:
            prime_main();
            break;
        case 2:
            hanoi_main();
            break;
        case 3:
            fibonacci_sequence_main();
            break;
        case 4:
            number_counter_main();
            break;
        case 5:
            size_of_types();
            break;
        case 6:
            sort_arroy_main();
            break;
        case 7:
            daffodil_main();
            break;
        default:
            break;
        }

    } while (input);
}

void binary_main()
{
    int input = 0;

    do
    {
        clear();

        binary_main_menu();

        scanf("%d", &input);
        clear();

        switch (input)
        {
        case 1:
            binary_difference();
            binary_return_menu();
            break;
        case 2:
            binary_1_num();
            binary_return_menu();
            break;
        case 3:
            binary_is2power();
            binary_return_menu();
            break;
        default:
            break;
        }

    } while (input);
}

void game_main()
{
    int game_main_input = 0;
    do
    {
        clear();

        game_main_menu();
        scanf("%d", &game_main_input);
        clear();

        switch (game_main_input)
        {
        case 1:
            trimoku_main();
            break;
        case 2:
            minesweeper_main();
            break;
        default:
            break;
        }

    } while (game_main_input);
}

void main_menu()
{
    printf("#####       Welcome!       #####\n");
    printf("#####        1.Myth        #####\n");
    printf("#####       2.Binary       #####\n");
    printf("#####        3.Game        #####\n");
    printf("#####        0.Exit        #####\n");
    printf("\nMain menu load successfully!\n");
    printf("Enter a number.____");
}

int account()
{
    int password_trying_times = 0;
    char password[20] = {"123zlaw123"};
    char password_enter[20] = {"0"};
    printf("Please enter your password.\n");
    for (password_trying_times = 0; password_trying_times < 3; password_trying_times++)
    {
        switch (password_trying_times)
        {
        case 0:
            printf("First entering.\n");
            break;
        case 1:
            printf("Second entering.\n");
            break;
        case 2:
            printf("Third entering.\n");
            break;
        }

        scanf("%s", password_enter);
        clear();
        if (!strcmp(password, password_enter))
        {
            printf("Password correct!\n\n");
            return 1;
            break;
        }
        else
        {
            printf("Password incorrect!\n");
            switch (password_trying_times)
            {
            case 0:
                printf("Two trying chances left.\n");
                break;
            case 1:
                printf("One trying chance left.\n");
                break;
            case 2:
                printf("You have used up all entering chances!\nProgram is about to exit.\n\n");

                pause();
                return 0;
                break;
            }
        }
    }
    return 0;
}

int main()
{
    int password_flag = 0;
    int input = -1;

    srand((unsigned int)time(NULL));

    if (password_flag)
    {
        if (0 == account())
        {
            return 0;
        }
    }

    do
    {
        input = -1;
        initgraph(800, 800, 1);

        IMAGE main_menu_pic;
        loadimage(&main_menu_pic, _T("D:/C_PP/picture/mix/main_menu.png"));

        putimage(0, 0, &main_menu_pic);

        main_menu();

        setfillcolor(BLACK);
        int flag = 1;
        int i = 0;

        ExMessage mymouse;
        while (flag)
        {
            while (flag && peekmessage(&mymouse, EM_MOUSE))
            {
                switch (mymouse.message)
                {
                case WM_LBUTTONDOWN:

                    if (mymouse.x > 295 && mymouse.x < 505)
                    {
                        if (mymouse.y > 389 && mymouse.y < 477)
                        {
                            input = 1;
                            flag = 0;
                        }
                        else if (mymouse.y > 492 && mymouse.y < 580)
                        {
                            flag = 0;
                            input = 2;
                        }
                        else if (mymouse.y > 595 && mymouse.y < 683)
                        {
                            flag = 0;
                            input = 3;
                        }

                        else if (mymouse.y > 698 && mymouse.y < 786)
                        {
                            flag = 0;
                            input = 0;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            if (input >= 0)
            {
                break;
            }
        }
        closegraph();
        switch (input)
        {
        case 1:
            myth_main();
            break;
        case 2:
            binary_main();
            break;
        case 3:
            game_main();
            break;
        default:
            break;
        }

    } while (input);

    clear();
    // pause();
    return 0;
}