
int partitioncityname (int low, int high) 
{ 
    struct ground pivot,temp,temp2;
	pivot=groundDB[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high- 1; j++) 
    { 
        if (strcmp(groundDB[j].city,pivot.city)<0) 
        { 
			i++;
			temp2=groundDB[i];	
			groundDB[i]=groundDB[j];
			groundDB[j]=temp2
		
        }
	else if(strcmp(groundDB[j].city,pivot.city)==0)
	{
		if (strcmp(groundDB[j].name,pivot.name)<=0)
		{
			i++;    // increment index of smaller element 
            		//swap(&arr[i], &arr[j]);
			temp2=groundDB[i];	
			groundDB[i]=groundDB[j];
			groundDB[j]=temp2;
		} 
	}
    } 
    //swap(&arr[i + 1], &arr[high]);
	temp=groundDB[i+1];
	groundDB[i+1]=groundDB[high];
	groundDB[high]=temp; 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void sortcityname(int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partitioncityname(low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(low, pi - 1); 
        quickSort(pi + 1, high); 
    } 
} 
