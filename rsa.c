#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int p=3,q=11,m=5,n,phi,e=7,d,c,M;

    //cal n
    n=p*q;

    //cal phi
    phi=(p-1)*(q-1);

    //cal d
    d=1;
    while(((e*d)%phi!=1))
    {
        d++;
    }

    //Encryption
    c=(int)(pow(m,e))%n;

    //Decryption
    M=(int)(pow(c,d))%n;

    printf("Given input:\t%d\n",m);
    printf("Encrypted:\t%d\n",c);
    printf("Decrypted:\t%d\n",M);
}
