#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<semaphore.h>
#include<sys/resource.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

struct data{

    int *newArray;
    int Starting_Point;
    int Ending_Point;
};

int swap_count = 0;
int swaps = 0;
int searches = 0;
int th;
int* array1;
int target;
int found = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t mutex2;
int a;
int length;
char InfixInput[100];
int operation;
void Make_Array();
void Make_CharArray();
void print_Array(int arr[] , int n);
void Bubble_Sort(int arr[] , int n);
void Insertion_Sort(int arr[], int n);
void Linear_Search(int arr[] , int n, int x);
void Binary_Search(int arr[] ,int low, int high, int x);
void *linearsearch(void *pArray);
void *binarysearch(void *pArray);
void Sort(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
void Operations(int arr[] , int size);
void *bubblesort(void *pArray);
void sort(int *newArray, int Starting_Point, int Ending_Point);
void *mergesort(void *pArray);
void *selectionsort(void *pArray);
void quicksort(int arr[], int low, int high);
void *quickSort(void *pArray);
void Process_Level_Bubble_Sort(int arr[] , int n);
void Thread_Level_Bubble_Sort(int arr[] , int n);
void Process_Level_insertion_Sort(int arr[] , int n);
void Thread_Level_Insertion_Sort(int arr[] , int n);
void Process_Level_Merge_Sort(int arr[] , int n);
void Thread_Level_Merge_Sort(int arr[] , int n);
void Process_Level_Quick_Sort(int arr[] , int n);
void Thread_Level_Quick_Sort(int arr[] , int n);
void Process_Level_Selection_Sort(int arr[] , int n);
void Thread_Level_Selection_Sort(int arr[] , int n);
void Process_Level_Linear_Search(int arr[] , int n);
void Thread_Level_Linear_Search(int arr[] , int n);
void Process_Level_Binary_Search(int arr[], int n);
void Thread_Level_Binary_Search(int n);
void Process_Level_Infix();
void Thread_Level_Infix();
bool isFull(int *t);
bool IsEmpty(int *t);
void Engine();

void main(){
   
        printf("\033[2J");
	printf("\033[1;33m");
	printf("\n\n");
	printf("          -----------------------------------------------------------------------");
	printf("\n\n");
	printf("                            Process-Thread Comparison");
	printf("\n\n");
	printf("          Arsal Jawed             Shahzaib Mirza              Muhammad Murtuza");
	printf("\n\n");
	printf("          ------------------------------------------------------------------------");
	printf("\n\n");
	Engine();
}

void Engine(){
        
        int choice;
        printf("\033[1;36m");
        printf("\nEnter Following Numbers for Your Desired Operation: \n\n");
	printf("     1-Bubble Sort      2-Insertion Sort      3-Selection Sort      4-Merge Sort\n\n");
	printf("     5-Quick Sort       6-Linear Search       7-Binary Search       8-Infix to Postfix\n\n");
	printf("     0-Exit");
	printf("\033[1;32m");
	printf("\n\nEnter: ");
	scanf("%d",&choice);
	
	switch(choice){
		
		case 1: operation = 1;
		        Make_Array();
		return;
		case 2: operation = 2;
		        Make_Array();
		return;
		case 3: operation = 3;
		        Make_Array();
		return;
		case 4: operation = 4;
		        Make_Array();
		return;
		case 5: operation = 5;
		        Make_Array();
		return;
		case 6: operation = 6;
		        Make_Array();
		return;
		case 7: operation = 7;
		        Make_Array();
		return;
		case 8: operation = 8;
		        Make_CharArray();
		return;
		case 0: printf("\033[1;35m"); 
		        printf("\n------------------Fi Amaanillah-----------------------\n\n");
		        sleep(1); 
		        exit(0);
		return;
		default:printf("\033[1;31m"); 
		        printf("\nWrong input!\n");
		        sleep(1);
		        Engine();
		return;
	}
}

void Make_Array(){
	
	int size;
	printf("\nEnter Size of Array: \n");
	scanf("%d",&size);
	
	int arr[size];
	
	Operations(arr,size);
	
	
}
void Make_CharArray(){
   
       int a;
       printf("\nEnter '1' for Process and '2' for Thread: ");
       scanf("%d",&a);
       
       if(a==1){
         
         Process_Level_Infix();
       }else if(a==2){
         Thread_Level_Infix();       
       }else{
           printf("\033[1;31m");
           printf("\nError!, Invalid Input\n");
           sleep(1);
       }
}
void Operations(int arr[] , int size){
	
	int a;
	printf("\nEnter '1' for Process and '2' for Thread: ");
	scanf("%d",&a);
	if(operation==1){
	
	if(a==1){
		
	printf("\nProcess-Level Execution: \n");
	Process_Level_Bubble_Sort(arr,size);
	}else if(a==2){
	printf("\nThread-Level Execution: \n");
	Thread_Level_Bubble_Sort(arr,size);
	}else{
	printf("\033[1;31m");
	printf("\nError!, Invalid Input\n");
	sleep(1);
	Engine();
        }
      }else if(operation==2){
      
        if(a==1){      
        printf("\nProcess-Level Execution: \n");
	Process_Level_insertion_Sort(arr,size);
	}else if(a==2){
	printf("\nThread-Level Execution: \n");
	Thread_Level_Insertion_Sort(arr,size);
	}else{
	printf("\033[1;31m");
	printf("\nError!, Invalid Input\n");
	sleep(1);
        Engine();
      }
    }else if(operation==3){
      
        if(a==1){      
        printf("\nProcess-Level Execution: \n");
	Process_Level_Selection_Sort(arr,size);
	}else if(a==2){
	printf("\nThread-Level Execution: \n");
	Thread_Level_Selection_Sort(arr,size);
	}else{
	printf("\033[1;31m");
	printf("\nError!, Invalid Input\n");
	sleep(1);
        Engine();
      }
    }else if(operation==4){
      
        if(a==1){      
        printf("\nProcess-Level Execution: \n");
	Process_Level_Merge_Sort(arr,size);
	}else if(a==2){
	printf("\nThread-Level Execution: \n");
	Thread_Level_Merge_Sort(arr,size);
	}else{
	printf("\033[1;31m");
	printf("\nError!, Invalid Input\n");
	sleep(1);
        Engine();
      }
    }else if(operation==5){
      
        if(a==1){      
        printf("\nProcess-Level Execution: \n");
	Process_Level_Quick_Sort(arr,size);
	}else if(a==2){
	printf("\nThread-Level Execution: \n");
	Thread_Level_Quick_Sort(arr,size);
	}else{
	printf("\033[1;31m");
	printf("\nError!, Invalid Input\n");
	sleep(1);
        Engine();
      }
    }else if(operation==6){
    
        if(a==1){
        printf("\nProcess-Level Execution: \n");
        Process_Level_Linear_Search(arr,size);
        }else if(a==2){
        printf("\nThread-Level Execution: \n");
        Thread_Level_Linear_Search(arr,size);
        }else{
        printf("\033[1;31m");
        printf("\nError!, Invalid Input\n");
        sleep(1);
        Engine();
      }
    }else if(operation==7){
     
        if(a==1){
        printf("\nProcess-Level Execution: \n");
        Process_Level_Binary_Search(arr,size);
        }else if(a==2){
        printf("\nThread-Level Execution: \n");
        Thread_Level_Binary_Search(size);
        }else{
        printf("\033[1;31m");
        printf("\nError!, Invalid Input\n");
        sleep(1);
        Engine();
      }
    }
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void Combine(int *p, int a, int b){
    int i, j;
    for(i=a; i<b; i++){
       for(j=i; j<b; j++){
	if(p[i]>p[j]){
	int temp=p[i];
	p[i]=p[j];
	p[j]=temp;
	swap_count++;
}
}
}
}
void CombineThreads(int arr[] , int si , int ei) {
		
     if(ei>si) {
			
	int mid = (si+ei)/2;
			
	CombineThreads(arr,si,mid);
	CombineThreads(arr,mid+1,ei);
	Sort(arr,si,mid,ei);
}
}
void print_Array(int arr[] , int n){
	int i;
	for(i=0 ; i<n ; i++){
		
		printf("%d  ",arr[i]);
	}
}
void Bubble_Sort(int arr[] , int n){
    
    int i, j, temp;
     swaps = 0;
    for(i=0; i<n-1; i++){
        for(j=n-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                swaps++;
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
void Insertion_Sort(int arr[], int n){
    
    int i, j, temp;
    swaps = 0;
	for(i=1; i<n; i++){
		temp = arr[i];
		j = i-1;

		while(j>=0 && arr[j]>temp){
			swaps++;
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = temp;
	}
}
void Sort(int arr[], int left, int mid, int right){
	
	int i, j, k;
	int x = mid-left+1;
	int y = right-mid;

	int L[x];
	int R[y];

	for(i=0; i<x; i++){
		L[i] = arr[left+i];
	}
	for(j=0; j<y; j++){
		R[j] = arr[mid+1+j];
	}
	i = j = 0;
	k = left;

	while(i<x && j<y){
		if(L[i] <= R[j]){
		    arr[k] = L[i];
		    i++;
		}else{
		    arr[k] = R[j];
		    j++;
		    swaps += mid - left - i + 1;
		    swap_count++;
		}

		k++;
		
	}

	while(i<x){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<y){
		arr[k] = R[j];
		j++;
		k++;
	}
	
	
}

void MergeSort(int arr[], int left, int right){
	int mid, status;

	int lchild = -1;
	int rchild = -1;

    if(left<right){
        mid = left+(right-left)/2;

        lchild = fork();

        if(lchild<0){
            perror("fork");
            exit(1);
        }
        if(lchild==0){
            MergeSort(arr, left, mid);
            exit(0);
        }else{
            rchild = fork();

            if(rchild<0){
                perror("fork");
                exit(1);
            }if(rchild==0){
                MergeSort(arr, mid+1, right);
                exit(0);
            }
        }

        waitpid(lchild, &status, 0);
        waitpid(rchild, &status, 0);
        Sort(arr, left, mid, right);
        
    }
}
void Selection(int arr[] , int n){
  
  swaps = 0;
  for(int i=0 ; i<n ; i++) {
		
       int key = i;
    for(int j=i+1 ; j<n ; j++) {
				
	if(arr[j]<arr[key]) {
		swaps++;
		key = j;
	}
}
	int temp = arr[i];
	arr[i] = arr[key];
	arr[key] = temp;
}
}
int Partition(int arr[], int left, int right){
	
	int temp;
	int pivot = arr[right];
	int i = left-1;

	for(int j=left; j<=right-1; j++){
		if(arr[j]<=pivot){
			
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			swaps++;
			swap_count++;
		}
	}

	temp = arr[i+1];
	arr[i+1] = arr[right];
	arr[right] = temp;

	return (i+1);
}

void QuickSort(int arr[], int low, int high){
	
	int indexer, status;

	int lchild = -1;
	int rchild = -1;

    if(low<high)
    {
        indexer = Partition(arr, low, high);

        lchild = fork();

        if(lchild<0)
        {
            perror("fork");
            exit(1);
        }
        if(lchild==0)
        {
            QuickSort(arr, low, indexer-1);
            exit(0);
        }
        else
        {
            rchild = fork();

            if(rchild<0)
            {
                perror("fork");
                exit(1);
            }
            if(rchild==0)
            {
                QuickSort(arr, indexer+1, high);
                exit(0);
            }
        }

        waitpid(lchild, &status, 0);
        waitpid(rchild, &status, 0);
    }
}
void Binary_Search(int arr[] , int low, int high, int x){
    int count=0;
    while (low <= high) {
    
       int mid = low + (high - low) / 2;
       searches++;
       if (arr[mid] == x){
       printf("\nvalue found");
       break;}
       if (arr[mid] < x){
       low = mid + 1;}
       else{
       high = mid - 1;}
   }
   if(low > high){
   printf("\nvalue not found");
   }
}
void *binarysearch(void *arg){
    int thread_id = *(int*) arg;
    int low = thread_id * (sizeof(array1) / th);
    int high = (thread_id + 1) * (sizeof(array1) / th) - 1;
    int mid;

    while (low <= high && !found) {
        mid = (low + high) / 2;
        searches++;
        if (array1[mid] == target) {
            pthread_mutex_lock(&mutex);
            found = 1;
            printf("\nTarget found by thread %d at index %d\n", thread_id, mid);
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        } else if (array1[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    pthread_exit(NULL);

}

void Linear_Search(int arr[] , int n, int x){
    int i,count=0;
    searches++;
    for(i=0; i<n; i++){
        if (arr[i] == x){
            printf("\n\nElement %d Found",x);
        }else {count++;
               searches++;      
         }
    }
    if(count==n){
    printf("\n%d not found",x);
    }
}
void *linearsearch(void *pArray){
int i;
struct data var = *(struct data *)pArray;
    int *newArray = var.newArray;
    int Starting_Point = var.Starting_Point;
    int Ending_Point = var.Ending_Point;
    searches++;
    for (i = Starting_Point; i < Ending_Point; i++) {
        if (newArray[i] == a) {
            printf("%d found",a);
            pthread_exit(NULL);
        }
        searches++;
    }
    pthread_exit(NULL);
}
void *insertionsort(void *pArray){
    struct data var = *(struct data *)pArray;
    int *newArray = var.newArray;
    int Starting_Point = var.Starting_Point;
    int Ending_Point = var.Ending_Point;

    int i, key, j;

    for(i=1; i<Ending_Point; i++){
        key = newArray[i];
        j = i-1;

        while(j>=0 && newArray[j]>key){
            newArray[j+1] = newArray[j];
            swap_count++;
            j = j-1;
        }

        newArray[j+1] = key;
    }
    
    Combine(newArray,Starting_Point,Ending_Point);

}
void *selectionsort(void *pArray){
    
    struct data var = *(struct data *)pArray;
    int *newArray = var.newArray;
    int Starting_Point = var.Starting_Point;
    int Ending_Point = var.Ending_Point;
    
    int i,key,j;
    
    for(i=0 ; i<Ending_Point ; i++){
    
    key = i;
    
    for(j=i+1 ; j<Ending_Point ; j++){
       
       if(newArray[j]<newArray[key]){
           swap_count++;
           key = j;
       }
    }
    
       int temp = newArray[i];
       newArray[i] = newArray[key];
       newArray[key] = temp;
    }
    
    Combine(newArray,Starting_Point,Ending_Point);
    
}
void *bubblesort(void *pArray){
    
    struct data var = *(struct data *)pArray;
    int *newArray = var.newArray;
    int Starting_Point = var.Starting_Point;
    int Ending_Point = var.Ending_Point;

    int i, j;
    for(i=Starting_Point; i<Ending_Point-1; i++){
    for(j=0; j<Ending_Point-Starting_Point-1; j++){
       if(newArray[j]>newArray[j+1]){
          swap(&newArray[j], &newArray[j+1]);
          swap_count++;
       }
   }
}

Combine(newArray,Starting_Point,Ending_Point);

}



void sort(int *newArray, int Starting_Point, int Ending_Point){
    
    int mid = (Starting_Point+Ending_Point)/2;

	if(mid>Starting_Point && mid<Ending_Point){
		sort(newArray, Starting_Point, mid);
		sort(newArray, mid+1, Ending_Point);
		Combine(newArray, Starting_Point, Ending_Point);
	}
}

void *mergesort(void *pArray){
    struct data var = *(struct data *)pArray;
    int *newArray = var.newArray;
    int sPoint = var.Starting_Point;
    int ePoint = var.Ending_Point;

    int mid=(sPoint+ePoint)/2;

	if(mid>sPoint && mid <ePoint){
		sort(newArray, sPoint, mid);
		sort(newArray, mid+1, ePoint);
		Combine(newArray, sPoint, ePoint);
	}
}

void quicksort(int arr[], int low, int high){
	
	if(low<high){
		
		int pi = Partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
		Combine(arr, low, high);
	}

}

void *quickSort(void *pArray){
	
	struct data var = *(struct data *)pArray;
        int *newArray = var.newArray;
	int sPoint = var.Starting_Point;
	int ePoint = var.Ending_Point;

    if(sPoint<ePoint){
		
		int pi = Partition(newArray, sPoint, ePoint);
		quicksort(newArray, sPoint, pi - 1);
		quicksort(newArray, pi + 1, ePoint);
	}
}
bool isFull(int *t){
if(*t==100){
return true;
}
return false;
}

bool IsEmpty(int *t){
if(*t==-1){
return true;
}
return false;
}

void Push(char c,char arr[],int *top){

if(isFull(&*top)){
 printf("Stack is full \n");
}else{
*top=*top+1;
arr[*top]=c;
}
}

char Pop(char arr[],int *top){
 if(IsEmpty(&*top)){
 printf("stack is empty");
 }else{
char Temp=arr[*top];
*top=*top-1;
return Temp;
}
}

char peek(int *top,char arr[]){
return arr[*top];
}

void print(char arr[],int top){
for (int i=0;i<=top;i++){
  printf("%c ,",arr[i]);
}
}

int Prec(char c){
  if(c=='+' || c=='-'){
  return 1;
  }
 if(c=='*' || c=='/' || '%'){
  return 2;
  }
   if(c=='^'){
  return 3;
  }
  return 0;
  
}
void toPostfix(char infix[],char arr[],int *top){
int index=0;
int lim=strlen(infix);
char Postfix[lim];

for(int i=0; i<lim;i++){
Postfix[i]='\0';
}
for(int i=0;i<strlen(infix);i++){
char Sym=infix[i];
printf("%c",Sym);
if(isalpha(Sym)){
Postfix[index]=Sym;
index=index+1;
}else if(Sym=='('){
Push(Sym,arr,&*top);
}else if(Sym==')'){
while((peek(&*top,arr))!='('){
Postfix[index++]=Pop(arr, &*top);
}
Pop(arr, &*top);
}else{
while(!IsEmpty(&*top) && !((peek(&*top,arr))=='(') && Prec(Sym)<=Prec((peek(&*top,arr)))){
Postfix[index++]=Pop( arr, &*top);
}
Push(Sym,arr,&*top);
}
}

while(!IsEmpty(&*top)){
Postfix[index++]=Pop( arr, &*top);

}

printf("\n\nThe Postfix: %s",Postfix);
}
void *InfixWriter(){

printf("\nEnter Infix: ");
scanf("%s",InfixInput);
length = strlen(InfixInput);
length += 116;
sem_post(&mutex2);
}
void *PostfixReader(){
sem_wait(&mutex2);
printf("\npostfix conversion and reading done by thread %ld\n",pthread_self());
int top=-1;
char arr[100];
for(int i=0; i<100;i++){
arr[i]='\0';
}

toPostfix(InfixInput,arr,&top);
sem_post(&mutex2);
}
void Process_Level_Bubble_Sort(int arr[] , int n){
    
    int status,v;
    clock_t t;
    int *shm_array;
    int *TS;
    int shm_id , swid;
	key_t key;
	size_t shm_size;
    printf("\033[1;37m");
    printf("\nParent Process Executing.....\n\n");
    sleep(1);
    int i;
    for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }
    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
        
         swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
	t = clock();
	printf("\nUnsorted Array: "); 
	print_Array(shm_array, n);
   
    int pid = fork();
    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
   
    
    Bubble_Sort(shm_array, n);
    *TS = swaps;
      exit(0);
    }
    
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    waitpid(pid, &status, 0);
    printf("\nSorted Array: ");
    print_Array(shm_array, n);
    t = clock() - t;
    
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory Usage: %ld bytes\n",usage+16);
    printf("No fo Swaps: %d\n",*TS);
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Thread_Level_Bubble_Sort(int arr[] , int n){

    int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   printf("\033[1;37m");
   printf("\nUnsorted Array: ");
   print_Array(arr,n);
    clock_t start, end;
    int count = 0;
    
    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}

    pthread_t pid[th];
    
    start = clock();
  
    for(i=0; i<th; i++){

    pthread_create(&pid[i], NULL, bubblesort, (void *)&x[i]);

    }
    for(i=0; i<th; i++){
    pthread_join(pid[i], NULL);
  }
        
        end = clock();
        
        printf("\n\nAFTER SORTING: \n");
        
        int A[n];
        for(int r=0 ; r<n ; r++)
        A[r] = arr[r];
        count = 0;
        for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count++;
        if (count == n / th) {
        count = 0;
        printf("\n");
    }
}   
    
    printf("\n\n");    
    printf("Sorted Array: ");
    CombineThreads(A,0,n-1);
    print_Array(A,n);
    printf("\n");
    
    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTotal CPU Time : %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Swaps: %d\n",swap_count);
    swap_count = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}
    
void Process_Level_insertion_Sort(int arr[] , int n){

    int status,v;
    clock_t t;
    int *shm_array;
    int *TS;
    int shm_id , swid;
    key_t key;
    size_t shm_size;
    printf("\033[1;37m");
    printf("\nParent Process Executing.....\n\n");
    sleep(1);
    int i;
    for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }
    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
	
	swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
     }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}
	
	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
        
	t = clock();
	printf("\n\nUnsorted Array: ");
	print_Array(shm_array, n);

    int a = fork();

    if(a<0){
        perror("fork");
        exit(1);
    }
    if(a==0){
        printf("\n\nChild Process Executing.\n");

        Insertion_Sort(shm_array, n);
         *TS = swaps;
    exit(0);
    }
    
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    waitpid(a, &status, 0);
    printf("\nSorted Array: ");
    print_Array(shm_array, n);
    t = clock() - t;
    
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory Usage: %ld bytes\n",usage+16);
    printf("\nNo fo Swaps: %d\n",*TS);
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
  }
  
void Thread_Level_Insertion_Sort(int arr[] , int n){

    int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   printf("\033[1;37m");
   printf("\nUnsorted Array: ");
   print_Array(arr,n);
    clock_t start, end;
    int count = 0;

    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}

pthread_t pid[th];

start = clock();

        for(i=0; i<th; i++){
            pthread_create(&pid[i], NULL, insertionsort, (void *)&x[i]);
         }

        for(i=0; i<th; i++){
            pthread_join(pid[i], NULL);
         }

        end = clock();
        int A[n];
        for(int i=0 ; i<n ; i++)
        A[i] = arr[i];
printf("\n\nAFTER SORTING: \n");

count = 0;
for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    count++;
    if (count == n / th) {
        count = 0;
        printf("\n");
    }
}

    printf("\n\n");    
    printf("Sorted Array: ");
    CombineThreads(A,0,n-1);
    print_Array(A,n);
    printf("\n");

    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTotal CPU Time : %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Swaps: %d\n",swap_count);
    swap_count = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Process_Level_Merge_Sort(int arr[] , int n){

    int status;
    clock_t t1, t2 , t;
    swaps = 0;
    int *TS;
    int *shm_array;
	int shm_id , swid;
	key_t key;
	size_t shm_size;
    printf("\033[1;37m");
    printf("\nParent Process Executing.....\n\n");
    sleep(1);
    int i; 
     for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }

    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
        
         swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
        
	t = clock();
	printf("\nUnsorted Array: "); 
	print_Array(shm_array, n);

    int pid = fork();

    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
        t1 = clock();
	print_Array(shm_array, n);
	MergeSort(shm_array, 0, n-1);
	*TS = swaps;
	print_Array(shm_array, n);
	
    exit(0);
    }
    
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    waitpid(pid, &status, 0);
    printf("\nSorted Array: ");
    print_Array(shm_array, n);
    t = clock() - t;
    
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\032[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory Usage: %ld bytes\n",usage+16);
    printf("No of Swaps: %d\n",*TS);
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Thread_Level_Merge_Sort(int arr[] , int n){

    int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   printf("\033[1;37m");
   printf("\nUnsorted Array: ");
   print_Array(arr,n);
    clock_t start, end;
    int count = 0;

    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}

pthread_t pid[th];

start = clock();

        for(i=0; i<th; i++){
            pthread_create(&pid[i], NULL, mergesort, (void *)&x[i]);
         }

        for(i=0; i<th; i++){
            pthread_join(pid[i], NULL);
         }

        end = clock();
   int A[n];
   for(int i=0 ; i<n ; i++)
   A[i] = arr[i];
printf("\n\nAFTER SORTING: \n");

count = 0;
for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    count++;
    if (count == n / th) {
        count = 0;
        printf("\n");
    }
}

    printf("\n\n");    
    printf("Sorted Array: ");
    CombineThreads(A,0,n-1);
    print_Array(A,n);
    printf("\n");

    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTotal CPU Time : %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Swaps: %d\n",swap_count);
    swap_count = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Process_Level_Selection_Sort(int arr[] , int n){
  
  int status,v;
    clock_t t1, t2 , t;
    int *TS;
    int *shm_array;
	int shm_id , swid;
	key_t key;
	size_t shm_size;
    printf("\033[1;37m");
    printf("\nParent Process Executing.....\n\n");
    sleep(1);
    int i; 
    for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }

    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
        
        swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
        
	t = clock();
	printf("\nUnsorted Array: "); 
	print_Array(shm_array,n);

    int pid = fork();

    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
        t1 = clock();
	print_Array(shm_array, n);
	Selection(shm_array, n);
	*TS = swaps;
    exit(0);
    }
    
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    waitpid(pid, &status, 0);
    printf("\nSorted Array: ");
    print_Array(shm_array, n);
    t = clock() - t;
    
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory Usage: %ld bytes\n",usage+16);
    printf("No of Swaps: %d\n",*TS);
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Thread_Level_Selection_Sort(int arr[] , int n){
     
    int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   
   printf("\033[1;37m");
   printf("\nUnsorted Array: ");
   print_Array(arr,n);
    clock_t start, end;
    int count = 0;

    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}

   pthread_t pid[th];

   start = clock();
   
   for(i=0; i<th; i++){
       pthread_create(&pid[i], NULL, quickSort, (void *)&x[i]);
   }

      for(i=0; i<th; i++){
      pthread_join(pid[i], NULL);
}

      end = clock();
      int A[n];
      for(int i=0 ; i<n ; i++)
      A[i] = arr[i];
      printf("\n\nAFTER SORTING: \n");

     count = 0;
     for (i = 0; i < n; i++) {
     printf("%d ", arr[i]);
     count++;
     if (count == n / th) {
        count = 0;
        printf("\n");
    }
}
    
    printf("\n\n");    
    printf("Sorted Array: ");
    CombineThreads(A,0,n-1);
    print_Array(A,n);
    printf("\n");
    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTotal CPU Time: %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Swaps: %d\n",swap_count);
    swap_count = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}

