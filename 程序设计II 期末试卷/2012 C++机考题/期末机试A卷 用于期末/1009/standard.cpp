bool check(int arr[][1000],int row, int target)
{
    int x=0,y=999;
    while(1) {
        if(x==row||y<0) return false;
        if(arr[x][y]==target) return true;
        if(arr[x][y]<target) x++;
        else if(arr[x][y]>target) y--;
    }
}
