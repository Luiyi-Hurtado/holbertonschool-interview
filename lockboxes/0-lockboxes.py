#!/usr/bin/python3
"""
Fucntion that determiantes if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Return True if the boxes is opened or
    False if the boxes is not opened

    Args:
        boxes (list):
            a list with the boxes

    Return:
        Boolean :
            a boolean that indicate if the boxes
            is opened or not
    """
    n = len(boxes)
    visited = [False] * n
    visited[0] = True
    stack = [0]

    while stack:
        box = stack.pop()
        for key in boxes[box]:
            if key >= 0 and key < n and not visited[key]:
                visited[key] = True
                stack.append(key)

    return all(visited)
