
def count_tree_dep_and_diam(nodes_tree_parents: list[int], nodes_tree_depth: list[int]) -> int:
    max_depth_node: int = 0
    prev_max_depth_node: int = 0
    current_depth = 0
    for prev_node_idx, node_parent in enumerate(nodes_tree_parents):
        current_depth = nodes_tree_depth[node_parent] + 1
        nodes_tree_depth[prev_node_idx+1] = current_depth
        if current_depth > max_depth_node:
            prev_max_depth_node = max_depth_node
            max_depth_node = current_depth
        elif current_depth > prev_max_depth_node:
            prev_max_depth_node = current_depth
    return max_depth_node + prev_max_depth_node


def print_task_answer(nodes_tree_depth: list[int], diameter: int) -> None:
    print(max(nodes_tree_depth), diameter)
    print(*nodes_tree_depth)
    

def main() -> None:
    tree_size: int = int(input())
    nodes_tree_parents: list[int] = list(map(int, input().split()))
    nodes_tree_depth = [0] * tree_size
    diameter = count_tree_dep_and_diam(nodes_tree_parents, nodes_tree_depth)
    print_task_answer(nodes_tree_depth, diameter)


if __name__ == "__main__":
    main()
