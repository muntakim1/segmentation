#include<bits/stdc++.h>
using namespace std;

string int_to_string(long n)
{
    stringstream a;
    a<<n;
    return a.str();
}

void sementationSec(long virtual_memory,long base[4],long bound[4],long segment[4]);
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long  bs[4],bnd[4],sgmt[4];
    

    long vm;
    sementationSec(vm, bs,bnd,sgmt);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
void sementationSec(long virtual_memory,long base[],long bound[],long segment[]){
    string access[4];

    for(long i=0; i<4; i++)
    {
        cin>>base[i]>>bound[i]>>access[i];
        segment[i]=base[i]+bound[i];
    }
    while(cin>>virtual_memory&&virtual_memory>-1)
    {
        string s=int_to_string(virtual_memory);
        long digit=s.size();

        if(digit==3)
        {
            long temp=virtual_memory+base[0];
            if(temp>=base[0]&&temp<=segment[0])
            {
                if(access[0]=="RW")
                    cout<<temp<<" "<<"Access granted...You can Raed and Write :D"<<endl;
                else if(access[0]=="R")
                    cout<<temp<<" "<<"Access granted...Read only :|"<<endl;
                else if(access[0]=="W")
                    cout<<temp<<" "<<"Access granted...Write only :p"<<endl;
                else
                    cout<<temp<<" "<<"Access not granted...sorry :("<<endl;
            }
            else
            cout<<"Ops! Wrong memory address"<<endl;
        }
        else if(digit==4)
        {
            long digits = (long)log10(virtual_memory);
            long firstDigit = (long)(virtual_memory/pow(10,digits));

            virtual_memory=virtual_memory-(firstDigit*1000);

            long temp=virtual_memory+base[firstDigit];
            if(temp>=base[firstDigit]&&temp<=segment[firstDigit])
            {
                if(access[firstDigit]=="RW")
                    cout<<temp<<" "<<"Access granted...You can Raed and Write :D"<<endl;
                else if(access[firstDigit]=="R")
                    cout<<temp<<" "<<"Access granted...Read only :|"<<endl;
                else if(access[firstDigit]=="W")
                    cout<<temp<<" "<<"Access granted...Write only :p"<<endl;
                else
                    cout<<temp<<" "<<"Access not granted...sorry :("<<endl;
            }
            else
            cout<<"Ops! Wrong memory address"<<endl;
        }
        else
            cout<<"Ops! Wrong memory address"<<endl;

    }
}
