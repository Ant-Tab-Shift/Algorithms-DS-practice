import math

MIN_ACCEPTABLE_DIFFERENCE: float = 0.0000001


def check_parameter(equation_param: float, equation_result: float) -> bool:
    formula_result: float = equation_param ** 2 + math.sqrt(equation_param + 1)
    return equation_result - formula_result <= MIN_ACCEPTABLE_DIFFERENCE


def binary_answer_search(result_const: float):
    left_border: float = 0.0
    right_border: float = result_const
    while right_border - left_border > MIN_ACCEPTABLE_DIFFERENCE:
        estimated_param: float = (right_border + left_border) / 2

        if check_parameter(estimated_param, result_const):
            right_border = estimated_param
        else:
            left_border = estimated_param
        
    return right_border


def main() -> None:
    result_const: float = float(input())
    print(binary_answer_search(result_const))


if __name__ == "__main__":
    main()
