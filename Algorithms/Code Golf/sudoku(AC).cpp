#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int hi[9][10],hj[9][10],hb[3][3][10],m[9][9],mc;bool suc;void dfs(){int i,j,k;if(suc){return;}if(mc==0){suc=true;return;}for(i=0;i<9;++i){for(j=0;j<9;++j){if(m[i][j]){continue;}for(k=1;k<=9;++k){if(hi[i][k]||hj[j][k]||hb[i/3][j/3][k]){continue;}else{hi[i][k]=1;hj[j][k]=1;hb[i/3][j/3][k]=1;m[i][j]=k;--mc;dfs();if(!suc){++mc;m[i][j]=0;hi[i][k]=0;hj[j][k]=0;hb[i/3][j/3][k]=0;}else{return;}}}if(k>9){return;}}}}int main(){int i,j,k;int t,ti;scanf("%d",&t);for(ti=0;ti<t;++ti){memset(m,0,9*9*sizeof(int));for(i=0;i<9;++i){for(j=0;j<9;++j){scanf("%d",&m[i][j]);}}memset(hi,0,9*10*sizeof(int));memset(hj,0,9*10*sizeof(int));memset(hb,0,3*3*10*sizeof(int));mc=0;for(i=0;i<9;++i){for(j=0;j<9;++j){if(m[i][j]){hi[i][m[i][j]]=1;hj[j][m[i][j]]=1;hb[i/3][j/3][m[i][j]]=1;}else{++mc;}}}if(mc==0){suc=true;for(i=0;i<9;++i){for(j=0;j<9;++j){printf("%d",m[i][j]);}printf("\n");}continue;}suc=false;for(i=0;i<9;++i){for(j=0;j<9;++j){if(m[i][j]){continue;}for(k=1;k<=9;++k){if(hi[i][k]||hj[j][k]||hb[i/3][j/3][k]){continue;}else{hi[i][k]=1;hj[j][k]=1;hb[i/3][j/3][k]=1;m[i][j]=k;--mc;dfs();if(!suc){++mc;m[i][j]=0;hi[i][k]=0;hj[j][k]=0;hb[i/3][j/3][k]=0;}}if(suc){break;}}if(suc){break;}}if(suc){break;}}for(i=0;i<9;++i){printf("%d",m[i][0]);for(j=1;j<9;++j){printf(" %d",m[i][j]);}printf("\n");}}return 0;}