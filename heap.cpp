#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y);
class heap{

	int *arr;
	int capacity;
	int heap_size;
	
		
	
	public:
		int parent(int i){
			return (i-1)/2;
			
		}
		int left(int i){
			return (2*i + 1);
			
		}
		
		int right(int i){
			return (2*i + 2);
		}
		
		
		heap(int n){
			heap_size = 0;
			capacity = n;
			arr = new int[n];
		}
		
		void insert(int k){
	
			if(heap_size == capacity){
				cout<<"overflow";
				return;
			}
			heap_size++;
			int i = heap_size-1;
			arr[i] = k;
			
			while(i != 0 && arr[parent(i)] > arr[i]){
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
			}
		
			
			
		} 
		void decrease(int i, int data){
		
			arr[i] = data;
			while(i != 0 && arr[parent(i)] > arr[i]){
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
			
			
			}
		}
		
		void increase(int i, int data){
		
			arr[i] = data;
			while(i != 0 && arr[parent(i)] < arr[i]){
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
			
			}
		}		
		
		
		
		void minheapify(int i){ 
			int r = right(i);
			int l = left(i);
			int smallest = i;
			
			if(l < heap_size && arr[l] < arr[i])
			smallest = l;
			if(r < heap_size && arr[r] < arr[smallest])
			smallest = r;
			
			if(smallest != i){
			swap(&arr[i], &arr[smallest]);
			minheapify(smallest);
			
			
			}
			
		}
		void maxheapify(int i){
			int r = right(i);
			int l = left(i);
			int largest = i;
			
			if(l < heap_size && arr[l] > arr[i])
			largest = l;
			if(r < heap_size && arr[r] > arr[largest])
			largest = r;
			
			if(largest != i){
				swap(&arr[i], &arr[largest]);
				maxheapify(largest);
			}
			
		}	
			
		

		int extact_min(){
			if(heap_size <= 0)
			return INT_MAX;
			
			if(heap_size == 1){
			heap_size--;
			return arr[0];
			}
			int root = arr[0];
			arr[0] = arr[heap_size-1];
			//arr[heap_size-1] = temp;
			heap_size--;
			minheapify(0);
			return root;
			
		}
		
		int extract_max(){
			if(heap_size <= 0)
				return INT_MIN;
			if(heap_size == 1){
				heap_size--;
				return arr[0];
			}	
			int temp  = arr[0];
			arr[0] = arr[heap_size-1];
			heap_size--;
			maxheapify(0);
			return temp;
				
			
		}	
			
};
	void swap(int *x, int *y){
			int temp = *x;
			*x = *y;
			*y = temp;
			
		}
		
		
int main(){
	
	heap h(5);
	h.insert(50);
	h.insert(12);
	h.insert(14);
	h.insert(13);
	h.insert(15);
	//h.decrease(3, 1);
	//h.increase(1, 61);
	cout<<h.extract_max()<<endl;
	cout<<h.extact_min()<<endl;
	//cout<<h.getmin()<<endl;
	
	return 0;
}
