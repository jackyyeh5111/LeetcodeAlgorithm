import random
import math
import matplotlib.pyplot as plt

""" 
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Node:
    def __init__(self, point, parent=None):
        self.point = point
        self.parent = parent
"""
@dataclass
class Point:
    x: float
    y: float

@dataclass
class Node:
    point: Point
    parent: 'Node' = None
    
def distance(p1, p2):
    return math.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

def random_point(width, height):
    return Point(random.uniform(0, width), random.uniform(0, height))

def nearest_node(tree, point):
    nearest = tree[0]
    min_dist = distance(nearest.point, point)
    for node in tree:
        dist = distance(node.point, point)
        if dist < min_dist:
            nearest = node
            min_dist = dist
    return nearest

def steer(from_point, to_point, max_step):
    dist = distance(from_point, to_point)
    if dist <= max_step:
        return to_point
    theta = math.atan2(to_point.y - from_point.y, to_point.x - from_point.x)
    new_x = from_point.x + max_step * math.cos(theta)
    new_y = from_point.y + max_step * math.sin(theta)
    return Point(new_x, new_y)

def is_collision_free(start, end):
    # Simplified to always return True; implement collision checks for obstacles.
    return True

def extract_path(goal_node):
    path = []
    current = goal_node
    while current is not None:
        path.append(current.point)
        current = current.parent
    path.reverse()
    return path

def rrt(start, goal, width, height, max_step, max_iterations):
    tree = [Node(start)]

    for _ in range(max_iterations):
        rand_point = random_point(width, height)
        nearest = nearest_node(tree, rand_point)
        new_point = steer(nearest.point, rand_point, max_step)

        if is_collision_free(nearest.point, new_point):
            new_node = Node(new_point, nearest)
            tree.append(new_node)

            if distance(new_point, goal) <= max_step and is_collision_free(new_point, goal):
                goal_node = Node(goal, new_node)
                return extract_path(goal_node)

    return None

def plot_path(path, start, goal, width, height):
    plt.figure(figsize=(8, 8))
    plt.xlim(0, width)
    plt.ylim(0, height)

    # Draw the path
    if path:
        x_coords = [point.x for point in path]
        y_coords = [point.y for point in path]
        plt.plot(x_coords, y_coords, '-o', label="Path")

    # Draw start and goal
    plt.scatter([start.x], [start.y], color='green', label="Start")
    plt.scatter([goal.x], [goal.y], color='red', label="Goal")

    plt.legend()
    plt.show()

def main():
    width = 10
    height = 10
    start = Point(0, 0)
    goal = Point(9, 9)
    max_step = 1.0
    max_iterations = 1000

    path = rrt(start, goal, width, height, max_step, max_iterations)

    if path:
        print("Path found:")
        for point in path:
            print(f"({point.x:.2f}, {point.y:.2f})")
    else:
        print("No path found.")

    plot_path(path, start, goal, width, height)

if __name__ == "__main__":
    main()
