#include <math.h>

int main()
{
    long long d;

    scanf("%lld", &d);

    long long l = d / 2;
    long long ans = 0;

    if (d % 2 == 1)
    {
        ans = 1;

        for (long long y = 1; y <= l; y++)
        {
            ans += 4 * (long long)floor(
                1 + 0.5 * sqrt((double)d * d - 4.0 * y * y)
            );
        }
    }
    else
    {
        for (long long y = 1; y <= l; y++)
        {
            ans += 4 * (long long)floor(
                0.5 + 0.5 * sqrt(
                    (double)d * d
                    - (2.0 * y - 1) * (2.0 * y - 1)
                )
            );
        }
    }

    printf("%lld", ans);

    return 0;
}
