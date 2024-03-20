import sys
import math


def ask_computer(request: int) -> None:
    print(request)
    sys.stdout.flush()


def print_right_answer(answer: int) -> None:
    print("!", answer)
    sys.stdout.flush()


def get_attempt_result() -> bool:
    computer_answer: str = input()

    if computer_answer == "<":
        return False
    elif computer_answer == ">=":
        return True
    else:
        raise ValueError("You are stupid dump buster")


def guess_number(left_border: int, right_border: int) -> int:
    while left_border < right_border:
        suggested_number: int = math.ceil((right_border + left_border) / 2)
        ask_computer(suggested_number)

        if get_attempt_result():
            left_border = suggested_number 
        else:
            right_border = suggested_number - 1

    return left_border


def main() -> None:
    min_number: int = 1
    max_number: int = int(input())
    result: int = guess_number(min_number, max_number)
    print_right_answer(result)


if __name__ == "__main__":
    main()
