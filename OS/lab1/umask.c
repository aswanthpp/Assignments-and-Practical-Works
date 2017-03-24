#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{       int p;
        p=umask(mask);
        printf("%d\n",p);
}
~         
