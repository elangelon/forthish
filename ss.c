/*....:....4....:....5....:....6....:....7....:....8....:....9....:....10
    !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcd
  efghijklmnopqrstuvwxyz{|}~ */

#include <stdio.h>  /* stable.c STABLE minimalist FORTH like VM */
#include <string.h> /* ss.c is a version of STABLE both by Sandor Schneider */
#include <stdlib.h>
#include <math.h>
union flin { float f[2400]; int i[2400]; char b[9600]; }; static union flin st; 
static char ex[80],t=0,u,a,k=0; static int x=0,i,c,v,m,r,p,n,mx,s,f;
void N(){;} void f33(){st.i[st.i[v]]=st.i[s]; s--; } void Z(){k=1; v=u; }
void f34(){p++;u=st.b[p];while(u!='\"'){putc(u,stdout);p++;u=st.b[p];}}
void f35(){s++; st.i[s]=st.i[s-1];} void f42(){st.i[s-1]*=st.i[s]; s--; }
void f36(){i=st.i[s]; st.i[s]=st.i[s-1]; st.i[s-1]=i;}
void f37(){st.i[s-1]%=st.i[s]; s--; } void f38(){st.i[s-1]&=st.i[s]; s--; }
void f39(){ p++; u=st.b[p]; 
   if(u=='\''){st.f[s]=st.i[s]; } if(u=='0') { st.i[s]=st.f[s]; }
   if(u=='.') {printf("%f",st.f[s]); s--;} if(u=='+'){ st.f[s-1]+=st.f[s];  s--;}
   if(u=='-') {st.f[s-1]-=st.f[s];  s--;}  if(u=='*'){ st.f[s-1]*=st.f[s];  s--;}
   if(u=='/') {st.f[s-1]/=st.f[s];  s--;}
   if(u=='s') {st.f[s]=sqrt(st.f[s]); }
   if(u=='|') {st.i[s-1]^=st.i[s];  s--;}}
void f40(){if(st.i[s]==0){s--;p++;u=st.b[p];while(u!=')'){p++;u=st.b[p];}} else{s--;}}
void f43(){ if(k==0){st.i[s-1]+=st.i[s]; s--; }else{st.i[v]++;} }
void f44(){printf("%c",st.i[s]); s--; } void B5(){st.i[s]=-st.i[s]; }
void f45(){ if(k==0){st.i[s-1]-=st.i[s]; s--; }else{st.i[v]--;} }
void f46(){printf("%d",st.i[s]); s--;} void f47(){st.i[s-1]/=st.i[s]; s--; }
void B(){i=0;while((u>='0')&&(u<='9')){i=i*10+u-'0';p++;u=st.b[p];}s++;st.i[s]=i;p--;}
void f58(){st.i[v]=st.i[s]; s--; } void f59(){s++; st.i[s]=st.i[v]; }
void f60(){if(st.i[s]> st.i[s-1]){st.i[s]=-1;}else{st.i[s]=0;}}
void f61(){if(st.i[s]==st.i[s-1]){st.i[s]=-1;}else {st.i[s]=0;}}
void f62(){if(st.i[s]< st.i[s-1]){st.i[s]=-1;}else{st.i[s]=0;}}
void f63(){s++; st.i[s]=st.i[st.i[v]]; } void f64(){st.i[s+1]=st.i[s-1]; s++; }
void A(){r++; st.i[r]=p; p=st.i[u]; u=st.b[p]; p--;}
void B1(){r++;st.i[r]=p;if(st.i[s]==0){p++;u=st.b[p]; while(u!=']'){ p++; u=st.b[p];}}}
void B2(){s--;} void B3(){if(st.i[s]!=0) p=st.i[r]; else r--; s--; }
void B4(){if((c=getc(stdin))==EOF) { c=0; } s++; st.i[s]=c; }
void B6(){x=0; p++; while(st.b[p]!='`'){ex[x++]=st.b[p];p++;} ex[x]=0; system(ex); } 
void f123(){f=st.b[p+1];st.i[f]=p+2;while(u!='}'){p++;u=st.b[p];}}
void f124(){st.i[s-1]|=st.i[s]; s--; }
void f125(){p=st.i[r];r--;}
void f126(){st.i[s]=~st.i[s]; }
void (*q[127])()={N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,
f33,f34,f35,f36,f37,f38,f39,f40,N,f42,f43,f44,f45,f46,f47,B,B,B,B,B,B,B,B,B,B,f58,
f59,f60,f61,f62,f63,f64,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B1,B2,
B3,B4,B5,B6,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,f123,f124,f125,f126};
int main(int argc,char *argv[]){ FILE *be;  for(i=0;i<2400;i++){ st.i[i]=0; }
 if(strcmp(argv[1],"-")==0){
             p=8000; while((c=getc(stdin))!=EOF){st.b[p++]=c;}mx=p; }
 else {      if (!(be=fopen(argv[1],"r"))) {printf("pr?\n"); return 0;}
             p=8000; while((c=fgetc(be))!=EOF){ st.b[p++]=c; } fclose(be); mx=p;} 
 for(i=0;i<argc;i++) if(i>1) st.i[i+95]=atoi(argv[i]);
 p=8000; s=140; r=20; 
 while(p<=mx){ u=st.b[p]; q[u](); if(u<'a')k=0; else if(u>'z')k=0; p++;} return 0;}
