def main():
    array_size, requests_cnt = map(int, input().split())
    sorted_array = list(map(int, input().split()))
    requests = list(map(int, input().split()))

    for request in requests:
        if binary_search(request, sorted_array, array_size):
            print("YES")
        else:
            print("NO")


def binary_search(request, sorted_array, array_size):
    left_border = 0
    right_border = array_size - 1
    while left_border <= right_border:
        middle = (left_border + right_border) // 2
        if request == sorted_array[middle]:
            return True
        elif request > sorted_array[middle]:
            left_border = middle + 1
        else:
            right_border = middle - 1   
    return False 


if __name__ == "__main__":
    main()
