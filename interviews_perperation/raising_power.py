def rainingPower(arr):
    mod = 10**9 + 7
    mx_value = -1 * float('inf')
    mx_index = -1
    for i in range(len(arr)):
        if arr[i] > mx_value:
            mx_value = arr[i]
            mx_index = i
    return pow(mx_value, mx_index, mod)
