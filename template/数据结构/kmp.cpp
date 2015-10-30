//kmp�Ż���
//����������
void findnext(char *p,int *next)
{
    int i=0,k=-1;
    int len=strlen(p);
    next[0]=-1;
    while(i<len)
    {
        while(k>=0&&p[k]!=p[i])
            k=next[k];
        i++;
        k++;
        if(i==len) break;
        //���Ż������ע���еĴ���
        if(p[i]==p[k])
            next[i]=next[k];
        else
            next[i]=k;
        //next[i]=k;
    }
}

//����ģʽ��p��ԭ��t�е����������ص�
int kmp(char *p,char *t,int *next)
{
    findnext(p,next);
    int i=0,j=0,cnt=0;
    int plen=strlen(p),tlen=strlen(t);
    if(tlen<plen) return cnt;
    while(j<tlen)
    {
        while(i!=-1&&p[i]!=t[j])
            i=next[i];
        i++;j++;
        if(i>=plen)
        {
            cnt++;
            i=0;
        }
    }
    return cnt;
}
