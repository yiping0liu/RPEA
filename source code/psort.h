void psort(int len);

void psort(int len)
{
	int i,j;

	float temp;

	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(asort[j]<asort[j+1])
			{
				temp=asort[j];
				asort[j]=asort[j+1];
				asort[j+1]=temp;
			}
		}//j
	}//i

}//end psrot