void Process_Level_Quick_Sort(int arr[] , int n){

   int status,v;
    clock_t t1, t2 , t;
    swaps = 0;
    int *shm_array;
    int shm_id , swid;
    int *TS;
    key_t key;
    size_t shm_size;
    
    printf("\033[1;37m");
    printf("\nParent Process Executing.....\n\n");
    sleep(1);
    int i; 
    for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }

    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
        
        swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
	
        printf("\nUnsorted Array: ");
        print_Array(arr,n);
	t = clock();
	printf("\nUnsorted Array: "); 
	print_Array(shm_array,n);

    int pid = fork();

    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
        t1 = clock();
	print_Array(shm_array, n);
	QuickSort(shm_array,0,n-1);
	*TS = swaps;
	exit(0);
	}
	waitpid(pid, &status, 0);
	printf("\nSorted Array: ");
	print_Array(shm_array, n);
	t2 = clock();

    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
   printf("\n\nTotal CPU Time: %f milisecs\n", time);
   printf("Memory Usage: %ld bytes\n",usage+16);
   printf("No of Swaps: %d\n",*TS);
   printf("\033[1;33m");
   printf("\nPress Enter To Continue.........");
   getchar();
   getchar();
   Engine();
}
void Thread_Level_Quick_Sort(int arr[] , int n){

    int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   
   printf("\033[1;37m");
    clock_t start, end;
    int count = 0;

    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}

