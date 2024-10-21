//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends




class Solution {
    // Function to return a list of integers denoting spiral traversal of matrix.
    public ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        // code here
        ArrayList<Integer> result=new ArrayList<>();
        
        if (matrix == null || matrix.length == 0) {
            return result;
        }
        
        int row=matrix.length;
        
        int col=matrix[0].length;
        
        
        int top=0;
        int bottom=row-1;
        
        int i;
        
        int left=0;
        int right=col-1;
        
        
        
        while(top<=bottom && left<=right){
            
            for(i=left;i<=right;i++){
                result.add(matrix[top][i]);
            }
            top++;
            
            for(i=top;i<=bottom;i++){
                result.add(matrix[i][right]);
            }
            right--;
            
            if(top<=bottom){
                for(i=right;i>=left;i--){
                    result.add(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(i=bottom;i>=top;i--){
                    result.add(matrix[i][left]);
                }
                left++;
            }
        }
        return result;

    }
}
