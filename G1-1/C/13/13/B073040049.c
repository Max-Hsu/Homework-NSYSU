void mysort(int array_file[],int num_of_file)
{
    for(int i=0; i<num_of_file-1; i++)
    {
        for(int j=0; j<num_of_file-i-1; j++)
        {
            if(array_file[j]>array_file[j+1])
            {
                int temp;
                temp=array_file[j];
                array_file[j]=array_file[j+1];
                array_file[j+1]=temp;
            }
        }
    }

}
int myBinarySearch(int array_file[],int target,int head,int tail)
{
    int searcha=(head+tail)/2;
    if(array_file[searcha]==target)
    {
        return searcha;
    }
    else if(searcha==head)
    {
        if(array_file[searcha+1]==target){
            return searcha+1;
        }
        else{
        return -1;
        }
    }
    if(array_file[searcha]>target)
    {
        myBinarySearch(array_file,target,head,searcha-1);
    }
    else if(array_file[searcha]<target)
    {
        myBinarySearch(array_file,target,searcha+1,tail);
    }

}
