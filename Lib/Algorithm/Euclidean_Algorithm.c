#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))



int greatestCommonDivisor(int arg1, int arg2) {
    int a = max(arg1, arg2);
    int b = min(arg1, arg2);

    int tmp = 0;
    while (1) {
        tmp = a % b;
        if (tmp == 0) break;
        a = b;
        b = tmp;
    }

    return b;
}


int leastCommonMultiple(int arg1, int arg2, int gcd)  {
    return arg1 * arg2 / gcd;
}
