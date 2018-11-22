#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//pipe
#include <sys/types.h>

#include <fcntl.h>
//signal
#include <signal.h>

int main(){
char str[1024];
char *text1=NULL;
char *text2=NULL;

char *command1[4];
char *command2[5];
int i;
char *pch;
//pipe
int fd[2];
int fdr;
pid_t pid;

//signal
sigset_t blockset;
sigemptyset(&blockset);
sigaddset(&blockset, SIGINT);
sigaddset(&blockset, SIGQUIT);
sigprocmask(SIG_BLOCK, &blockset, NULL);

while(1){
for(i=0; i<1024; i++){
str[i]='\0';
}
command1[0]=NULL;command1[1]=NULL;command1[2]=NULL;command1[3]=NULL;
command2[0]=NULL;command2[1]=NULL;command2[2]=NULL;
printf("$");
fgets(str,sizeof(str),stdin);
if(feof(stdin)){
printf("Ctrl+D exit \n");
exit(0);
fflush( stdin );

if(strchr(str, '|')!=NULL){
text1 = strtok (str, "|");
text2 = strtok (NULL, "|");

strcat(text1, "\0");
strcat(text2, "\0");

i=0;
pch = strtok (text1," ");
while (pch != NULL && i<3)
{command1[i]=pch;
pch = strtok (NULL, " ");
i++;
}
command1[i]=(char*)0;
i=0;
pch = strtok (text2, " ");
while (pch != NULL && i<3)
{
command2[i]=pch;
pch = strtok(NULL, " ");
i++;
}
command2[i]=(char*)0;

if(pipe(fd) == -1){
printf("fail to call pipe()\n");
exit(1);
}
}
}
}
}