pthread_t pid[th];

start = clock();

        for(i=0; i<th; i++){
            pthread_create(&pid[i], NULL, selectionsort, (void *)&x[i]);
         }

        for(i=0; i<th; i++){
            pthread_join(pid[i], NULL);
         }

        end = clock();
        int A[n];
        for(int i=0 ; i<n ; i++)
        A[i] = arr[i];
printf("\n\nAFTER SORTING: \n");

count = 0;
for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    count++;
    if (count == n / th) {
        count = 0;
        printf("\n");
    }
}
    printf("\n\n");    
    printf("Sorted Array: ");
    CombineThreads(A,0,n-1);
    print_Array(A,n);
    printf("\n");
    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTotal CPU Time: %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Swaps: %d\n",swap_count);
    swap_count = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}
void Process_Level_Binary_Search(int arr[] , int n){
int status,v;
    clock_t t;

    int *shm_array;
    int *TS; 
    int shm_id , swid;
    key_t key;
    size_t shm_size;

    printf("\nParent Process Executing.....\n\n");
    printf("Select Values Provider: \n\n");
    printf("\nEnter '1' for User and '2' for System: \n");
    scanf("%d",&v);
    int i,val,ans; 
    if(v==1){
		
	for(i=0 ; i<n ; i++){
			
	printf("Enter Value for index %d: \n",i);
	scanf("%d",&arr[i]);
		}
	}else if(v==2){
		
		for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }
	}else{
		printf("\033[1;31m");
		printf("Error! Invalid Input");
		Engine();
	}
	printf("\n\nEnter Value To Find: ");
	scanf("%d",&val);

    key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
        swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
    if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }
	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}

	t = clock();
	printf("\033[1;37m");
	print_Array(shm_array, n);

    int pid = fork();
    
    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
        Binary_Search(shm_array, 0, n-1, val);
        printf("\n");
        *TS = searches;
        exit(0);
    }

    waitpid(pid, &status, 0);
    t = clock() - t;
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
    
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory usage: %ld\n",usage+16);
    printf("No of Searching Checks: %d\n",*TS);
    searches = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}
