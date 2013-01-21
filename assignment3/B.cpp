int
main()
{
    int phone_digits[] = { 3, 3, 1, 2, 9, 1, 5 };
    char phone_chars[] = "331-2915";
    int i = 3;
    int * ip = &i;
    int * pn;
    char * ps = phone_chars;

    pn = phone_digits;

    int value01 = phone_digits[i];

    char value02 = phone_chars[i];

    int * value03 = pn;

    int * value04 = phone_digits;

    int value05 = pn[i];

    int * value06 = &i;

    int value07 = *ip;

    char * value08 = ps;

    char * value09 = phone_chars;

    int value10 = *phone_digits;

    char value11 = *phone_chars;

    int ** value12 = &ip;

    int ** value13 = &pn;

    char ** value14 = &ps;

    int value15 = *&i;

    int * value16 = *&ip;

    char * value17 = *&ps;

    int * value18 = &phone_digits[0];

    int * value19 = &phone_digits[i];

    char * value20 = &phone_chars[0];

    char * value21 = &phone_chars[i];
}
