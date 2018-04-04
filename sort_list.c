#include <stdio.h>

void print_client_snr(int *client_snr, unsigned short num_clients)
{
        if (client_snr == NULL || num_clients <= 0) {
                return;
        }
        printf("SWTPC: client_snr list:");
        int i; 
        for (i = 0; i < num_clients; i++) {
                printf(" %d,", client_snr[i]);
        }
        printf("\n");
}

void swap(int *list, int i, int j)
{
        if (list == NULL)
                return;
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
}
void quick_sort(int *list, int init, int end)
{       
	printf("SWTPC: quick sort %d - %d\n", init, end);
        if (list == NULL)
                return;
	if (init >= end)
		return;
        int i = init;
        int j = end;
        int ref = list[init];
        while(i <= j) {
                while (list[i] < ref)
                        i++;
                while (list[j] > ref)
                        j--;
		if(i <= j) {
			swap(list, i,j);
			i++;
			j--;
		}
        }
        if (init < j)
                quick_sort(list, init, j);
        if (i < end)
                quick_sort(list, i, end);
}
//sort client_snr (quick sort, small to large) 
void sort_client_snr(int *client_snr, unsigned short num_clients)
{
        quick_sort(client_snr, 0, num_clients - 1);
}

main()
{
	int client_snr[]  = {51, 67, 51, 66, 50};
	//int client_snr[]  = {1, 1, 1, 1, 1};
	unsigned short l = 5;
	print_client_snr(client_snr, l);
	sort_client_snr(client_snr, l);
	print_client_snr(client_snr, l);
	
}
