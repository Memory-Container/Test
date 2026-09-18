#include <stdio.h>
#include <math.h>
int main(){
    int d;   
    scanf("%d" ,&d);
    if (d < 0) return 0;
    int l;
    int sum = 0;
    int N_d;
    if(d % 2 == 0)
    {
            l = d / 2;
        for(int y = 1;y <= l; y++){
        sum += 0.5 + sqrt(pow(d,2)- pow(2 * y - 1, 2))/2;         
    }      
        N_d = 4 * sum;
    }
    else
        {
            l = ( d + 1) / 2 - 1;
        for(int y = 1; y <= l; y++){
            sum += 1 + (sqrt(pow(d, 2) - 4 * pow(y,2))/2);          
        }
        N_d = 1 + 4 * sum;
    }
    printf("%d", N_d);  
    return 0;
}