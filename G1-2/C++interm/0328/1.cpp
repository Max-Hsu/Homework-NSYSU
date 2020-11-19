#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int size[10]= {0};
    int size_i[10]= {0};
    int num_into=0;
    int input;
    int status=1;
    int times=0;
    cin>>input;
    num_into=log10(input);
	for(int i=num_into; i>=0; i-=1)
        {
            size[i]=input/pow(10,i);
            input-=size[i]*pow(10,i);
        }
    while(status)
    {

        for(int i=0; i<=num_into; i++)
        {
            size_i[num_into-i]=size[i];
        }
        /*
		for(int i=0; i<=num_into; i++)
        {
            cout<<size_i[i]<<" "<<size[i]<<endl;
        }
		*/
        for(int i=0; i<=num_into; i++)
        {
            size[i]+=size_i[i];
            if(size[i]>=10)
            {
                //cout<<i<<" "<<size[i]<<endl;
                //cout<<i+1<<" "<<size[i+1]<<endl;
                size[i+1]+=size[i]/10;
                size[i]%=10;
                //cout<<i<<" "<<size[i]<<endl;
                //cout<<i+1<<" "<<size[i+1]<<endl;
                if(i==num_into)
                {
                    num_into++;
                }
            }
        }

        for(int i=0; i<=(num_into+1/2); i++)
        {
            if(size[i]!=size[num_into-i])
            {
                status=1;
                break;
            }
            else
            {
                status=0;
            }
        }
        times++;
    }

    cout<<times<<"  ";
    for(int i=0; i<=num_into; i++)
    {
        cout<<size[i];
    }
	cout<<endl;
    return 0;
}
