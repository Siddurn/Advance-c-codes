#include <stdio.h>
#include <stdlib.h>

float variance(int *, int);

int main()
{
    int N;
    
    scanf("%d",&N);
    int *arr=malloc(N*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program indicating failure
    }
    printf("Enter integers:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("variance is :%f\n",variance(arr,N));
    
    free(arr); // Free dynamically allocated memory
    
    return 0;
 
}


float variance(int *arr, int N)
{
    int sum_arr=0;
    float mean,sum_Dsqr=0,var;
    
    for(int i=0;i<N;i++)
    {
        sum_arr+=*(arr+i);
    }
    mean=(float)sum_arr/N;
    float D[N],D_sqr[N];
    for(int i=0;i<N;i++)
    {
        D[i]=arr[i]-mean;
        D_sqr[i]=D[i]*D[i];
        sum_Dsqr+=D_sqr[i];
    }
    var=sum_Dsqr/N;
    return var;
}

/*9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31*/