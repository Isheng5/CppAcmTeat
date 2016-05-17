//
// Created by zengjiean on 16-5-17.
//

# include <stdio.h>
int c64()
{
	int n,m,a,i,t;
	scanf("%d",&a);
	while(a--)
	{
		t=0;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			if(m==i*2+(n-i)*4)
			{
				printf("%d %d\n",i,n-i);
				t++;
			}
		}
		if(t==0)
			printf("No answer\n");
	}
	return 0;
}