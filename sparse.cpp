#include<iostream>
using namespace std;

#define max 50

class sparse{
	int sp[max][3];
	int len;
public:
	sparse(int r,int c,int l)
	{
		sp[0][0]= r;
		sp[0][1]= c;
		sp[0][2]= l;
		len = 0;	
	}
	void insert(int row,int col,int val);
	void display();
	void transpose(sparse &s1);
};

void sparse::insert(int row, int col, int val) {
	if(row >= sp[0][0] || col >= sp[0][1]) {
		cout << "Invalid input" << endl;
	} else {
		sp[len+1][0] = row;
		sp[len+1][1] = col;
		sp[len+1][2] = val;
		len++;
	}
}

void sparse::display() {
	cout << "row\tcol\tvalue\n";
	for(int i = 0; i <= len; i++) {
		cout << sp[i][0] << "\t" << sp[i][1] << "\t" << sp[i][2] << endl;
	}
}

void sparse::transpose(sparse &s1) {
	int i, j, k = 1;
	sp[0][0] = s1.sp[0][1]; 
	sp[0][1] = s1.sp[0][0];
	sp[0][2] = s1.sp[0][2];
	for(i = 0; i < s1.sp[0][1]; i++) {
		for(j = 1; j <= s1.len; j++) {
			if(s1.sp[j][1] == i) {
				sp[k][0] = s1.sp[j][1];
				sp[k][1] = s1.sp[j][0];
				sp[k][2] = s1.sp[j][2];
				k++;
			}
		}
	}
	len = k - 1;
}
void sparse::add(s1,s2)
{
    if (s1.sp[0][0]!=s2.sp[0][0]&&s1.sp[0][1]!=s2.sp[0][1])
{
    cout<<"ERROR";
return 0;
}
while (i<=s1.sp[0][2]&&j<=s2.sp[0][2])
{
 if(s1.sp[i][0]==s2.sp[j][0])
 {
    if(s1.sp[i][1]==s2.sp[j][1])
    {
        sp[k][0]=s1.sp[i][0];
        sp[k][1]=s1.sp[j][0];
        sp[k][2]=s1.sp[i][2]+s2.sp[j][1];
        i++;
        j++;
        k++;
    }
    else if(s1.sp[i][1]<s2.sp[j][1])
    {
        sp[k][0]=s1.sp[i][0];
        sp[k][1]=s1.sp[i][1];
        sp[k][2]=s1.sp[i][2];
        j++;
        k++;
    }
 }
}

}
int main() {
	int row, col, val;
	int r, c, l;
	cout << "Enter the number of rows, columns, and non-zero values: ";
	cin >> r >> c >> l;
	
	sparse s1(r, c, l);
	sparse s2(c, r, l);  
	
	for(int i = 0; i < l; i++) {
		cout << "\nEnter row, column, and value of non-zero element: ";
		cin >> row >> col >> val;
		s1.insert(row, col, val);
	}
	
	cout << "\nOriginal Sparse Matrix:" << endl;
	s1.display();
	
	s2.transpose(s1);
	
	cout << "\nTransposed Sparse Matrix:" << endl;
	s2.display();
	
	return 0;
}