void Thread_Level_Binary_Search(int n){
    
    array1 = malloc(n * sizeof(int));
    printf("\n\nEnter Number of Threads: ");
    scanf("%d",&th);
    if(th>=n || th<=0){
    printf("\033[1;31m");
    printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
    return;
   }

    for (int i = 0; i < n; i++) {
        array1[i] = i * 2;
    }

    printf("\n\nEnter the target value: ");
    scanf("%d", &target);
    pthread_t threads[th];
    int thread_ids[th];
    clock_t start, end;
    printf("\033[1;37m");
    start = clock();
    for (int i = 0; i < th; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, binarysearch, &thread_ids[i]);
    }
    for (int i = 0; i < th; i++) {
        pthread_join(threads[i], NULL);
    }
    
    end = clock();

    if (!found) {
        printf("\nTarget not found\n");
    }
    size_t size = sizeof(struct data);
    int usage = (int)size;
    int arrsize = n*4;
    usage += arrsize;
    printf("\033[1;32m");
    double time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f\n", time);
    printf("Memory Usage: %d bytes\n",usage+16);
    printf("No of Searching Checks: %d\n",searches);
    searches = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}
void Process_Level_Linear_Search(int arr[] , int n){
int status,v;
    clock_t t;

    int *shm_array;
    int *TS;
    int shm_id , swid;
    key_t key;
    size_t shm_size;

    printf("\nParent Process Executing.....\n\n");
    printf("Select Values Provider: \n\n");
    printf("\nEnter '1' for User and '2' for System: \n");
    scanf("%d",&v);
    int i,val; 
    if(v==1){
		
	for(i=0 ; i<n ; i++){
			
	printf("Enter Value for index %d: \n",i);
	scanf("%d",&arr[i]);
		}
	}else if(v==2){
		
		for(i=0 ; i<n ; i++){
        
		arr[i] = rand()%100;
        }
	}else{
		printf("\033[1;31m");
		printf("Error! Invalid Input");
		Engine();
	}
	printf("\n\nEnter Value To Find: ");
	scanf("%d",&val);

        key = IPC_PRIVATE;

	shm_size = n * sizeof(int);
	swid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        if (swid == -1) {
        perror("shmget");
        exit(1);
    }
        TS = (int *) shmat(swid, NULL, 0);
        if (TS == (int *) -1) {
        perror("shmat");
        exit(1);
    }

	if((shm_id = shmget(key, shm_size, IPC_CREAT | 0666)) == -1){
		perror("shmget");
		exit(1);
	}

	if((shm_array = shmat(shm_id, NULL, 0)) == (int *) -1){
		perror("shmat");
		exit(1);
	}

	for(int i=0; i<n; i++){
		shm_array[i] = arr[i];
	}
        printf("\033[1;37m");
	t = clock(); 
	print_Array(shm_array, n);

    int pid = fork();

    if(pid<0){
        perror("fork");
        exit(1);
    }
    if(pid==0){
        printf("\n\nChild Process Executing......\n");
        Linear_Search(shm_array, n, val);
        printf("\n");
        *TS = searches-1;
        exit(0);
    }

    waitpid(pid, &status, 0);
    t = clock() - t;
    struct shmid_ds buf;
    if(shmctl(shm_id, IPC_STAT, &buf) == -1){
    perror("shmctl");
    exit(1);
    }
 
    long usage = buf.shm_segsz;
    printf("\033[1;32m");
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal CPU Time: %f milisecs\n", time);
    printf("Memory Usage: %ld\n",usage+16);
    printf("No of Searching Checks: %d\n",*TS);
    searches = 0;
    printf("\033[1;33m");
    printf("\nPress Enter To Continue.........");
    getchar();
    getchar();
    Engine();
}
void Thread_Level_Linear_Search(int arr[] , int n){
   
   int i,th;
    
   for(i=0 ; i<n ; i++){
        
	arr[i] = rand()%100;
   }
	
   printf("\n\nEnter Number of Threads: ");
   scanf("%d",&th);
   if(th>=n || th<=0){
   printf("\033[1;31m");
   printf("Error!,No of Threads should be lesser than Size of Array and greater than '0'");
   return;
   }
   printf("\033[1;37m");
    clock_t start, end;
    int count = 0;

    struct data x[th];
    int Starting_Point = 0;
    int Ending_Point = n / th;

    for (i = 0; i < th; i++) {
    x[i].newArray = arr;
    x[i].Starting_Point = Starting_Point;
    x[i].Ending_Point = Ending_Point;
    Starting_Point += n / th;
    Ending_Point += n / th;
}
    printf("\n\nEnter Value To Find: ");
    scanf("%d",&a);
    pthread_t pid[th];

    start = clock();

        for(i=0; i<th; i++){
            pthread_create(&pid[i], NULL, linearsearch, (void *)&x[i]);
         }

        for(i=0; i<th; i++){
            pthread_join(pid[i], NULL);
         }

        end = clock();
        
        count = 0;
for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    count++;
    if (count == n / th) {
        count = 0;
    }
}
int arrsize = (n*4)+4;
printf("\033[1;32m");
double time = ((double)end - start) / CLOCKS_PER_SEC;
printf("\n\nTotal CPU Time: %f\n", time);
printf("Memory Usage: %d\n",arrsize+16);
printf("No of Searching Checks: %d\n",searches);
searches = 0;
printf("\033[1;33m");
printf("\nPress Enter To Continue.........");
getchar();
getchar();
Engine();
}

