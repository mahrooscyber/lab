#include<stdio.h>

void main()
{
    int i,j;
    int key[2][2]={{2,3},{3,6}};
    char a[]="attack";
    int len=sizeof(a)-1;
    char e[len],num[len],d[len];

    //calculating number equivalents
    for(i=0;i<len;i++)
    {
        num[i]=a[i]-'a';
    }

    //encryption using matrix multiplication
    for(i=0;i<len;i=i+2)
    {
        e[i]=((num[i]*key[0][0])%26+(num[i+1]*key[1][0])%26)%26;
        e[i+1]=((num[i]*key[0][1])%26+(num[i+1]*key[1][1])%26)%26;
    }

    char enc[len];

    for(i=0;i<len;i++)
    {
        enc[i]=e[i]+'a';
    }

    printf("Original string=%s\n",a);
    printf("Encrypted string=%s\n",enc);

    //calculating del of key
    int del=(key[0][0]*key[1][1])-(key[0][1]*key[1][0]);
    int del_inv;

    for(i=0;i<26;i++)
    {
        if((del*i)%26==1)
        {
            del_inv=i;
            break;
        }
    }

    //finding adjoint of key
    int k_adj[2][2]={{key[1][1],0-key[0][1]},{0-key[1][0],key[0][0]}};

    int k_inv[2][2];

    //finding inverse of key
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            k_inv[i][j]=k_adj[i][j]*del_inv;
        }
    }

    //eliminating any negative numbers
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            if(k_inv[i][j]<0)
            {
                k_inv[i][j]+=26;
            }
        }
    }

    //decryption using matrix multiplication
    for(i=0;i<len;i=i+2)
    {
        d[i]=((e[i]*k_inv[0][0])%26+(e[i+1]*k_inv[1][0])%26)%26;
        d[i+1]=((e[i]*k_inv[0][1])%26+(e[i+1]*k_inv[1][1])%26)%26;
    }

    char dec[len];

    for(i=0;i<len;i++)
    {
        dec[i]=d[i]+'a';
    }

    printf("Decrypted string=%s\n",dec);
}
