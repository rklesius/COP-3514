//This program simulates a computer at a grocery store, where each product
//has a name, unit price, number of pounds sold, and a sale volume stored in
//an array of structures.  The program reads the data from sales.txt.  The 
//sales volume is calculated for each item and sorted by sale volume in a file
//called sorted_products.txt.  It is assumed that there are no more than 1000
//products in the file.  
//By Rachel Klesius

#include <stdio.h>
#define MAX 1000

struct product {
	char name[MAX];
	double price;
	double pounds;
	double sales;
};

void selection_sort(struct product products[], int n);

int main(void)
{	struct product products[MAX];
	int i = 0;
	int items = 0; //keeps track of how many items in the array
	FILE* pFile = fopen("sale.txt", "r");
	FILE* qFile = fopen("sorted_products.txt", "w");

	if ((pFile == NULL) || (qFile == NULL)){	
		printf("Cannot open file\n");
		return 1;
		}
	//read in the file contents into the array of struct
	while(!feof(pFile)&&!ferror(pFile)){
		fscanf(pFile, "%s %lf %lf", products[i].name, &products[i].price, 
				&products[i].pounds);
		items++;
		i++;
		}
	//calculate total sales for product
	for(i = 0; i < items; i++)
		products[i].sales = products[i].price * products[i].pounds;
	
	//sort based on sales 
	selection_sort(products, items);
	
	//print to file
	fprintf(qFile, "#name\tunit price($)\tunits (pounds) sold\tsale volume($)\n");
	for(i = 1; i < items; i++)
		fprintf(qFile, "%s\t%lf\t%lf\t%lf\n", products[i].name, products[i].price,
				products[i].pounds, products[i].sales);
	fclose(pFile);
	fclose(qFile);
	return 0;
}


//sorts items of struct product by the value "sale" in the product struct.  
//Alters the struct array products[] and recieves n, the number of items in the
//array.  
void selection_sort(struct product products[], int n)
{	int i, largest = 0;
	struct product temp;
	
	if (n == 1)
		return;
	
	for (i = 1; i < n; i++)
		if (products[i].sales > products[largest].sales)
			largest = i;
	
	if (largest < n - 1) {
		temp = products[n-1];
		products[n-1] = products[largest];
		products[largest] = temp;
		}
	selection_sort(products, n - 1);
}




