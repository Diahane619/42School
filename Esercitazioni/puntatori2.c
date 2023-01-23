void bubblesort(int v[], int n) 
{
	int temp;

for(int i = 0; i < n - 1; i++) 
{
 for(int k = 0; k < n - 1 - i; k++) 
 {
         if(v[k] > v[k + 1]) 
		 {
          	temp = v[k];
          	v[k] = v[k + 1];
          	v[k + 1] = temp;
         }
 }
}
}