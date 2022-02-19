#include <stdio.h>
int str_length(char *str){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;

}
bool find_substr(char *a,char *b){
    int n1=str_length(a);
    int n2=str_length(b);
    bool found=false;
    if(n1>n2){
        for(int i=0;i<n1-n2+1;i++){
            if(a[i]==b[0]){
                found=true;
                for(int j=0;j<n2;j++){
                    if(a[i+j]!=b[j]){
                        found=false;
                        break;
                    }
                }
                if(found){
                    return true;
                }
            }
        }
    }else{
        for(int i=0;i<n2-n1+1;i++){
            if(b[i]==a[0]){
                found=true;
                for(int j=0;j<n1;j++){
                    if(b[i+j]!=a[j]){
                        found=false;
                        break;
                    }
                }
                if(found){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    char a[]="abcdefghijklmnopqrstuvwxyz";
    char b[]="abce";
    printf("%d\n",find_substr(a,b));
}