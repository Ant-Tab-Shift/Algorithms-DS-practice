def main():
    array_size, requests_cnt = map(int, input().split())
    sorted_array = list(map(int, input().split()))
    requests = list(map(int, input().split()))

    for request in requests:
        print(almost_binary_search(request, sorted_array, array_size))


def almost_binary_search(request, sorted_array, array_size):
    left_border = 0
    right_border = array_size - 1
    while left_border < right_border - 1:
        middle = (left_border + right_border) // 2
        if request == sorted_array[middle]:
            return sorted_array[middle]
        elif request > sorted_array[middle]:
            left_border = middle
        else:
            right_border = middle

    left_diff = abs(sorted_array[left_border] - request)
    right_diff = abs(sorted_array[right_border] - request)
    return sorted_array[right_border] if right_diff < left_diff else sorted_array[left_border]


if __name__ == "__main__":
    main()
