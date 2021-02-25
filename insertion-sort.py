def insertion_sort(my_list):
    for i in range(0, len(my_list)):
        current_value = my_list[i]
        k = i - 1
        while k>= 0 and current_value <= my_list[k]:
            my_list[k+1] = my_list[k]
            k -= 1
        my_list[k+1] = current_value
    return my_list

listem = [5, 3, 11, 9, 21, 18, 20, 4]

print(insertion_sort(listem))
