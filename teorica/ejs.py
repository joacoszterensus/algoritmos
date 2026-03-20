# final 2023

#10
# sha256


def longitud_lis(arr):
    n = len(arr)
    if n == 0:
        return 0
    
    LIS = [1] * n
    print(LIS)
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and LIS[i] < LIS[j] + 1:
                LIS[i] = LIS[j] + 1
    print(LIS)
    return max(LIS)

vector = [20,4,5,31,24]
longitud_maxima = longitud_lis(vector)
print("La longitud de la subsecuencia creciente de máxima longitud es:", longitud_maxima)
