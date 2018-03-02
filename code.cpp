#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{

    ll t,i,m;
    cin>>t;
    while(t--)
    {
        char s[1000010];
        cin>>s;
        ll l=strlen(s);
        ll k=l/2;
        ll flag=1,check=0;
        //cout<<"k is"<<k<<endl;
        for(i=0;i<l;i++)
        {
            if(s[i]!='9')   //if string contains all digits 9
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            s[0]='1';
            for(i=1;i<l;i++)
            s[i]='0';
            s[l]='1';
            s[l+1]='\0';
            check=1;
        }
        flag=0;
        if(check!=1)
        {
            for(i=0;i<k;i++)
            {
                if(s[i]<s[l-1-i])
                flag=-1;
                else if(s[i]>s[l-1-i])
                flag=1;
                s[l-1-i]=s[i];
            }
            //cout<<"string is "<<endl;
            //cout<<s<<endl;

            if(l%2==0)  //if string length is even
            m=k-1;
            else m=k;
            //cout<<m<<endl;
            if(flag==0||flag==-1)
            {
                i=0;
                while(s[m-i]=='9')
                {
                    s[m-i]='0';
                    //cout<<s[m-i]<<" ";
                    s[l-1-m+i]='0';
                    //cout<<s[l-1-m+i]<<" ";
                    i++;
                }

                s[m-i]++;
                s[l-1-m+i]=s[m-i];
            }
    }
    cout<<s<<endl;
    }
    return 0;
}

/*test cases 
5               output
4                 5
191              202
999              1001
1001             1111
1234             1331
