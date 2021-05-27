#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
void display(struct Array A1)
{
    for(int i=0;i<A1.length;i++)
    {
        cout<<A1.A[i]<<endl;
    }
}
void append(struct Array *A1,int x)
{
    A1->A[A1->length]=x;
    A1->length++;
}
void insert(struct Array *A1,int element,int index)
{
    for(int i=A1->length;i>index;i--)
    {
        A1->A[i]=A1->A[i-1];
    }
    A1->A[index]=element;
    A1->length++;
}
void del(struct Array *arr , int id)
{
    int a=arr->A[id];
    for(int i=id;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;
}
int lin(struct Array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct Array arr,int key)
{
    int low,mid,high;
    low=0;
    high=arr.length-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(arr.A[mid]>key)
        {
            high=mid-1;
        }
        else if (arr.A[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            return mid;
        }
        mid=(low+high)/2;
    }
    return -1;
}
int get(struct Array arr,int id)
{
    if((id>=0)&&(id<arr.length))
    {
        return arr.A[id];
    }
}
void set(struct Array *arr,int id,int element)
{
    if((id>=0)&&(id<arr->length))
    {
        arr->A[id]=element;
    }
}
int sum(struct Array arr,int len)
{
    if(len==-1)
    {
        return 0;
    }
    return sum(arr,len-1)+arr.A[len];
}
int avg(struct Array arr)
{
    return sum(arr,arr.length-1)/arr.length;
}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(max<arr.A[i]){ max=arr.A[i];}
    }
    return max;
}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(min>arr.A[i]){ min=arr.A[i];}
    }
    return min;
}
void reverse(struct Array *arr)
{
    int temp;
    int c=(arr->length-1)/2;
    for(int i=0;i<=c;i++)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[arr->length-1-i];
        arr->A[arr->length-1-i]=temp;
    }
}
int main()
{
    struct Array Q={{1,2,33,773,94,6,12,8,10,50},20,10};
    //cout<<Q.A[3]<<" "<<Q.length<<" "<<Q.size<<endl;
    display(Q);
    cout<<endl;
    //append(&Q,100);
    //insert(&Q,100,5);
    //display(Q);
    //cout<<endl;
    //del(&Q,4);
    //display(Q);
    //cout<<endl;
    //cout<<lin(Q,10);
    cout<<" "<<Q.length<<endl;
    //cout<<"hello"<<endl;
    //cout<<BinarySearch(Q,10);
    /*cout<<get(Q,3)<<endl;
    set(&Q,5,-5);
    display(Q);
    cout<<endl;
    cout<<sum(Q,Q.length-1)<<endl;
    cout<<avg(Q)<<endl;
    cout<<min(Q)<<endl;
    cout<<max(Q)<<endl;*/
    reverse(&Q);
    display(Q);
}