void Process_Level_Infix(){
   
   printf("\033[1;37m");
   clock_t start,end;
   printf("\nEnter Infix: ");
   scanf("%s",InfixInput);
   printf("postfix conversion and reading done by process \n");
   int size = strlen(InfixInput);
   size += 116;
   int top=-1;
   char arr[100];
   for(int i=0; i<100;i++){
   arr[i]='\0';
}
start=clock();
toPostfix(InfixInput,arr,&top);
end=clock();

printf("\033[1;32m");
double time = ((double)end - start) / CLOCKS_PER_SEC;
printf("\n\nTotal CPU Time: %f milieseconds", time);
printf("\nMemory Usage: %d\n",size);
printf("\033[1;33m");
printf("\nPress Enter To Continue.........");
getchar();
getchar();
Engine();
}

void Thread_Level_Infix(){

printf("\033[1;37m");
clock_t start,end;
pthread_t td[2];
sem_init(&mutex2,0,0);
start=clock();
pthread_create(&td[0],NULL,InfixWriter,NULL);
pthread_create(&td[1],NULL,PostfixReader,NULL);
pthread_join(td[0],NULL);
end=clock();
pthread_join(td[1],NULL);
sem_destroy(&mutex2);
printf("\033[1;32m");
double time = ((double)end - start) / CLOCKS_PER_SEC;
printf("\n\nTotal CPU Time: %f milieseconds\n", time);
printf("Memory Usage: %d\n",length);
printf("\033[1;33m");
printf("\nPress Enter To Continue.........");
getchar();
getchar();
Engine();
}
