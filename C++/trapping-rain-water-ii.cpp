
vector<vector<int> > Visited;
int HowMuchCanHold(vector<vector<int> > &M,int i,int j)
{
    Visited[i][j]=1;
    if(i==0 || j==0 || i==M.size()-1 || j==M[0].size()-1) // we are in borders
        return -1; // drops to earth
    int up=M[i-1][j],down=M[i+1][j],left=M[i][j-1],right=M[i][j+1];
    int minall=1<<10;
    if(!Visited[i-1][j])
        minall=min(minall,up);
    if(!Visited[i+1][j])
        minall=min(minall,down);
    if(!Visited[i][j-1])
        minall=min(minall,left);
    if(!Visited[i][j+1])
        minall=min(minall,right);
    
    int mij=M[i][j];
    if(minall>mij)
        return minall-mij;
    else
        if(minall<mij)
            return -1; // can't hold the drop
    
    int minup=1<<10,mindown=1<<10,minleft=1<<10,minright=1<<10;
    if(mij==up && Visited[i-1][j]==0) // drop may flow up
        minup=HowMuchCanHold(M,i-1,j);
    else
        if(mij!=up)
            minup=up-mij;
    if(mij==down && Visited[i+1][j]==0) // drop may flow down
        mindown=HowMuchCanHold(M,i+1,j);
    else
        if(mij!=down)
            mindown=down-mij;
    if(mij==left && Visited[i][j-1]==0) // drop may flow left
        minleft=HowMuchCanHold(M,i,j-1);
    else
        if(mij!=left)
            minleft=left-mij;
    if(mij==right && Visited[i][j+1]==0) // drop may flow right
        minright=HowMuchCanHold(M,i,j+1);
    else
        if(mij!=right)
            minright=right-mij;
    if(minup<0 || mindown<0 || minleft<0 || minright <0) // drop wil fall from up,down,left or right!
        return -1; // can't hold the drop
    int min1=min(minup,mindown);
    int min2=min(minleft,minright);
    minall=min(min1,min2);
    return minall;
}
int DropTo(vector<vector<int> > &M,int i,int j)
{
    Visited=vector<vector<int> >(M.size(), vector<int>(M[0].size(),0));
    return HowMuchCanHold(M,i,j);
}
int get_watr_trap(vector<vector<int> > M)
{
    int row=M.size();
    int col=M[0].size();
    int total=0;
    int nexthold=0;
    bool find=false;
    while(1)
    {
        find=false;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                nexthold=DropTo(M,i,j);
                if(nexthold>0)
                {
                    find=true;
                    M[i][j]+=nexthold;//fill current cell up to the maxhold
                    total+=nexthold;
                }
            }
        }
        if(!find)
            break;
    }
    return total;
}