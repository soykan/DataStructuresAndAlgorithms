def bubble_sort(arr): 
    n = len(arr) 
    for i in range(n): 
        for j in range(0, n-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
    return arr


my_list = [5, 3, 11, 9, 21, 18, 20, 4]

print(bubble_sort(my_list))