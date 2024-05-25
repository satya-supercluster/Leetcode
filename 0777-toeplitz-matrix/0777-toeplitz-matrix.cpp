
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
    int i=m,j=0,s=m,t=0;
        ///// traversing lower left side diagonals
// i.e. matrix[2][0]
//matrix[1][0]
//matrix[2][1]
//matrix[0][0]
//matrix[1][1]
//matrix[2][2]

    while(s>=0)
    {
        i=s;
        j=0;
        while(i<m-1&&j<n-1)
        {
            if(matrix[i][j]!=matrix[i+1][j+1])
                return false;
            i++;
            j++;
        }
        s--;
    }  

            ///// traversing upper right side diagonals
// i.e. matrix[0][1]
//matrix[1][2]
//matrix[2][3]
//matrix[0][2]
//matrix[1][3]
//matrix[0][3]
        i=0,j=1;
         while(t<n)
    {
        i=0;
        j=t;
        while(i<m-1&&j<n-1)
        {
            if(matrix[i][j]!=matrix[i+1][j+1])
                return false;
            i++;
            j++;
        }
        t++;
    }  
        return true;
    }
};