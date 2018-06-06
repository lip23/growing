#include <stdio.h>
#include <string.h>

int main()
{
	char word[6];
	while(gets(word)&&strcmp(word,"#")!=0)
	{
		int times[5];
		memset(times,0,sizeof(times));
		char line[81];
		gets(line);
		int l=strlen(line);
		int lw=strlen(word);
		for(int i=0;i<l;i++)
			for(int j=0;j<lw;j++)
				if(line[i]==word[j])
					times[j]++;
		for(i=0;i<lw;i++)
			printf("%c %d\n",word[i],times[i]);
	}
	return 0;
}
