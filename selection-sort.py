
def selection_sort(A):
    for i in range(len(A)): 
        min_idx = i 
        for j in range(i+1, len(A)): 
            if A[min_idx] > A[j]: 
                min_idx = j    
        A[i], A[min_idx] = A[min_idx], A[i] 
    return A

my_list = [5, 3, 11, 9, 21, 18, 20, 4]
print(selection_sort(my_list))
